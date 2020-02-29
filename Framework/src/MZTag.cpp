#include <map>
#include <mutex>

#include "MZTag.hpp"
#include "MZConstants.hpp"
//#import <MetaZKit/MZTimeCode.h>
//#import <MetaZKit/NSDate+UTC.h>
//#import <MetaZKit/MZLogger.h>
//#import <MetaZKit/NSString+MZAllInCharacterSet.h>

class MZVideoTypeTagClass : public MZEnumTag //Was @interface MZVideoTypeTagClass : MZEnumTag
{
	std::vector<std::string> typeNames; // Was NSArray*
	std::vector<std::string> localizedTypeNames; // Was NSArray*
	std::vector<std::string> typeValues; // Was NSArray*
};

class MZRatingTag : public MZEnumTag //@interface MZRatingTag : MZEnumTag
{
public:
  MZRatingTag(const std::string& identifier, const std::string& scriptName);
	std::vector<std::string> ratingNames; // NSArray* ratingNames;
	std::vector<std::string> ratingNamesNonStrict; // NSArray* ratingNamesNonStrict;
	std::vector<MZRating> ratingValuesNonStrict; // NSMutableArray* ratingValuesNonStrict;
};

MZStringTag::MZStringTag(const std::string& identifier, const std::string& scriptName)
  : MZTag(identifier, scriptName)
{

}

MZTag::MZTag()
//+ (void)initialize
{
    // Info tags
  const std::string str("file name");
  MZStringTag stringTag(MZFileNameTagIdent, str);
  
//  MZTag::registerTag(dynamic_cast<const MZTag>(MZStringTag(MZFileNameTagIdent, static_cast<const std::string>(std::string("file name")))));// [self registerTag : [MZStringTag tagWithIdentifier : MZFileNameTagIdent scriptName : @"file name"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZPictureTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZTitleTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZArtistTagIdent]];
    //[self registerTag:[MZYearDateTag tagWithIdentifier:MZDateTagIdent]];
    //[self registerTag:[MZRatingTag tagWithIdentifier:MZRatingTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZGenreTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZAlbumTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZAlbumArtistTagIdent scriptName:@"album artist"]];
    //[self registerTag:[MZDateTag tagWithIdentifier:MZPurchaseDateTagIdent scriptName:@"purchase date"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZShortDescriptionTagIdent scriptName:@"description"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZLongDescriptionTagIdent scriptName:@"long description"]];

    // Video tags
    //[self registerTag:[MZVideoTypeTagClass tagWithIdentifier:MZVideoTypeTagIdent scriptName:@"video type"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZActorsTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZDirectorTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZProducerTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZScreenwriterTagIdent scriptName:@"writer"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZTVShowTagIdent scriptName:@"tv show"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZTVEpisodeIDTagIdent scriptName:@"tv episode id"]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZTVSeasonTagIdent scriptName:@"tv season"]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZTVEpisodeTagIdent scriptName:@"tv episode"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZTVNetworkTagIdent scriptName:@"tv network"]];

    // Sort tags
    //[self registerTag:[MZStringTag tagWithIdentifier:MZSortTitleTagIdent scriptName:@"sort title"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZSortArtistTagIdent scriptName:@"sort artist"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZSortAlbumTagIdent scriptName:@"sort album"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZSortAlbumArtistTagIdent scriptName:@"sort album artist"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZSortTVShowTagIdent scriptName:@"sort tv show"]];
    
    // Advanced tags
    //[self registerTag:[MZStringTag tagWithIdentifier:MZFeedURLTagIdent scriptName:@"feed url"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZEpisodeURLTagIdent scriptName:@"episode url"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZCategoryTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZKeywordTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZAdvisoryTagIdent]];
    //[self registerTag:[MZBoolTag tagWithIdentifier:MZPodcastTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZCopyrightTagIdent]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZTrackNumberTagIdent scriptName:@"track number"]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZTrackCountTagIdent scriptName:@"track count"]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZDiscNumberTagIdent scriptName:@"disc number"]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZDiscCountTagIdent scriptName:@"disc count"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZGroupingTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZEncodingToolTagIdent scriptName:@"encoding tool"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZCommentTagIdent]];
    //[self registerTag:[MZBoolTag tagWithIdentifier:MZGaplessTagIdent]];
    //[self registerTag:[MZBoolTag tagWithIdentifier:MZCompilationTagIdent]];
    
    // Chapter tags
    //[self registerTag:[MZTag tagWithIdentifier:MZChaptersTagIdent]];
    //[self registerTag:[MZReadOnlyTag tagWithIdentifier:MZChapterNamesTagIdent scriptName:@"chapter names"]];

    //[self registerTag:[MZTimeCodeTag tagWithIdentifier:MZDurationTagIdent]];
    
    //[self registerTag:[MZStringTag tagWithIdentifier:MZIMDBTagIdent]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZASINTagIdent]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZDVDSeasonTagIdent scriptName:@"dvd season"]];
    //[self registerTag:[MZIntegerTag tagWithIdentifier:MZDVDEpisodeTagIdent scriptName:@"dvd episode"]];
    //[self registerTag:[MZStringTag tagWithIdentifier:MZiTunesPersistentIDTagIdent scriptName:@"itunes persistent id"]];

}

