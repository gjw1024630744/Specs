//
//  PAGSShortInfos.h
//  AFNetworking
//
//  Created by zth on 2024/7/13.
//

#import "PAGSBaseModel.h"
#import "PAGSSDKMacros.h"

NS_ASSUME_NONNULL_BEGIN

@class PAGSCollectInfo,PAGSLikeInfo;

@interface PAGSShortInfos : NSObject

@end

/**
 剧目信息
 */
@interface PAGSShort : PAGSBaseModel

/// 短剧标题
@property (nonatomic, copy) NSString *title;
/// 短剧描述
@property (nonatomic, copy) NSString *desc;
/// 类目名称
@property (nonatomic, copy) NSDictionary *category;
/// 封面图片
@property (nonatomic, copy) NSString *cover_image;
/// 视频过期时间, 单位ms
@property (nonatomic, assign) long play_url_expire_time;
/// 短剧id
@property (nonatomic, assign) long shortplay_id;
/// 国家
@property (nonatomic, copy) NSString *country;
/// 总剧集数
@property (nonatomic, assign) long total;
/// 完结状态, 1完结  2未完结
@property (nonatomic, assign) PAGSShortState progress_state;
/// 字幕语言
@property (nonatomic, copy) NSString *language;
/// 剧集数组
@property (nonatomic, strong) NSArray *episodes;
/// 全局收藏信息, count表示收藏数
@property (nonatomic, strong) PAGSCollectInfo *total_collect_info;
/// 本账户(即媒体传入的userid)收藏信息, count = 1.表示收藏  =0表示未收藏
@property (nonatomic, strong) PAGSCollectInfo *user_collect_info;
/// 标签信息
@property (nonatomic, strong) NSArray *tag_list;



@end

/**
 剧集信息
 */
@interface PAGSShortEpisode : PAGSBaseModel

/// 第index集
@property (nonatomic, assign) long episode_index;
/// 剧集id
@property (nonatomic, assign) long episode_id;
/// 视频云播放id
@property (nonatomic, copy) NSString *Vid;
/// 短剧视频信息list
@property (nonatomic, strong) NSArray *PlayInfoList;
@property (nonatomic, copy) NSString *play_auth_token;
@property (nonatomic, assign) BOOL EnableAdaptive;
@property (nonatomic, assign) long version;
@property (nonatomic, assign) long status;
@property (nonatomic, assign) double Duration;
@property (nonatomic, strong) PAGSLikeInfo *user_like_info;
@property (nonatomic, strong) PAGSLikeInfo *total_like_info;
/// 过期时间戳
@property (nonatomic, assign) long play_url_expire_absolute_time;

@end

/**
 短剧视频信息
 */
@interface PAGSShortPlay : PAGSBaseModel

@property (nonatomic, copy) NSString *FileId;
@property (nonatomic, copy) NSString *Md5;
@property (nonatomic, copy) NSString *MainPlayUrl;
@property (nonatomic, copy) NSString *BackupPlayUrl;
@property (nonatomic, copy) NSString *PlayAuthId;
@property (nonatomic, copy) NSString *PlayAuth;
@property (nonatomic, copy) NSString *Definition;
@property (nonatomic, copy) NSString *FileType;
@property (nonatomic, copy) NSString *Format;
@property (nonatomic, copy) NSString *Codec;
@property (nonatomic, assign) long Bitrate;
@property (nonatomic, assign) long Width;
@property (nonatomic, assign) long Height;
@property (nonatomic, assign) long Size;
@property (nonatomic, assign) double Duration;
@property (nonatomic, copy) NSString *KeyFrameAlignment;
@property (nonatomic, copy) NSString *MainUrlExpire;
@property (nonatomic, copy) NSString *BackupUrlExpire;
@property (nonatomic, copy) NSString *Quality;
@property (nonatomic, copy) NSString *CheckInfo;
@property (nonatomic, copy) NSString *BarrageMaskOffset;

@end

@interface PAGSCollectInfo : PAGSBaseModel

@property (nonatomic, assign) long count;

@end

@interface PAGSLikeInfo : PAGSBaseModel

@property (nonatomic, assign) long count;

@end

@interface PAGSShortTagInfo : PAGSBaseModel

@property (nonatomic, copy) NSString *tag_name;
@property (nonatomic, assign) int tag_id;

@end

@interface PAGSCategoryItem : PAGSBaseModel

@property (nonatomic, assign) NSInteger categoryId;
/// 分类名称
@property (nonatomic, copy) NSString *name;
/// 该分类下预估的短剧数量
@property (nonatomic, assign) NSInteger count;

@end

typedef PAGSShort PAGSShortItem;
typedef PAGSShortEpisode PAGSShortEpisodeItem;
typedef PAGSShortPlay PAGSShortPlayItem;

NS_ASSUME_NONNULL_END
