//
//  MZTimeCode.m
//  MetaZ
//
//  Created by Brian Olsen on 09/10/09.
//  Copyright 2009 Maven-Group. All rights reserved.
//
#include <array>
#include <cstddef>
#include <exception>
#include <vector>

#include "MZTimeCode.hpp" //#import "MZTimeCode.h"
//#import <AEVTBuilder.h> // https://forums.wxwidgets.org/viewtopic.php?t=7838

//@implementation MZTimeCode
//@synthesize millis;

//+ (id)timeCodeWithString:(NSString *)str
//{
//    return [[[self alloc] initWithString:str] autorelease];
//}

//+ (id)timeCodeWithMillis:(NSUInteger)millis
//{
//    return [[[self alloc] initWithMillis:millis] autorelease];
//}

// http://www.cplusplus.com/faq/sequences/strings/split/#string-find_first_of

struct splitStr
{
  enum empties_t { empties_ok, no_empties };
};

template <typename Container>
Container& split(
  Container& result,
  const typename Container::value_type& s,
  const typename Container::value_type& delimiters,
  splitStr::empties_t empties = splitStr::empties_ok)
{
//  result.clear();
  size_t current;
  size_t next = -1;
  do
  {
    if (empties == splitStr::no_empties)
    {
      next = s.find_first_not_of(delimiters, next + 1);
      if (next == Container::value_type::npos) break;
      next -= 1;
    }
    current = next + 1;
    next = s.find_first_of(delimiters, current);
    result.push_back(s.substr(current, next - current));
  } while (next != Container::value_type::npos);
  return result;
}

MZTimeCode::MZTimeCode()
  : hour(0), min(0), sec(0), ms(0), millis(0), set(false)
{
}

MZTimeCode::MZTimeCode(const std::string& str) //- (id)initWithString:(NSString *)str
  : hour(0), min(0), sec(0), ms(0), millis(0)
{
  std::vector <std::string> timeElements; // Array is more efficient but we can't check to see we got four elements?
  split(timeElements, str, ";.:", splitStr::no_empties);
//    NSScanner* scanner = [NSScanner scannerWithString:str]; // https://developer.apple.com/documentation/foundation/nsscanner
//  unsigned int theMillis = 0;// NSUInteger theMillis = 0;
  if (timeElements.size() < 4)
  {
    throw std::invalid_argument("Invalid time code.");// fail
  }
//    NSInteger value;
    //Hours[;.:]Minutes[;.:]Seconds[;.:]Milliseconds[;.:]
    // If we don't have an integer value in str fail, or is this the first characters?
//    if(![scanner scanInteger:&value])
//    {
//        [self release];
//        return nil;
//    }
  
  this->millis += std::stoul(timeElements[0]) * 3600000; // theMillis += value*3600000; // Hours
    // string separate set - ';' '.' ':'
//    NSCharacterSet* sepSet = [NSCharacterSet characterSetWithCharactersInString:@";.:"];
    // Scan 
//    if(![scanner scanCharactersFromSet:sepSet intoString:NULL])
//    {
//        [self release];
//        return nil;
//    }

//    if(![scanner scanInteger:&value])
//    {
//        [self release];
//        return nil;
//    }
  this->millis = +std::stoul(timeElements[1]) * 60000; // theMillis += value * 60000; // Minutes

//    if(![scanner scanCharactersFromSet:sepSet intoString:NULL])
//    {
//        [self release];
//        return nil;
//    }

//    if(![scanner scanInteger:&value])
//    {
//        [self release];
//        return nil;
//    }
  this->millis += std::stoul(timeElements[2]) * 1000;//    theMillis += value * 1000; // Seconds
    
//    if(![scanner scanCharactersFromSet:sepSet intoString:NULL])
//    {
//        [self release];
//        return nil;
//    }

//    if(![scanner scanInteger:&value])
//    {
//        [self release];
//        return nil;
//    }
  this->millis += std::stoul(timeElements[3]);//  theMillis += value; // milliseconds
  this->set = true;
//    return [self initWithMillis:theMillis];
}

MZTimeCode::MZTimeCode(const unsigned int& millis)//- (id)initWithMillis:(NSUInteger)theMillis
  : hour(0), min(0), sec(0), ms(0), millis(millis), set(true)
{
//    self = [super init];
//    if(self)
//        millis = theMillis;
//    return self;
}

