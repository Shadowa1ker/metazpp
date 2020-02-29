//
//  MZTimedTextItem.m
//  MetaZ
//
//  Created by Brian Olsen on 09/10/09.
//  Copyright 2009 Maven-Group. All rights reserved.
//
#include <array>
#include <algorithm>
#include <sstream>
//#include <wx\string.h>

#include "MZTimedTextItem.hpp"
#include "MZStringUtils.hpp"
//#import <MetaZKit/MZLogger.h>

// This might be intended to be static, is before implementation declaration


//@implementation MZTimedTextItem
// + means static (class)
// - means instance (object)
std::vector<MZTimedTextItem> MZTimedTextItem::parseChapters(const std::string& str, MZTimeCode& duration) //+ (NSArray *)parseChapters:(NSString *)str duration:(MZTimeCode *)duration
{
  std::string trimmedStr = str;
  trim(trimmedStr);
  //  str = [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
  if (trimmedStr[0] == 'C')//    if([str characterAtIndex:0] == 'C') // Ogg format
  {
    return MZTimedTextItem::parseOggChapters(str, duration);//        return [self parseOggChapters:str duration:duration];
  }
  else if (trimmedStr.compare(0, 2, "1.", 2) == 0)//    else if([[str substringToIndex:2] isEqual:@"1."]) // Web format
  {
    return MZTimedTextItem::parseWebChapters(str, duration);//    else if([[str substringToIndex:2] isEqual:@"1."]) // Web format
  }
  else//    else
  {
    return MZTimedTextItem::parseMP4Chapters(str, duration); // return[self parseMP4Chapters : str duration : duration];
  }
}

std::vector<MZTimedTextItem> MZTimedTextItem::parseOggChapters(const std::string& str, MZTimeCode& duration) //+ (NSArray *)parseOggChapters:(NSString *)str duration:(MZTimeCode *)duration
{
  bool parsingTimestamp = true;// BOOL parsingTimestamp = YES;
  std::vector<MZTimedTextItem> timestamps;//    NSMutableArray* ret = [NSMutableArray array];
  MZTimeCode timestamp;//  MZTimeCode* timestamp = nil;
  std::string txt; //  NSString* txt = nil;
  MZTimeCode nextTimestamp;//    MZTimeCode* nextTimestamp = nil;

  std::stringstream strSs(str);
  std::string line;
  while (std::getline(strSs, line, '\n'))
  {
 //   NSArray* lines = [str componentsSeparatedByString:@"\n"];
 //   for(NSString* line in lines)
 //   {
    trim(line);//     line = [line stringByTrimmingCharactersInSet : [NSCharacterSet whitespaceCharacterSet] ];
    if (line.length() == 0) //if([line length] == 0)
    {
      continue;
    }
    size_t equalSignIdx = line.find_first_of('=');
    if (equalSignIdx == std::string::npos)
    {
      return timestamps;
    }
    std::string newTxt = line.substr(equalSignIdx + 1, std::string::npos);

//        NSScanner* sc = [NSScanner scannerWithString:line];
//        [sc setCharactersToBeSkipped:nil];
        
//        if(![sc scanUpToString:@"=" intoString:nil])
//            return nil;
//        if(![sc scanString:@"=" intoString:nil])
//            return nil;

//        NSString* newTxt = [line substringFromIndex:[sc scanLocation]];
        
    if(parsingTimestamp)
    {
      MZTimeCode nextTimestamp(newTxt); //nextTimestamp = [MZTimeCode timeCodeWithString:newTxt];
        //if(!nextTimestamp)
        //    return nil;
    }
    else
    {
      if(!txt.empty())//  if(txt)
      {
        MZTimeCode curDuration(nextTimestamp.get_millis() - timestamp.get_millis());//   MZTimeCode* curDuration = [MZTimeCode timeCodeWithMillis : [nextTimestamp millis] - [timestamp millis]];
        MZTimedTextItem curTimedText(timestamp, curDuration, txt);
        timestamps.emplace_back(curTimedText);// [ret addObject : [MZTimedTextItem textItemWithStart : timestamp duration : curDuration text : txt] ] ;
      }
      txt = newTxt;
      timestamp = nextTimestamp;
    }
    parsingTimestamp = !parsingTimestamp;
  }
  if (!parsingTimestamp)
  {
    std::vector<MZTimedTextItem> empty; //return nil;
    return empty;
  }
  if(!txt.empty() && timestamp.isSet())
  {
    if (duration.isSet())//        if(duration)
    {
      duration -= timestamp;//            duration = [MZTimeCode timeCodeWithMillis:[duration millis]-[timestamp millis]];
    }
    MZTimedTextItem newItem(timestamp, duration, txt);
    timestamps.emplace_back(newItem);//        [ret addObject:[MZTimedTextItem textItemWithStart:timestamp duration:duration text:txt]];
   }
  return timestamps;
//    if([ret count] == 0)
//        return nil;
//    return ret;
}

