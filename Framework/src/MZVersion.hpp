#ifndef __MZVERSION_HPP__
#define __MZVERSION_HPP__
//
//  MZVersion.h
//  MetaZ
//
//  Created by Brian Olsen on 24/11/13.
//
//

//#import <Foundation/Foundation.h>

class MZVersion //@interface MZVersion : NSObject {
{
public:
  const unsigned int major;
  const unsigned int minor;
  const unsigned int bugFix;

  MZVersion(const unsigned int& major, const unsigned int& minor, const unsigned int& bugFix);//- (id)initWithMajor:(NSUInteger)major minor:(NSUInteger)minor bugFix:(NSUInteger)bugFix;
  const std::string description();
  //    NSUInteger major, minor, bugFix;
  //}
  //@property(readonly, nonatomic) NSUInteger major;
  //@property(readonly, nonatomic) NSUInteger minor;
  //@property(readonly, nonatomic) NSUInteger bugFix;
  bool operator== (const MZVersion& v1);
  bool operator!= (const MZVersion& v1);
  bool operator<  (const MZVersion& v1);
  bool operator<= (const MZVersion& v1);
  bool operator>  (const MZVersion& v1);
  bool operator>= (const MZVersion& v1);

  friend bool operator== (const MZVersion& v1, const MZVersion& v2);
  friend bool operator!= (const MZVersion& v1, const MZVersion& v2);
  friend bool operator<  (const MZVersion& v1, const MZVersion& v2);
  friend bool operator<= (const MZVersion& v1, const MZVersion& v2);
  friend bool operator>  (const MZVersion& v1, const MZVersion& v2);
  friend bool operator>= (const MZVersion& v1, const MZVersion& v2);

  static const std::string systemVersion(); // +(id)systemVersion;
  static const std::string versionWithString(); // +(id)versionWithString:(NSString*)systemVersion;
//+ (id)versionWithMajor:(NSUInteger)major minor:(NSUInteger)minor bugFix:(NSUInteger)bugFix;
//- (id)initWithString:(NSString *)systemVersion;

private:
  static const MZComparison _compare(const MZVersion& v1, const MZVersion& v2);
  //- (BOOL)isLessThan:(MZVersion *)aVersion;
  //- (BOOL)isLessThanOrEqualTo:(MZVersion *)aVersion;
  //- (BOOL)isGreaterThan:(MZVersion *)aVersion;
  //- (BOOL)isGreaterThanOrEqualTo:(MZVersion *)aVersion;
  //- (NSComparisonResult)compare:(MZVersion *)aVersion;

}; //@end

#endif // __MZVERSION_HPP__