// These aren't part of a class, they are global statics, which is why we lock when we populate.
// Could have something to do with plugins.
std::mutex MZTag::sharedMutex;
std::map<std::string, MZTag> MZTag::sharedTags;// static NSMutableDictionary* sharedTags = nil;
std::map<std::string, MZTag> MZTag::sharedTagScriptNames;// static NSMutableDictionary* sharedTagScriptNames = nil;

void MZTag::registerTag (const MZTag& tag)
//+ (void)registerTag:(MZTag *)tag
{
  std::lock_guard<std::mutex> lock(MZTag::sharedMutex);
//    @synchronized(self)
//    {
//        if(!sharedTags)
//            sharedTags = [[NSMutableDictionary alloc] init];
  MZTag::sharedTags.emplace(tag.identifier, tag);// [sharedTags setObject : tag forKey : tag.identifier] ;
//        if(!sharedTagScriptNames)
//            sharedTagScriptNames = [[NSMutableDictionary alloc] init];
  MZTag::sharedTagScriptNames.emplace(tag.scriptName, tag);// [sharedTagScriptNames setObject : tag forKey : tag.scriptName] ;
//    }
}

MZTag MZTag::tagForIdentifier(const std::string& identifier) //+ (MZTag *)tagForIdentifier:(NSString *)identifier
{
//    @synchronized(self)
//    {
//        if(sharedTags)
    try
    {
      std::lock_guard<std::mutex> lock(MZTag::sharedMutex);
      return sharedTags.at(identifier); //ret = [sharedTags objectForKey : identifier];
    }
    catch (...)
    {
    }
    MZTag tag;
//    }
    return tag;
}

MZTag MZTag::tagForScriptName(const std::string& scriptName)//+ (MZTag *)tagForScriptName:(NSString *)scriptName
{
//    MZTag *ret = nil;
//    @synchronized(self)
//    {
//        if(sharedTagScriptNames)
    try
    {
      std::lock_guard<std::mutex> lock(MZTag::sharedMutex);
      return MZTag::sharedTags.at(scriptName); // ret = [sharedTagScriptNames objectForKey : scriptName];
    }
    catch(...)
    {
    }
    MZTag tag;
//    }
    return tag;
}

std::map<std::string, MZTag> MZTag::allKnownTags() //+ (NSArray*)allKnownTags
{
  std::lock_guard<std::mutex> lock(MZTag::sharedMutex);
  std::map<std::string, MZTag> allTags(MZTag::sharedTags);
  return allTags;
  //    NSArray* ret = [NSArray array];
  //  @synchronized(self)
  //  {
  //      if(sharedTags)
  //          ret = [NSArray arrayWithArray:[sharedTags allValues]];
  //  }
  //  return ret;
}

