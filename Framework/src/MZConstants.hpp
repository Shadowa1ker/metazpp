#ifndef __MZCONSTANTS_HPP__
#define __MZCONSTANTS_HPP__

#include <string>

typedef enum
{
    MZUnsetVideoType = -1,
    MZHomeMovieVideoType = 0,
    MZNormalVideoType = 1,
    MZAudiobookVideoType = 2,
    MZWhackedBookmarkVideoType = 5,
    MZMusicVideoType = 6,
    MZMovieVideoType = 9,
    MZTVShowVideoType = 10,
    MZBookletVideoType = 11,
    MZRingtoneVideoType = 14,
    MZPodcastVideoType = 21,
    MZITunesUVideoType = 23
    
} MZVideoType;

typedef enum
{
    MZNoRating = 0,

    //US
    MZ_G_Rating,
    MZ_PG_Rating,
    MZ_PG13_Rating,
    MZ_R_Rating,
    MZ_NC17_Rating,
    MZ_Unrated_Rating,
    
    //US-TV
    MZ_TVY_Rating,
    MZ_TVY7_Rating,
    MZ_TVG_Rating,
    MZ_TVPG_Rating,
    MZ_TV14_Rating,
    MZ_TVMA_Rating,
    
    // UK
    MZ_U_Rating,
    MZ_Uc_Rating,
    MZ_PG_UK_Rating,
    MZ_12_UK_Rating,
    MZ_12A_Rating,
    MZ_15_UK_Rating,
    MZ_18_UK_Rating,
    MZ_E_UK_Rating,
    MZ_Unrated_UK_Rating,

    // DE
    MZ_FSK0_Rating,
    MZ_FSK6_Rating,
    MZ_FSK12_Rating,
    MZ_FSK16_Rating,
    MZ_FSK18_Rating,
    
    // IE
    MZ_G_IE_Rating,
    MZ_PG_IE_Rating,
    MZ_12_IE_Rating,
    MZ_15_IE_Rating,
    MZ_16_Rating,
    MZ_18_IE_Rating,
    MZ_Unrated_IE_Rating,
    
    // IE-TV
    MZ_GA_Rating,
    MZ_Ch_Rating,
    MZ_YA_Rating,
    MZ_PS_Rating,
    MZ_MA_IETV_Rating,
    MZ_Unrated_IETV_Rating,
    
    // CA
    MZ_G_CA_Rating,
    MZ_PG_CA_Rating,
    MZ_14_Rating,
    MZ_18_CA_Rating,
    MZ_R_CA_Rating,
    MZ_E_CA_Rating,
    MZ_Unrated_CA_Rating,
    
    // CA-TV
    MZ_C_CATV_Rating,
    MZ_C8_Rating,
    MZ_G_CATV_Rating,
    MZ_PG_CATV_Rating,
    MZ_14Plus_Rating,
    MZ_18Plus_Rating,
    MZ_Unrated_CATV_Rating,
    
    // AU
    MZ_E_AU_Rating,
    MZ_G_AU_Rating,
    MZ_PG_AU_Rating,
    MZ_M_AU_Rating,
    MZ_MA15Plus_AU_Rating,
    MZ_R18Plus_Rating,
    MZ_Unrated_AU_Rating,
    
    // AU-TV
    MZ_P_Rating,
    MZ_C_AUTV_Rating,
    MZ_G_AUTV_Rating,
    MZ_PG_AUTV_Rating,
    MZ_M_AUTV_Rating,
    MZ_MA15Plus_AUTV_Rating,
    MZ_AV15Plus_Rating,
    MZ_Unrated_AUTV_Rating,
    
    // NZ
    MZ_E_NZ_Rating,
    MZ_G_NZ_Rating,
    MZ_PG_NZ_Rating,
    MZ_M_NZ_Rating,
    MZ_R13_Rating,
    MZ_R15_Rating,
    MZ_R16_Rating,
    MZ_R18_Rating,
    MZ_R_NZ_Rating,
    MZ_Unrated_NZ_Rating,
    
    // NZ-TV
    MZ_G_NZTV_Rating,
    MZ_PGR_Rating,
    MZ_AO_Rating,
    MZ_Unrated_NZTV_Rating,
} MZRating;

// Comparison states
typedef enum class MZComparison
{
  MZEqual,
  MZLessThan,
  MZLessThanOrEqualTo,
  MZGreaterThan,
  MZGreaterThanOrEqualTo,
}MZComparison;