std::vector<MZTimedTextItem> MZTimedTextItem::parseMP4Chapters(const std::string& str, MZTimeCode& duration)// + (NSArray *)parseMP4Chapters:(NSString *)str duration:(MZTimeCode *)duration
{
  MZTimeCode timestamp;//  MZTimeCode* timestamp = nil;
/*
    NSString* txt = nil;
*/
  std::vector<MZTimedTextItem> timestamps;//    NSMutableArray* ret = [NSMutableArray array];
/*

    NSArray* lines = [str componentsSeparatedByString:@"\n"];
    for(NSString* line in lines)
    {
        line = [line stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
        if([line length] == 0)
            continue;
        
        NSScanner* sc = [NSScanner scannerWithString:line];
        [sc setCharactersToBeSkipped:nil];
        
        NSString* timestampText;
        if(![sc scanUpToCharactersFromSet:[NSCharacterSet whitespaceCharacterSet] intoString:&timestampText])
            return nil;
        
        MZTimeCode* nextTimestamp = [MZTimeCode timeCodeWithString:timestampText];
        if(!nextTimestamp)
            return nil;
        
        if(![sc scanCharactersFromSet:[NSCharacterSet whitespaceCharacterSet] intoString:nil])
            return nil;
            
        NSString* newTxt = [line substringFromIndex:[sc scanLocation]];
        if(txt)
        {
            MZTimeCode* curDuration = [MZTimeCode timeCodeWithMillis:[nextTimestamp millis]-[timestamp millis]];
            [ret addObject:[MZTimedTextItem textItemWithStart:timestamp duration:curDuration text:txt]];
        }
        timestamp = nextTimestamp;
        txt = newTxt;
    }
    
    if(txt && timestamp)
    {
        if(duration)
            duration = [MZTimeCode timeCodeWithMillis:[duration millis]-[timestamp millis]];
        [ret addObject:[MZTimedTextItem textItemWithStart:timestamp duration:duration text:txt]];
    }
    if([ret count] == 0)
        return nil;
*/
  return timestamps; // return ret;

}