std::vector<MZTag> MZTag::infoTags()//+ (NSArray*)infoTags
{
  return { {MZFileNameTagIdent},
           {MZPictureTagIdent}
         };
 }
 /*
    return [NSArray arrayWithObjects:
        [self tagForIdentifier:MZFileNameTagIdent],
        [self tagForIdentifier:MZPictureTagIdent],
        [self tagForIdentifier:MZTitleTagIdent],
        [self tagForIdentifier:MZArtistTagIdent],
        [self tagForIdentifier:MZDateTagIdent],
        [self tagForIdentifier:MZRatingTagIdent],
        [self tagForIdentifier:MZGenreTagIdent],
        [self tagForIdentifier:MZAlbumTagIdent],
        [self tagForIdentifier:MZAlbumArtistTagIdent],
        [self tagForIdentifier:MZPurchaseDateTagIdent],
        [self tagForIdentifier:MZShortDescriptionTagIdent],
        [self tagForIdentifier:MZLongDescriptionTagIdent],
        [self tagForIdentifier:MZAlbumArtistTagIdent],
        nil];
}

+ (NSArray*)videoTags
{
    return [NSArray arrayWithObjects:
        [self tagForIdentifier:MZVideoTypeTagIdent],
        [self tagForIdentifier:MZActorsTagIdent],
        [self tagForIdentifier:MZDirectorTagIdent],
        [self tagForIdentifier:MZProducerTagIdent],
        [self tagForIdentifier:MZScreenwriterTagIdent],
        [self tagForIdentifier:MZTVShowTagIdent],
        [self tagForIdentifier:MZTVEpisodeIDTagIdent],
        [self tagForIdentifier:MZTVSeasonTagIdent],
        [self tagForIdentifier:MZTVEpisodeTagIdent],
        [self tagForIdentifier:MZTVNetworkTagIdent],
        nil];
}

+ (NSArray*)sortTags
{
    return [NSArray arrayWithObjects:
        [self tagForIdentifier:MZSortTitleTagIdent],
        [self tagForIdentifier:MZSortArtistTagIdent],
        [self tagForIdentifier:MZSortAlbumTagIdent],
        [self tagForIdentifier:MZSortAlbumArtistTagIdent],
        [self tagForIdentifier:MZSortTVShowTagIdent],
        nil];
}

+ (NSArray*)advancedTags
{
    return [NSArray arrayWithObjects:
        [self tagForIdentifier:MZFeedURLTagIdent],
        [self tagForIdentifier:MZEpisodeURLTagIdent],
        [self tagForIdentifier:MZCategoryTagIdent],
        [self tagForIdentifier:MZKeywordTagIdent],
        [self tagForIdentifier:MZAdvisoryTagIdent],
        [self tagForIdentifier:MZPodcastTagIdent],
        [self tagForIdentifier:MZCopyrightTagIdent],
        [self tagForIdentifier:MZTrackNumberTagIdent],
        [self tagForIdentifier:MZTrackCountTagIdent],
        [self tagForIdentifier:MZDiscNumberTagIdent],
        [self tagForIdentifier:MZDiscCountTagIdent],
        [self tagForIdentifier:MZGroupingTagIdent],
        [self tagForIdentifier:MZEncodingToolTagIdent],
        [self tagForIdentifier:MZCommentTagIdent],
        [self tagForIdentifier:MZGaplessTagIdent],
        [self tagForIdentifier:MZCompilationTagIdent],
        nil];
}

+ (NSArray *)chapterTags
{
    return [NSArray arrayWithObjects:
        [self tagForIdentifier:MZChaptersTagIdent],
        [self tagForIdentifier:MZChapterNamesTagIdent],
        nil];
}

+ (NSString *)localizedNameForKnownIdentifier:(NSString *)identifier
{
    return NSLocalizedStringFromTableInBundle(
            identifier, 
            @"MZTags", 
            [NSBundle bundleForClass:[self class]],
            @"Name for tag");
}

+ (id)tagWithIdentifier:(NSString *)identifier
{
    return [[[self alloc] initWithIdentifier:identifier] autorelease];
}

+ (id)tagWithIdentifier:(NSString *)identifier scriptName:(NSString *)scriptName
{
    return [[[self alloc] initWithIdentifier:identifier scriptName:scriptName] autorelease];
}
*/
MZTag::MZTag(const std::string& identifier) //- (id)initWithIdentifier:(NSString *)theIdentifier
{
  MZTag(identifier, identifier);
 //   return [self initWithIdentifier:theIdentifier scriptName:theIdentifier];
}