bool MZTimeCode::isSet() const
{
  return this->set;
}

unsigned int MZTimeCode::get_millis() const
{
  return this->millis;
}

unsigned int MZTimeCode::get_ms() const //- (NSUInteger)ms
{
    return this->millis % 1000;
}

unsigned int MZTimeCode::get_sec() const //- (NSUInteger)sec
{
    return (this->millis / 1000) % 60;
}

unsigned int MZTimeCode::get_min() const //- (NSUInteger)min
{
    return (this->millis / 60000) % 60;
}

unsigned int MZTimeCode::get_hour() const //- (NSUInteger)hour
{
    return this->millis / 3600000;
}

MZTimeCode& MZTimeCode::operator+= (const MZTimeCode& rhs)
{
  this->millis += rhs.get_millis();
  return *this;
}

MZTimeCode& MZTimeCode::operator+ (const MZTimeCode& rhs)
{
  this->millis += rhs.get_millis();
  return *this;
}

MZTimeCode operator+ (MZTimeCode lhs, const MZTimeCode& rhs)
{
  lhs.millis = lhs.millis + rhs.get_millis();
  return lhs;
}

MZTimeCode& MZTimeCode::operator-= (const MZTimeCode& rhs)
{
  this->millis -= rhs.get_millis();
  return *this;
}

MZTimeCode& MZTimeCode::operator- (const MZTimeCode& rhs)
{
  this->millis -= rhs.get_millis();
  return *this;
}

MZTimeCode operator- (MZTimeCode lhs, const MZTimeCode& rhs)
{
  lhs.millis = lhs.millis - rhs.get_millis();
  return lhs;
}

/*
- (MZTimeCode *)addTimeCode:(MZTimeCode *)timeCode
{
    return [MZTimeCode timeCodeWithMillis:millis + [timeCode millis]];
}

- (NSString *)description
{
    return [self stringValue];
}

- (NSString *)stringValue
{
    return [NSString stringWithFormat:@"%02lu:%02lu:%02lu.%03lu",
        [self hour], [self min], [self sec], [self ms]];
}

- (BOOL)isEqual:(id)object
{
    if(![object isKindOfClass:[MZTimeCode class]])
        return NO;
    MZTimeCode* other = object;
    return millis == other->millis;
}
*/
MZComparison MZTimeCode::_compare(const MZTimeCode& v1, const MZTimeCode& v2) //- (NSComparisonResult)compare:(MZTimeCode *)aTimeCode
{
    if(v1.millis < v2.millis)
        return MZComparison::MZLessThan;
    if(v1.millis > v2.millis)
        return MZComparison::MZGreaterThan;
    return MZComparison::MZEqual;
}
/*
#pragma mark - Scripting additions

+ (void) initialize {
	[super initialize];
	static BOOL tooLate = NO;
	if( ! tooLate ) {
		[[NSScriptCoercionHandler sharedCoercionHandler] registerCoercer:[self class] selector:@selector( coerceTimeCode:toString: ) toConvertFromClass:[MZTimeCode class] toClass:[NSString class]];
		tooLate = YES;
	}
}

+ (id) coerceTimeCode:(MZTimeCode *) value toString:(Class) class
{
	return [value stringValue];
}

- (NSAppleEventDescriptor *)scriptingRecordDescriptor
{
    return [RECORD : 'Mtim',
        [KEY : 'MTmi'], [INT : self.millis],
        [KEY : 'MTms'], [INT : self.ms],
        [KEY : 'MTse'], [INT : self.sec],
        [KEY : 'MTmt'], [INT : self.min],
        [KEY : 'MThr'], [INT : self.hour],
        [KEY : 'MTxt'], [STRING : [self stringValue]],
    nil];
}

- (NSAppleEventDescriptor *)scriptingAnyDescriptor
{
    return [self scriptingRecordDescriptor];
}

#pragma mark - NSCoding implementation
- (id)initWithCoder:(NSCoder *)decoder
{
    self = [super init];
    if(self)
    {
        millis = [decoder decodeIntegerForKey:@"millis"];
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder
{
    [encoder encodeInteger:millis forKey:@"millis"];
}

#pragma mark - NSCopying implementation
- (id)copyWithZone:(NSZone *)zone
{
    return [[[self class] allocWithZone:zone] initWithMillis:millis];
}

@end
*/