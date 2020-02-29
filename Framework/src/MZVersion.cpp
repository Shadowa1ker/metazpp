//
//  MZVersion.m
//  MetaZ
//
//  Created by Brian Olsen on 24/11/13.
//
//
#include <sstream>
//#include <wx/platinfo.h>

#include "MZConstants.hpp"
#include "MZVersion.hpp" //#import "MZVersion.h"

//@implementation MZVersion

/*+ (id)systemVersion; {
    NSOperatingSystemVersion version = [[NSProcessInfo processInfo] operatingSystemVersion];
    return [self versionWithMajor:version.majorVersion
                            minor:version.minorVersion
                           bugFix:version.patchVersion];
}*/

/*+ (id)versionWithMajor:(NSUInteger)major minor:(NSUInteger)minor bugFix:(NSUInteger)bugFix;
{
    return [[[self alloc] initWithMajor:major minor:minor bugFix:bugFix] autorelease];
}*/

const std::string MZVersion::systemVersion()//+ (id)versionWithString:(NSString *)systemVersion; {
{
  std::ostringstream systemVersion;
//  systemVersion << wxPlatformInfo::Get().GetOSMajorVersion() << "." << wxPlatformInfo::Get().GetOSMinorVersion();
  return systemVersion.str();
//    return [[[self alloc] initWithString:systemVersion] autorelease];
}


MZVersion::MZVersion(const unsigned int& major, const unsigned int& minor, const unsigned int& bugFix)//- (id)initWithMajor:(NSUInteger)aMajor minor:(NSUInteger)aMinor bugFix:(NSUInteger)aBugFix; {
  : major(major), minor(minor), bugFix(bugFix)
{
 //   self = [super init];
 //   if(self) {
 //       major = aMajor;
 //       minor = aMinor;
 //       bugFix = aBugFix;
 //   }
 //   return self;
}
/*- (id)initWithString:(NSString *)version; {
    NSArray* components = [version componentsSeparatedByString:@"."];
    NSUInteger versMajor, versMinor, versBugFix;
    versMinor = versBugFix = 0;
    versMajor = [[components objectAtIndex:0] integerValue];
    if([components count] >= 2)
        versMinor = [[components objectAtIndex:1] integerValue];
    if([components count] >= 3)
        versBugFix = [[components objectAtIndex:2] integerValue];
    
    return [self initWithMajor:versMajor minor:versMinor bugFix:versBugFix];
}*/

const std::string MZVersion::description() //-(NSString*)description
{
  std::ostringstream description;
  description << major << "." << minor << "." << bugFix;
  return description.str();
//    return[NSString stringWithFormat : @"%lu. % lu. % lu",
//    (unsigned long)major,
//    (unsigned long)minor,
//    (unsigned long)bugFix];
}

//@synthesize major;
//@synthesize minor;
//@synthesize bugFix;


const MZComparison MZVersion::_compare(const MZVersion& v1, const MZVersion& v2)//- (NSComparisonResult)compare:(MZVersion *)aVersion;
{
    if(v1.major < v2.major)
      return MZComparison::MZLessThan;
    if(v1.major > v2.major)
      return MZComparison::MZGreaterThan;

    if(v1.minor < v2.minor)
        return MZComparison::MZLessThan;
    if(v1.minor > v2.minor)
        return MZComparison::MZGreaterThan;
    
    if(v1.bugFix < v2.bugFix)
        return MZComparison::MZLessThan;
    if(v1.bugFix > v2.bugFix)
        return MZComparison::MZGreaterThan;
    return MZComparison::MZEqual;
}

bool MZVersion::operator== (const MZVersion& v1)
{
  return (MZVersion::_compare(*this, v1) == MZComparison::MZLessThan); // return[self compare : aVersion] == NSOrderedAscending;
}

bool MZVersion::operator!= (const MZVersion& v1)
{
  return (!(MZVersion::_compare(*this, v1) == MZComparison::MZEqual));
}

bool MZVersion::operator<  (const MZVersion& v1)
{
  return (MZVersion::_compare(*this, v1) == MZComparison::MZLessThan); // return[self compare : aVersion] == NSOrderedAscending;
}

bool MZVersion::operator<= (const MZVersion& v1)
{
  MZComparison result = MZVersion::_compare(*this, v1);
  return (result == MZComparison::MZEqual || result == MZComparison::MZLessThan);//return [self compare:aVersion] <= NSOrderedSame;
}

bool MZVersion::operator>  (const MZVersion& v1)
{
  return (MZVersion::_compare(*this, v1) == MZComparison::MZGreaterThan); //return [self compare:aVersion] == NSOrderedDescending;
}

bool MZVersion::operator>= (const MZVersion& v1)
{
  MZComparison result = MZVersion::_compare(*this, v1);
  return (result == MZComparison::MZEqual || result == MZComparison::MZGreaterThan);
}

bool operator<(const MZVersion& v1, const MZVersion& v2)//- (BOOL)isLessThan:(MZVersion *)aVersion;
{
  return (MZVersion::_compare(v1, v2) == MZComparison::MZLessThan); // return[self compare : aVersion] == NSOrderedAscending;
}

bool operator<=(const MZVersion& v1, const MZVersion& v2)//- (BOOL)isLessThanOrEqualTo:(MZVersion *)aVersion;
{
  MZComparison result = MZVersion::_compare(v1, v2);
  return (result == MZComparison::MZEqual || result == MZComparison::MZLessThan);//return [self compare:aVersion] <= NSOrderedSame;
}

bool operator>(const MZVersion& v1, const MZVersion& v2)//- (BOOL)isGreaterThan:(MZVersion *)aVersion;
{
  return (MZVersion::_compare(v1, v2) == MZComparison::MZGreaterThan); //return [self compare:aVersion] == NSOrderedDescending;
}

bool operator>=(const MZVersion& v1, const MZVersion& v2)//- (BOOL)isGreaterThanOrEqualTo:(MZVersion *)aVersion;
{
  MZComparison result = MZVersion::_compare(v1, v2);
  return (result == MZComparison::MZEqual || result == MZComparison::MZGreaterThan);
//    return [self compare:aVersion] >= NSOrderedSame;
}

bool operator==(const MZVersion& v1, const MZVersion& v2)//- (BOOL)isEqual:(id)anObject
{
  return (MZVersion::_compare(v1, v2) == MZComparison::MZEqual);
//    if(![anObject isKindOfClass:[MZVersion class]])
//        return NO;
//    MZVersion* o = (MZVersion *)anObject;
//    return o.major == self.major && o.minor == self.minor && o.bugFix == self.bugFix;
}

bool operator!=(const MZVersion& v1, const MZVersion& v2)//- (BOOL)isEqual:(id)anObject
{
  return (!(MZVersion::_compare(v1, v2) == MZComparison::MZEqual));
}

//@end
