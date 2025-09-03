//
//  PAGSDetailPageConfig.h
//  PAGShortPlay
//
//  Created by zth on 2024/7/15.
//


#import <Foundation/Foundation.h>
#import "PAGSPPlayBackState.h"

/// 视频播放器控制层视图
typedef NS_ENUM (NSUInteger, PAGSPlayViewPosition) {
    
    PAGSPlayviewpositionTopTitle         = 0,/** 顶部标题*/
    PAGSPlayviewpositionBottomTitle      = 1,/** 底部标题*/
    PAGSPlayviewpositionBottomDesc       = 2 /** 底部描述文字*/
};


NS_ASSUME_NONNULL_BEGIN
/**
 视频播放界面的配置
 */
@interface PAGSDetailPageConfig : NSObject

/// 获取一个空白的配置项对象
+ (PAGSDetailPageConfig *)customConfig;

/// 设置不同位置的文本颜色
- (void)displayTextColor:(UIColor *)color position:(PAGSPlayViewPosition)position;

/// 设置不同位置的文本大小
- (void)displayTextSize:(int)size position:(PAGSPlayViewPosition)position;

/// 设置不同位置的文本字体
- (void)displayTextFont:(UIFont *)font position:(PAGSPlayViewPosition)position;

/// 设置不同位置的可见性  YES 可见
- (void)displayTextVisibility:(BOOL)visibility position:(PAGSPlayViewPosition)position;

/// 隐藏左上角返回按钮和标题，默认显示
- (void)setHideLeftTopCloseAndTitle:(BOOL)hidden clickAction:(void(^)(void))action;

/// 播放页无操作xxx ms后隐藏文字进入沉浸式模式，默认不启用此功能，启用时可指定时间
- (void)setEnableImmersiveMode:(double)time;

/// 只播放一集模式，用于在开发者用多个播放页构造滑动切剧场景时，默认false
- (void)setPlaySingleItem:(BOOL)only;

/// 设置播放进度条离底部距离
- (void)setProgressBarMarginToBottom:(float)margn;

/// 设置起播集的播放集数, 从xx集开始播放，默认从第1集开始
/// @note 当创建PAGSDetailFragment时若已确认了起播集数和起播时间, 要使用本类的setStartPlayIndex: 和setStartPlayAtTimeSeconds: 方法.
- (void)setStartPlayIndex:(int)index;

/// 设置起播集的时间, 单位为秒, 需大于0
/// @note 该配置参数只对首集播放起作用.
- (void)setStartPlayAtTimeSeconds:(long)time;

/// 设置是否自动播放下一集
- (void)setEnableAutoPlayNext:(BOOL)autoNext;

/// 是否显示底部展示视图.
/// @param  isDisplay YES 展示, NO 隐藏, 默认展示
/// @discussion 可以使用这个区域展示banner广告,展示IAP跳转等交互视图
- (void)displayBottomExtraView:(BOOL)isDisplay;

/// 是否显示进度条
/// @param isShow YES 显示, NO 不显示. 默认为显示
/// @note 开发者可隐藏自带的进度跳,然后添加自定义进度条
- (void)displayProgressBar:(BOOL)isShow;

/// 设置视频填充模式
- (void)setVideoScalingMode:(PAGSVideoScalingMode)mode;

/// 设置剧集封面占位图
- (void)setDefaultCoverImage:(UIImage *)defaultCoverImage;



@end

NS_ASSUME_NONNULL_END