MZTag::MZTag(const std::string& identifier, const std::string& scriptName) //- (id)initWithIdentifier:(NSString *)theIdentifier scriptName:(NSString *)theScriptName
  : identifier(identifier), scriptName(scriptName)
{
  MZTag();
//    self = [super init];
//    if(self)
//    {
//        identifier = [theIdentifier retain];
//        scriptName = [theScriptName retain];
//    }
//   return self;
}
/*
- (void)dealloc
{
    [identifier release];
    [scriptName release];
    [super dealloc];
}

@synthesize identifier;
@synthesize scriptName;

- (NSString *)localizedName
{
    return [[self class] localizedNameForKnownIdentifier:[self identifier]];
}

- (NSCell *)editorCell
{
    return nil;
}

- (const char*)encoding
{
    return @encode(id);
}

- (id)convertValueToObject:(void*)buffer
{
    id* v = (id*)buffer;
    return *v;
}

- (void)convertObject:(id)obj toValue:(void*)buffer
{
    id* v = (id*)buffer;
    *v = obj;
}

- (id)nullConvertValueToObject:(void*)buffer
{
    id ret = [self convertValueToObject:buffer];
    if(ret)
        return ret;
    return [NSNull null];
}

- (void)nullConvertObject:(id)obj toValue:(void*)buffer
{
    if(obj == [NSNull null])
        obj = nil;
    [self convertObject:obj toValue:buffer];
}

- (id)convertObjectForRetrival:(id)obj
{
    if(obj == [NSNull null])
        return nil;
    return obj;
}

- (id)convertObjectForStorage:(id)obj
{
    if(!obj)
        return [NSNull null];
    return obj;
}

- (id)objectFromString:(NSString *)str
{
    return nil;
}

- (NSString *)stringForObject:(id)obj
{
    if(!obj || obj == [NSNull null] || ![obj respondsToSelector:@selector(stringValue)])
        return @"";
    return [obj stringValue];
}

@end
*/
/*
@implementation MZReadOnlyTag
- (id)convertObjectForStorage:(id)obj
{
    [NSException raise:@"MZTagReadOnly" format:@"Tag '%@' is read only", [self identifier]];
    return nil;
}
@end
*/
/*
@implementation MZStringTag

- (NSCell *)editorCell
{
    return [[[NSTextFieldCell alloc] initTextCell:@""] autorelease]; 
}

- (id)objectFromString:(NSString *)str
{
    if(!str || [str length]==0)
        return nil;
    return str;
}

- (NSString *)stringForObject:(id)obj
{
    if(!obj || obj == [NSNull null])
        return @"";
    return obj;
}


@end


@implementation MZDateTag

- (NSCell *)editorCell
{
    return [[[NSTextFieldCell alloc] initTextCell:@""] autorelease]; 
}

- (id)convertValueToObject:(void*)buffer
{
    NSDate** str = (NSDate**)buffer;
    return *str;
}

- (void)convertObject:(id)obj toValue:(void*)buffer
{
    NSDate** str = (NSDate**)buffer;
    *str = obj;
}

- (id)objectFromString:(NSString *)str
{
    if(!str || [str length]==0)
        return nil;
    
    return [NSDate dateWithUTCString:str];
}

- (NSString *)stringForObject:(id)obj
{
    if(!obj || obj == [NSNull null])
        return @"";
    NSDate* date = obj;
    return [date utcTimestamp];
}

@end


@implementation MZYearDateTag

- (NSCell *)editorCell
{
    return [[[NSTextFieldCell alloc] initTextCell:@""] autorelease]; 
}

- (id)convertValueToObject:(void*)buffer
{
    id* str = (id*)buffer;
    return *str;
}

- (void)convertObject:(id)obj toValue:(void*)buffer
{
    id* str = (id*)buffer;
    *str = obj;
}

- (id)objectFromString:(NSString *)str
{
    if(!str || [str length]==0)
        return nil;

    if([str mz_allInCharacterSet:[NSCharacterSet decimalDigitCharacterSet]])
        return [NSNumber numberWithInt:[str intValue]];
    return [NSDate dateWithUTCString:str];
}

- (NSString *)stringForObject:(id)obj
{
    if(!obj || obj == [NSNull null])
        return @"";
    if([obj isKindOfClass:[NSNumber class]])
        return [obj stringValue];
    NSDate* date = obj;
    return [date utcTimestamp];
}

@end


@implementation MZIntegerTag

- (NSCell *)editorCell
{
    return [[[NSTextFieldCell alloc] initTextCell:@""] autorelease]; 
}

- (id)convertValueToObject:(void*)buffer
{
    NSNumber** str = (NSNumber**)buffer;
    return *str;
}

- (void)convertObject:(id)obj toValue:(void*)buffer
{
    NSNumber** str = (NSNumber**)buffer;
    *str = obj;
}

- (id)objectFromString:(NSString *)str
{
    if(!str || [str length]==0)
        return nil;
    
    NSInteger i = [str integerValue];
    return [NSNumber numberWithInteger:i];
}

@end

@implementation MZBoolTag : MZTag

- (NSCell *)editorCell
{
    return [[[NSTextFieldCell alloc] initTextCell:@""] autorelease]; 
}

- (id)convertValueToObject:(void*)buffer
{
    NSNumber** str = (NSNumber**)buffer;
    return *str;
}

- (void)convertObject:(id)obj toValue:(void*)buffer
{
    NSNumber** str = (NSNumber**)buffer;
    *str = obj;
}

- (id)objectFromString:(NSString *)str
{
    if(!str || [str length]==0)
        return nil;
    
    BOOL value = [str boolValue];
    return [NSNumber numberWithBool:value];
}

@end


@implementation MZTimeCodeTag

- (NSCell *)editorCell
{
    return [[[NSTextFieldCell alloc] initTextCell:@""] autorelease]; 
}

- (id)convertValueToObject:(void*)buffer
{
    MZTimeCode** str = (MZTimeCode**)buffer;
    return *str;
}

- (void)convertObject:(id)obj toValue:(void*)buffer
{
    MZTimeCode** str = (MZTimeCode**)buffer;
    *str = obj;
}

- (id)objectFromString:(NSString *)str
{
    if(!str || [str length]==0)
        return nil;
    
    return [MZTimeCode timeCodeWithString:str];
}

@end


@interface NSPopUpButtonCell (AddItemWithTag)
- (void)addItemWithTitle:(NSString *)title tag:(NSInteger)tag;
@end

@implementation NSPopUpButtonCell (AddItemWithTag)
- (void)addItemWithTitle:(NSString *)title tag:(NSInteger)tag
{
    [self addItemWithTitle:title];
    [[self lastItem] setTag:tag];
}
@end


@implementation MZEnumTag
*/
MZEnumTag::MZEnumTag(const std::string& identifier, const std::string& scriptName)
  : MZTag(identifier, scriptName)
{
}
/*
- (NSString *)enumScriptName
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

- (NSArray *)values
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

- (NSArray *)valueNames
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

- (NSArray *)localizedValueNames
{
    [self doesNotRecognizeSelector:_cmd];
    return nil;
}

- (const char*)encoding
{
    return @encode(int);
}

- (id)convertValueToObject:(void*)buffer
{
    int* value = (int*)buffer;
    return [NSNumber numberWithInt:*value];
}

- (void)convertObject:(id)obj toValue:(void*)buffer
{
    int* ret = (int*)buffer;
    if(!obj || obj == [NSNull null] || ![obj respondsToSelector:@selector(intValue)])
        *ret = [self nilValue];
    else
        *ret = [obj intValue];
}

- (id)convertObjectForRetrival:(id)obj
{
    int ret = [self nilValue];
    if(obj && obj != [NSNull null] && [obj respondsToSelector:@selector(intValue)])
        ret = [obj intValue];
    return [NSNumber numberWithInt:ret];
}

- (id)convertObjectForStorage:(id)obj
{
    int ret = [self nilValue];
    if(obj && obj != [NSNull null] && [obj respondsToSelector:@selector(intValue)])
        ret = [obj intValue];
    return [NSNumber numberWithInt:ret];
}

- (int)nilValue
{
    return 0;
}

@end


@implementation MZVideoTypeTagClass

- (id)initWithIdentifier:(NSString *)theIdentifier scriptName:(NSString *)theScriptName
{
    self = [super initWithIdentifier:theIdentifier scriptName:theScriptName];
    if(self)
    {
        typeNames = [[NSArray alloc] initWithObjects:
            @"", @"Home Movie", @"Normal", 
            @"Audiobook", @"Whacked Bookmark", @"Music Video",
            @"Movie", @"TV Show", @"Booklet",
            @"Ringtone", @"Podcast", @"iTunes U",
            nil];
        NSAssert([typeNames count] == 12, @"Bad number of types");
        int typeValuesTemp[] = {
            MZUnsetVideoType, MZHomeMovieVideoType, MZNormalVideoType, 
            MZAudiobookVideoType, MZWhackedBookmarkVideoType, MZMusicVideoType,
            MZMovieVideoType, MZTVShowVideoType, MZBookletVideoType,
            MZRingtoneVideoType, MZPodcastVideoType, MZITunesUVideoType
            };
        NSMutableArray* names = [NSMutableArray array];
        NSMutableArray* values = [NSMutableArray array];
        NSInteger count = [typeNames count];
        for(int i=0; i<count; i++)
        {
            [names addObject:NSLocalizedStringFromTable([typeNames objectAtIndex:i], @"VideoType", @"Video type")];
            [values addObject:[NSNumber numberWithInt:typeValuesTemp[i]]];
        }
        localizedTypeNames = [[NSArray alloc] initWithArray:names];
        typeValues = [[NSArray alloc] initWithArray:values];
    }
    return self;
}

- (void)dealloc
{
    [typeNames release];
    [typeValues release];
    [super dealloc];
}

- (NSArray *)values
{
    return typeValues;
}

- (NSArray *)valueNames
{
    return typeNames;
}

- (NSArray *)localizedValueNames
{
    return localizedTypeNames;
}

- (NSString *)enumScriptName;
{
    return @"video type";
}

- (NSCell *)editorCell
{
    NSPopUpButtonCell* cell = [[[NSPopUpButtonCell alloc] initTextCell:@"" pullsDown:NO] autorelease]; 
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Home Movie", @"VideoType", @"Video type") tag:MZHomeMovieVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Normal", @"VideoType", @"Video type") tag:MZNormalVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Audiobook", @"VideoType", @"Video type") tag:MZAudiobookVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Whacked Bookmark", @"VideoType", @"Video type") tag:MZWhackedBookmarkVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Music Video", @"VideoType", @"Video type") tag:MZMusicVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Movie", @"VideoType", @"Video type") tag:MZMovieVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"TV Show", @"VideoType", @"Video type") tag:MZTVShowVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Booklet", @"VideoType", @"Video type") tag:MZBookletVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Ringtone", @"VideoType", @"Video type") tag:MZRingtoneVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"Podcast", @"VideoType", @"Video type") tag:MZPodcastVideoType];
    [cell addItemWithTitle:NSLocalizedStringFromTable(@"iTunes U", @"VideoType", @"Video type") tag:MZITunesUVideoType];
    return cell;
}

- (const char*)encoding
{
    return @encode(MZVideoType);
}

- (int)nilValue
{
    return MZUnsetVideoType;
}

- (id)objectFromString:(NSString *)str
{
    if(!str)
        return [NSNumber numberWithInt:MZUnsetVideoType];
    NSInteger i = [typeNames indexOfObject:str];
    if(i == NSNotFound)
    {
        MZLoggerError(@"Found no video type for '%@'", str);
        return [NSNumber numberWithInt:MZUnsetVideoType];
    }
    return [typeValues objectAtIndex:i];
}

- (NSString *)stringForObject:(id)obj
{
    if(!obj || obj == [NSNull null] || ![obj respondsToSelector:@selector(intValue)])
        return @"";
    MZVideoType type = [obj intValue];
    int count = [typeValues count];
    for(int i=0; i<count; i++)
    {
        NSNumber* num = [typeValues objectAtIndex:i];
        if(type == [num intValue])
            return [typeNames objectAtIndex:i];
    }
    return @"";
}


@end
*/