// Info
extern const std::string MZFileNameTagIdent;
extern const std::string MZPictureTagIdent;
extern const std::string MZTitleTagIdent;
extern const std::string MZArtistTagIdent;
extern const std::string MZDateTagIdent;
extern const std::string MZRatingTagIdent;
extern const std::string MZGenreTagIdent;
extern const std::string MZAlbumTagIdent;
extern const std::string MZAlbumArtistTagIdent;
extern const std::string MZPurchaseDateTagIdent;
extern const std::string MZShortDescriptionTagIdent;
extern const std::string MZLongDescriptionTagIdent;

// Video
extern const std::string MZVideoTypeTagIdent;
extern const std::string MZActorsTagIdent;
extern const std::string MZDirectorTagIdent;
extern const std::string MZProducerTagIdent;
extern const std::string MZScreenwriterTagIdent;
extern const std::string MZTVShowTagIdent;
extern const std::string MZTVEpisodeIDTagIdent;
extern const std::string MZTVSeasonTagIdent;
extern const std::string MZTVEpisodeTagIdent;
extern const std::string MZTVNetworkTagIdent;


// Sort
extern const std::string MZSortTitleTagIdent;
extern const std::string MZSortArtistTagIdent;
extern const std::string MZSortAlbumTagIdent;
extern const std::string MZSortAlbumArtistTagIdent;
extern const std::string MZSortTVShowTagIdent;
extern const std::string MZSortComposerTagIdent;

// MetaX Advanced
extern const std::string MZFeedURLTagIdent;
extern const std::string MZEpisodeURLTagIdent;
extern const std::string MZCategoryTagIdent;
extern const std::string MZKeywordTagIdent;
extern const std::string MZAdvisoryTagIdent;
extern const std::string MZPodcastTagIdent;
extern const std::string MZCopyrightTagIdent;
extern const std::string MZTrackNumberTagIdent;
extern const std::string MZTrackCountTagIdent;
extern const std::string MZDiscNumberTagIdent;
extern const std::string MZDiscCountTagIdent;
extern const std::string MZGroupingTagIdent;
extern const std::string MZEncodingToolTagIdent;
extern const std::string MZCommentTagIdent;
extern const std::string MZGaplessTagIdent;
extern const std::string MZCompilationTagIdent;


extern const std::string MZChaptersTagIdent;
extern const std::string MZChapterNamesTagIdent;
extern const std::string MZDurationTagIdent;

extern const std::string MZIMDBTagIdent;
extern const std::string MZASINTagIdent;
extern const std::string MZDVDSeasonTagIdent;
extern const std::string MZDVDEpisodeTagIdent;
extern const std::string MZiTunesPersistentIDTagIdent;

/* Notifications */
extern const std::string MZDataProviderLoadedNotification;
extern const std::string MZDataProviderWritingStartedNotification;
extern const std::string MZDataProviderWritingCanceledNotification;
extern const std::string MZDataProviderWritingFinishedNotification;
extern const std::string MZSearchFinishedNotification;
extern const std::string MZUndoActionNameNotification;
extern const std::string MZMetaEditsDeallocating;

extern const std::string MZQueueStartedNotification;
extern const std::string MZQueueItemStartedNotification;
extern const std::string MZQueueItemCompletedPercentNotification;
extern const std::string MZQueueItemCompletedNotification;
extern const std::string MZQueueItemFailedNotification;
extern const std::string MZQueueCompletedNotification;

extern const std::string MZMetaLoaderStartedNotification;
extern const std::string MZMetaLoaderFinishedNotification;

extern const std::string MZMetaEditsNotificationKey;
extern const std::string MZUndoActionNameKey;
extern const std::string MZDataControllerNotificationKey;
extern const std::string MZNSErrorKey;


// Standard alert ids
extern const std::string MZDataProviderFileAlreadyLoadedWarningKey;

extern const std::string iTunesMetadataPboardType;
extern const std::string iTunesPboardType;

// Plugin UTI
extern const std::string kMZUTMetaZPlugin;
extern const std::string kMZUTMetaZActionsPlugin;
extern const std::string kMZUTMetaZDataProviderPlugin;
extern const std::string kMZUTMetaZSearchProviderPlugin;
extern const std::string kMZUTAppleScriptText;
extern const std::string kMZUTAppleScript;
extern const std::string kMZUTAppleScriptBundle;
#endif // __MZCONSTANTS_HPP__