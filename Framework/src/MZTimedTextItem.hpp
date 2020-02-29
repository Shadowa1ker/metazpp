//
//  MZTimedTextItem.h
//  MetaZ
//
//  Created by Brian Olsen on 09/10/09.
//  Copyright 2009 Maven-Group. All rights reserved.
//

//#import <Cocoa/Cocoa.h>
#include <vector>
#include "MZTimeCode.hpp" //#import <MetaZKit/MZTimeCode.h>

class MZTimedTextItem //@interface MZTimedTextItem : NSObject <NSCoding,NSCopying,NSMutableCopying>
{
public:
  // MZTimeCode* start;
  // MZTimeCode* duration;
  // NSString* text;
//}
  static std::vector<MZTimedTextItem> parseChapters(const std::string& str, MZTimeCode& duration); // +(NSArray*)parseChapters : (NSString*)str duration : (MZTimeCode*)duration;
  static std::vector<MZTimedTextItem> parseOggChapters(const std::string& str, MZTimeCode& duration); // +(NSArray*)parseOggChapters:(NSString*)str duration : (MZTimeCode*)duration;
  static std::vector<MZTimedTextItem> parseMP4Chapters(const std::string& str, MZTimeCode& duration); // +(NSArray*)parseMP4Chapters:(NSString*)str duration : (MZTimeCode*)duration;
  static std::vector<MZTimedTextItem> parseWebChapters(const std::string& str, MZTimeCode& duration); //+(NSArray*)parseWebChapters:(NSString*)str duration : (MZTimeCode*)duration;

  //+(id)textItemWithStart:(MZTimeCode*)start duration : (MZTimeCode*)duration text : (NSString*)text;
  MZTimedTextItem(const MZTimeCode& start, const MZTimeCode& duration, const std::string& text); // -(id)initWithStart:(MZTimeCode*)start duration : (MZTimeCode*)duration text : (NSString*)text;

private:
  MZTimeCode start; // @property(readonly) MZTimeCode* start;
  MZTimeCode duration; // @property(readonly) MZTimeCode* duration;
  std::string text; // @property(readonly, copy, getter = text) NSString* text;
};
//@end


class MZMutableTimedTextItem : public MZTimedTextItem //@interface MZMutableTimedTextItem : MZTimedTextItem
{
public:
  std::string text;
};
//@property (copy,getter=text) NSString* text;

//@end