//@implementation MZRatingTag

MZRatingTag::MZRatingTag(const std::string& identifier, const std::string& scriptName) //- (id)initWithIdentifier:(NSString *)theIdentifier scriptName:(NSString *)theScriptName
  : MZEnumTag(identifier, scriptName)
{  
//    self =  [super initWithIdentifier:theIdentifier scriptName:theScriptName];
//    if(self)
//    {
//        ratingNames = [[NSArray alloc] initWithObjects:
  this->ratingNames = { "No Rating",
                       "G", "PG", "PG-13", "R", "NC-17", "Unrated" };
//  this->ratingNames.push_back("No Rating");//            @"No Rating",
  // US
//  this->ratingNames.push_back("G"); //          @"G", @"PG", @"PG-13", @"R", @"NC-17", @"Unrated",
//  this->ratingNames.push_back("PG");
//  this->ratingNames.push_back("PG-13");
//  this->ratingNames.push_back("R");
//  this->ratingNames.push_back("NC-17");
//  this->ratingNames.push_back("Unrated");
  // US TV
//  this->ratingNames.push_back("Unrated");
//  @"TV-Y", @"TV-Y7", @"TV-G", @"TV-PG", @"TV-14", @"TV-MA",
            // UK
//            @"U", @"Uc", @"PG (UK)", @"12 (UK)", @"12A", @"15 (UK)", @"18 (UK)", @"E (UK)", @"UNRATED (UK)",
//            // DE
//            @"FSK-0", @"FSK-6", @"FSK-12", @"FSK-16", @"FSK-18",
//            // IE
//            @"G (IE)", @"PG (IE)", @"12 (IE)", @"15 (IE)", @"16", @"18 (IE)", @"UNRATED (IE)",
//            // IE TV
//            @"GA", @"Ch", @"YA", @"PS", @"MA (IE-TV)", @"UNRATED (IE-TV)",
//            // CA
//            @"G (CA)", @"PG (CA)", @"14", @"18 (CA)", @"R (CA)", @"E (CA)", @"UNRATED (CA)",
//            // CA-TV
//            @"C (CA-TV)", @"C8", @"G (CA-TV)", @"PG (CA-TV)", @"14+", @"18+", @"UNRATED (CA-TV)",
//            // AU
//            @"E (AU)", @"G (AU)", @"PG (AU)", @"M (AU)", @"MA 15+", @"R 18+", @"UNRATED (AU)",
//            // AU TV
//            @"P", @"C (AU-TV)", @"G (AU-TV)", @"PG (AU-TV)", @"M (AU-TV)", @"MA 15+ (AU-TV)", @"AV 15+", @"UNRATED (AU-TV)",
//            // NZ
//            @"E (NZ)", @"G (NZ)", @"PG (NZ)", @"M (NZ)", @"R13", @"R15", @"R16",
//            @"R18", @"R (NZ)", @"UNRATED (NZ)",
//            // NZ TV
//            @"G (NZ-TV)", @"PGR", @"AD", @"UNRATED (NZ-TV)",
//            nil];
//        NSAssert([ratingNames count] == MZ_Unrated_NZTV_Rating+1, @"Bad number of ratings");
  this->ratingNamesNonStrict = {
    "UNRATED",
    "FSK 0", "FSK 6", "FSK 12", "FSK 16", "FSK 18"
  };
//        ratingNamesNonStrict = [[NSArray alloc] initWithObjects:
//            @"UNRATED",
//            @"FSK 0", @"FSK 6", @"FSK 12", @"FSK 16", @"FSK 18",
//            nil];
  this->ratingValuesNonStrict = {
    MZ_Unrated_Rating,
    MZ_FSK0_Rating, MZ_FSK6_Rating, MZ_FSK12_Rating, MZ_FSK16_Rating, MZ_FSK18_Rating
  };
//        int ratingNonStrictValues[] = {
//            MZ_Unrated_Rating,
//            MZ_FSK0_Rating, MZ_FSK6_Rating, MZ_FSK12_Rating, MZ_FSK16_Rating, MZ_FSK18_Rating
//            };
//        ratingValuesNonStrict = [[NSMutableArray alloc] init];
//        NSInteger count = [ratingNamesNonStrict count];
//        for(int i=0; i<count; i++)
//           [ratingValuesNonStrict addObject:[NSNumber numberWithInt:ratingNonStrictValues[i]]];
//    }
//    return self;
}