std::vector<MZTimedTextItem> MZTimedTextItem::parseWebChapters(const std::string& str, MZTimeCode& duration)// + (NSArray *)parseWebChapters:(NSString *)str duration:(MZTimeCode *)duration
{
/*
    NSUInteger start = 0;
*/
    std::vector<MZTimedTextItem> timestamps;//    NSMutableArray* ret = [NSMutableArray array];
/*
    NSMutableArray* ret = [NSMutableArray array];
    BOOL chapterNames = NO;

    NSArray* lines = [str componentsSeparatedByString:@"\n"];
    for(NSString* line in lines)
    {
        line = [line stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
        if([line length] == 0)
            continue;
        
        NSScanner* sc = [NSScanner scannerWithString:line];
        [sc setCharactersToBeSkipped:nil];
        
        if(![sc scanCharactersFromSet:[NSCharacterSet decimalDigitCharacterSet] intoString:nil])
            return nil;
        if(![sc scanString:@"." intoString:nil])
            return nil;
        if(![sc scanCharactersFromSet:[NSCharacterSet whitespaceCharacterSet] intoString:nil])
            return nil;
        
        NSString* text;
        [sc scanUpToString:@"[" intoString:&text];
            
        if([sc isAtEnd] || chapterNames)
        {
            chapterNames = YES;
            [ret addObject:text];
            continue;
        }
        
        [sc scanString:@"[" intoString:nil];

        int minutes = 0;
        [sc scanInt:&minutes];
        if(![sc scanString:@":" intoString:nil])
        {
            chapterNames = YES;
            [ret addObject:text];
            continue;
        }

        int seconds;
        if(![sc scanInt:&seconds])
        {
            chapterNames = YES;
            [ret addObject:text];
            continue;
        }
        
        if(![sc scanString:@"]" intoString:nil])
        {
            chapterNames = YES;
            [ret addObject:text];
            continue;
        }
        
        NSUInteger millis = (minutes*60+seconds)*1000;
        
        [ret addObject:[MZTimedTextItem
            textItemWithStart:[MZTimeCode timeCodeWithMillis:start]
                     duration:[MZTimeCode timeCodeWithMillis:millis]
                         text:text]];
        start += millis;
    }
    if(chapterNames)
    {
        int count = [ret count];
        for(int i=0; i<count; i++)
        {
            id value = [ret objectAtIndex:i];
            if([value isKindOfClass:[MZTimedTextItem class]])
                [ret replaceObjectAtIndex:i withObject:[value text]];
        }
    }
    else if(duration && start != [duration millis])
    {
        MZLoggerError(@"Chapters don't match the expected duration %@ actual %@",
            duration, [MZTimeCode timeCodeWithMillis:start]);
    }
*/
  return timestamps;//  return ret;
}
/*
+ (id)textItemWithStart:(MZTimeCode *)start duration:(MZTimeCode *)duration text:(NSString *)text
{
    return [[[self alloc] initWithStart:start duration:duration text:text] autorelease];
}
*/
MZTimedTextItem::MZTimedTextItem(const MZTimeCode& start, const MZTimeCode& duration, const std::string& text) // -(id)initWithStart:(MZTimeCode*)aStart duration : (MZTimeCode*)aDuration text : (NSString*)aText
  : start(start), duration(duration)
{
  this->text = deduplicateWhitespaceToSpace(text);
//    self = [super init];
//    if(self)
//    {
//        start = [aStart copy];
//        duration = [aDuration copy];
//        text = [fixText(aText) retain];
//    }
//    return self;
}
/*
- (void)dealloc
{
    [start release];
    [duration release];
    [text release];
    [super dealloc];
}

@synthesize start;
@synthesize duration;
@synthesize text;

- (NSString *)description
{
    return [NSString
        stringWithFormat:@"%@ %@",
            [start description],
            text];
}

#pragma mark - NSCoding implementation
- (id)initWithCoder:(NSCoder *)decoder
{
    self = [super init];
    if(self)
    {
        start = [[decoder decodeObjectForKey:@"start"] retain];
        duration = [[decoder decodeObjectForKey:@"duration"] retain];
        text = [[decoder decodeObjectForKey:@"text"] retain];
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder
{
    [encoder encodeObject:start forKey:@"start"];
    [encoder encodeObject:duration forKey:@"duration"];
    [encoder encodeObject:text forKey:@"text"];
}

#pragma mark - NSCopying implementation
- (id)copyWithZone:(NSZone *)zone
{
    return [[MZTimedTextItem allocWithZone:zone]
        initWithStart:start
             duration:duration
                 text:text];
}

#pragma mark - NSMutableCopying implementation
- (id)mutableCopyWithZone:(NSZone *)zone
{
    return [[MZMutableTimedTextItem allocWithZone:zone]
        initWithStart:start
             duration:duration
                 text:text];
}

@end


@implementation MZMutableTimedTextItem
@dynamic text;

- (void)setText:(NSString *)aText
{
    NSString* newText = fixText(aText);
    [text release];
    text = [newText retain];
}

@end
*/
