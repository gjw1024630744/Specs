//
//  PAGSPSDK.h
//  PAGShortPlay
//
//  Created by zth on 2024/3/25.
//

#import <Foundation/Foundation.h>
#import "PAGSSDKMacros.h"


@class PAGSSDKConfig,PAGSShort,PAGSDetailPageConfig,PAGSDetailFragment,PAGSRevenueInfo,PAGSCategoryItem;
@protocol PAGSDetailFragmentDelegate,PAGSAdDelegate;

NS_ASSUME_NONNULL_BEGIN
/**
 短剧sdk
 */
@interface PAGSSDK : NSObject

/// 版本号
+ (NSString *)version;

/// sdk初始化
/// @param config  初始化配置
/// @param completionHandler 初始化结果回调
+ (void)startWithConfig:(PAGSSDKConfig *)config completionHandler:(nullable void (^)(BOOL success, NSError * _Nullable error))completionHandler;

/// 设置当前用户是否适合观看短剧内容
+ (void)setEligibleAudience:(BOOL)ea;

/// 检查当前地区是否支持播放
+ (void)checkPlayStatusCompletionHandler:(void(^)(PAGSAvailable result, NSError * _Nullable error))completionHandler;

/// 设置短剧内容语言, 若该方法不调用,则默认使用系统语言
/// @param language ,获取设备本地语言请调用pags_get_current_language()
+ (void)setContentLanguage:(NSString *)language __attribute__((deprecated("This method is deprecated. Please use setContentLanguages: instead.")));

/// 设置短剧内容语言,若该方法不调用,则默认使用系统语言
/// @param languages 内容语言数组,获取设备本地语言请调用pags_get_current_language()
/// @warning setContentLanguage: 和本方法会互相覆盖, 建议不再使用setContentLanguage:方法
+ (void)setContentLanguages:(NSArray <NSString *>*)languages;

///请求短剧列表
///@param index 页索引, 从1开始
///@param count 请求数量
///@param completionHandler 结果回调
+ (void)requestFeedListWithIndex:(int)index count:(int)count completionHandler:(void(^)(NSArray <PAGSShort *> * _Nullable list,BOOL haseMore,NSError * _Nullable error))completionHandler;

///请求新剧列表
///@param index 页索引, 从1开始
///@param count 请求数量
///@param completionHandler 结果回调
+ (void)requestNewFeedListWithIndex:(int)index count:(int)count completionHandler:(void(^)(NSArray <PAGSShort *> * _Nullable list,BOOL haseMore,NSError * _Nullable error))completionHandler;


/// 请求热门短剧列表
///@param index 页索引, 从1开始
///@param count 请求数量
///@param completionHandler 结果回调
+ (void)requestPopularDrama:(int)index count:(int)count completionHandler:(void(^)(NSArray <PAGSShort *> * _Nullable list,BOOL haseMore,NSError * _Nullable error))completionHandler;

/// 搜索短剧
///@param index 页索引, 从1开始
///@param count 请求数量
///@param keyword 搜索关键词
///@param isFuzzy 是否模糊搜索,  YES: 模糊搜索 NO:精准搜索
///@param completionHandler 结果回调
+ (void)requestSearchDrama:(int)index count:(int)count keyWord:(NSString *)keyword isFuzzy:(BOOL)isFuzzy completionHandler:(void(^)(NSArray <PAGSShort *> * _Nullable list,BOOL haseMore,NSError * _Nullable error))completionHandler;

/// 获取指定分类或短剧的列表
///@param index 页索引, 从1开始
///@param count 请求数量
///@param categoryIds 分类id集合,无则传空数组
///@param shortplayIds 短剧id集合,无则传空数组
///@param completionHandler 结果回调
+ (void)requestFeedListWithIndex:(int)index count:(int)count categoryIds:(NSArray *)categoryIds shortplayIds:(NSArray *)shortplayIds completionHandler:(void(^)(NSArray <PAGSShort *> * _Nullable list,BOOL haseMore,NSError * _Nullable error))completionHandler;

/// 获取指定标签的列表
///@param index 页索引, 从1开始
///@param count 请求数量
///@param tag 标签,具体值请查看PAGSSDKMacros.h
///@param completionHandler 结果回调
+ (void)requestDramaWithTag:(PAGSShortTag)tag index:(int)index count:(int)count completionHandler:(void(^)(NSArray <PAGSShort *> * _Nullable list,BOOL haseMore,NSError * _Nullable error))completionHandler;

/// 创建视频容器
/// @param shortPlay 剧目信息
/// @param pageConfig 播放页视图配置类
/// @param delegate delegate
/// @param error 构建过程中的报错信息, error不为空时,返回nil
/// @return 视频容器实例对象
+ (PAGSDetailFragment *)createDetailFragmentWithShort:(PAGSShort *)shortPlay pageConfig:(PAGSDetailPageConfig *)pageConfig delegate:(id<PAGSDetailFragmentDelegate, PAGSAdDelegate>)delegate;

/// 获取短剧分类列表, 支持多语言
/// @param language 语种
/// @param completionHandler 结果回调,其中PAGSCategoryItem为一个分类信息
+ (void)getCategoryListWithLanguage:(NSString *)language completionHandler:(void(^)(NSArray <PAGSCategoryItem *> * _Nullable categoryList, NSString *language, NSError * _Nullable error))completionHandler;

/// 设置收藏
///@param isCollected YES-收藏，NO-取消收藏
///@param shortplayId 剧目ID
///@param completionHandler 设置成功失败的回调
+ (void)setCollected:(BOOL)isCollected withShortplayId:(long)shortplayId completionHandler:(void(^)(BOOL success, NSError * _Nullable error))handler;

/// 设置喜欢
///@param isLiked       是否喜欢
///@param shortPlayId   剧目ID
///@param episode       集数
///@param resultListener       设置成功失败的回调
+ (void)setLiked:(BOOL)isLiked withShortplayId:(long )shortplayId episodeId:(long)episodeId  completionHandler:(void(^)(BOOL success, NSError * _Nullable error))handler;

/// sdk 是否初始化成功
+ (BOOL)hasInitialized;

/// 上送广告信息
+ (void)reportRevenueInfo:(PAGSRevenueInfo *)revenueInfo;

/// 清除sdk缓存
+ (void)clearLocalCache;

@end

NS_ASSUME_NONNULL_END