//- (void)dealloc
//{
//    [ratingNames release];
//    [ratingNamesNonStrict release];
//    [ratingValuesNonStrict release];
//    [super dealloc];
//}
/*
std::string MZRatingTag::enumScriptName() //- (NSString *)enumScriptName;
{
    return "rating";
}

- (NSCell *)editorCell
{
    NSPopUpButtonCell* cell = [[[NSPopUpButtonCell alloc] initTextCell:@"" pullsDown:NO] autorelease];
    NSInteger count = [ratingNames count];
    for(NSInteger i=0; i<count; i++)
    {
        [cell addItemWithTitle:[ratingNames objectAtIndex:i] tag:i];
    }
    return cell;
}

- (const char*)encoding
{
    return @encode(MZRating);
}

- (int)nilValue
{
    return MZNoRating;
}

- (id)objectFromString:(NSString *)str
{
    if(!str || [str length] == 0)
        return [NSNumber numberWithInt:MZNoRating];
    NSInteger i = [ratingNames indexOfObject:str];
    if(i == NSNotFound)
    {
        i = [ratingNamesNonStrict indexOfObject:str];
        if(i != NSNotFound)
            i = [[ratingValuesNonStrict objectAtIndex:i] integerValue];
    }
    if(i == NSNotFound)
    {
        MZLoggerError(@"Found no rating for '%@'", str);
        return [NSNumber numberWithInt:MZNoRating];
    }
    return [NSNumber numberWithInt:i];
}


@end
*/


