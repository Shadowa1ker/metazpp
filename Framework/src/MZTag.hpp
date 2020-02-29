#ifndef __MZTAG_HPP__
#define __MZTAG_HPP__

#include <string>
#include <vector>

class MZTag //@interface MZTag : NSObject
{
public:
	const std::string identifier; // @property(readonly) NSString *identifier;
	const std::string scriptName; //@property(readonly) NSString* scriptName;
  //@property(readonly) NSString* localizedName;
  //@property(readonly) NSCell* editorCell;//

  MZTag();
	MZTag(const std::string& identifier);// constructor - (id)initWithIdentifier:(NSString *)identifier;
	MZTag(const std::string& identifier, const std::string& scriptName);// constructor - (id)initWithIdentifier:(NSString *)identifier scriptName:(NSString *)scriptName;

  static void registerTag(const MZTag& tag); //+(void)registerTag:(MZTag*)tag;
  static std::vector<MZTag> infoTags(); //+ (NSArray *)infoTags;
  static std::vector<MZTag> videoTags(); // +(NSArray*)videoTags;
  static std::vector<MZTag> sortTags(); // +(NSArray*)sortTags;
  static std::vector<MZTag> advancedTags(); // +(NSArray*)advancedTags;
  static std::vector<MZTag> chapterTags(); // +(NSArray*)chapterTags;
  static std::map<std::string, MZTag> allKnownTags(); // +(NSArray*)allKnownTags;
  static std::string localizedNameForKnownIdentifier(const std::string& identifier);// +(NSString*)localizedNameForKnownIdentifier:(NSString*)identifier;
  static MZTag tagForIdentifier(const std::string& identifier); // +(id)tagForIdentifier:(NSString*)identifier;
  static MZTag tagForScriptName(const std::string& scriptName); // +(MZTag*)tagForScriptName:(NSString*)scriptName;
  static MZTag tagWithIdentifier(const std::string& identifier); // +(id)tagWithIdentifier:(NSString*)identifier;
  static MZTag tagWithIdentifier(const std::string& identifier, const std::string& scriptName); //j+(id)tagWithIdentifier:(NSString*)identifier scriptName : (NSString*)scriptName;
  //-(const char*)encoding;
  //-(id)convertValueToObject:(void*)buffer;
  //-(void)convertObject:(id)obj toValue : (void*)buffer;
  //-(id)nullConvertValueToObject:(void*)buffer;
  //-(void)nullConvertObject:(id)obj toValue : (void*)buffer;
  //-(id)convertObjectForRetrival:(id)obj;
  //-(id)convertObjectForStorage:(id)obj;
  //-(id)objectFromString:(NSString*)str;
  //-(NSString*)stringForObject:(id)str;

private:
  static std::mutex sharedMutex;
  static std::map<std::string, MZTag> sharedTags;// static NSMutableDictionary* sharedTags = nil;
  static std::map<std::string, MZTag> sharedTagScriptNames;// static NSMutableDictionary* sharedTagScriptNames = nil;
};
//@end

class MZReadOnlyTag : public MZTag //@interface MZReadOnlyTag : MZTag {}
{

};
//@end

class MZStringTag : public MZTag //@interface MZStringTag : MZTag {}
{
public:
  MZStringTag(const std::string& identifier, const std::string &scriptName);
};
//@end

class MZDateTag : public MZTag//@interface MZDateTag : MZTag {}
{

};

//@end

class MZYearDateTag : public MZTag //@interface MZYearDateTag : MZTag {}
{

};
//@end

class MZIntegerTag : public MZTag //@interface MZIntegerTag : MZTag {}
{

};
//@end

class MZBoolTag : MZTag //@interface MZBoolTag : MZTag {}
{

};
//@end

class MZEnumTag : public MZTag // //@interface MZEnumTag : MZTag {}
{
public:
  MZEnumTag(const std::string&, const std::string&);
  std::string enumScriptName(); //- (NSString *)enumScriptName;
  int nilValue();//- (int)nilValue;
  std::vector<std::string> values();//- (NSArray *)values;
  std::vector<std::string> valueNames();//- (NSArray *)valueNames;
  std::vector<std::string> localizedValueNames();//- (NSArray *)localizedValueNames;
};

//@end

class MZTimeCodeTag : MZReadOnlyTag
{

};
//@interface MZTimeCodeTag : MZReadOnlyTag {}

//@end

#endif // __MZTAG_HPP__