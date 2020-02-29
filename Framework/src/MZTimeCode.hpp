#ifndef __MZTIMECODE_HPP__
#define __MZTIMECODE_HPP__
//
//  MZTimeCode.h
//  MetaZ
//
//  Created by Brian Olsen on 09/10/09.
//  Copyright 2009 Maven-Group. All rights reserved.
//

//#import <Cocoa/Cocoa.h>
#include <string>
#include "MZConstants.hpp"

class MZTimeCode //@interface MZTimeCode : NSObject <NSCoding,NSCopying> {
{
public:
  // NSUInteger millis;
  unsigned int get_millis() const;
  unsigned int get_ms() const;
  unsigned int get_sec() const;
  unsigned int get_min() const;
  unsigned int get_hour() const;

  bool isSet() const;

  MZTimeCode();
  MZTimeCode(const std::string& str);
  MZTimeCode(const unsigned int& millis);
  std::string stringValue() const;// -(NSString*)stringValue;
  std::string description() const;// -(NSString*)description;
  MZTimeCode addTimeCode(const MZTimeCode& timeCode);// -(MZTimeCode*)addTimeCode:(MZTimeCode*)timeCode;

  MZTimeCode& operator+= (const MZTimeCode& rhs); // MZTimeCode addMillis(const unsigned int& millis);// -(MZTimeCode*)addMillis:(NSUInteger)millis;
  MZTimeCode& operator+  (const MZTimeCode& rhs);
  MZTimeCode& operator-= (const MZTimeCode& rhs);
  MZTimeCode& operator-  (const MZTimeCode& rhs);
  bool operator== (const MZTimeCode& v1);
  bool operator!= (const MZTimeCode& v1);
  bool operator<  (const MZTimeCode& v1);
  bool operator<= (const MZTimeCode& v1);
  bool operator>  (const MZTimeCode& v1);
  bool operator>= (const MZTimeCode& v1);

  friend MZTimeCode operator+  (MZTimeCode lhs, const MZTimeCode& rhs);
  friend MZTimeCode operator-  (MZTimeCode lhs, const MZTimeCode& rhs);
  friend bool operator== (const MZTimeCode& v1, const MZTimeCode& v2);
  friend bool operator!= (const MZTimeCode& v1, const MZTimeCode& v2);
  friend bool operator<  (const MZTimeCode& v1, const MZTimeCode& v2);
  friend bool operator<= (const MZTimeCode& v1, const MZTimeCode& v2);
  friend bool operator>  (const MZTimeCode& v1, const MZTimeCode& v2);
  friend bool operator>= (const MZTimeCode& v1, const MZTimeCode& v2);

  //-(NSComparisonResult)compare:(MZTimeCode*)aTimeCode;

//}
//  +(id)timeCodeWithString:(NSString*)str;
//  +(id)timeCodeWithMillis:(NSUInteger)millis;
private:
  unsigned int millis;//@property (readonly) NSUInteger millis;
  unsigned int ms;// @property (readonly)NSUInteger ms;
  unsigned int sec;// @property (readonly)NSUInteger sec;
  unsigned int min;// @property (readonly)NSUInteger min;
  unsigned int hour;// @property (readonly)NSUInteger hour;

  bool set;
  static MZComparison _compare(const MZTimeCode& v1, const MZTimeCode& v2);

//  -(id)initWithString:(NSString*)str;
//  -(id)initWithMillis:(NSUInteger)millis;


}; // @end

#endif // __MZTIMECODE_HPP__