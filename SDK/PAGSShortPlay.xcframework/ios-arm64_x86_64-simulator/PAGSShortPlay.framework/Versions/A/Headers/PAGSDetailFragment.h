//
//  PAGSDetailFragment.h
//  PAGShortPlay
//
//  Created by zth on 2024/7/15.
//

#import <Foundation/Foundation.h>
#import "PAGSPPlayBackState.h"
#import "PAGSSDKMacros.h"

@class PAGSShort,PAGSDetailPageConfig;
@protocol PAGSDetailFragmentDelegate, PAGSPPlayerViewProtocol,PAGSAdDelegate,PAGSPlayerControlDelegate;
NS_ASSUME_NONNULL_BEGIN
/**
 视频容器
 */
@interface PAGSDetailFragment : NSObject


@property (nonatomic, strong,readonly) PAGSShort *shortPlay;

- (instancetype)initWithShort:(PAGSShort *)shortPlay pageConfig:(PAGSDetailPageConfig *)pageConfig delegate:(id<PAGSDetailFragmentDelegate,PAGSAdDelegate>)delegate NS_DESIGNATED_INITIALIZER;

- (instancetype)init __attribute__((unavailable));

/// 视频播放
- (UIView <PAGSPPlayerViewProtocol> *)playView;

/// 视频播放区域的bounds
- (CGRect)playerContentBounds;

/// 设置为当前正在展示的Fragment, 默认为NO;
/// @note 仅在单集播放模式下生效.
/// @note 配合preLoadVideo使用,当收到preload pool达到满载, 若设置了currentFragment,不会销毁currentFragment的内部引擎.  否则会销毁,在执行play时重新创建一次,有可能导致起播耗时增加
- (void)setCurrentFragment:(BOOL)isCurrent;

/// 开始播放
- (void)startPlay;

/// 停止播放
- (void)stopPlay;

/// 暂定播放
- (void)pausePlay;

/// 播放指定剧集
/// @param index 要播放的集数
- (void)startPlayIndex:(int)index;

/// 指定当前剧集的播放位置  单位为秒,
/// @param playbackTime 指定的播放位置, 单位为秒,  当<=0 或者>当前剧集duration时长时会失效.
/// @note 调用该方法, 当视频处于播放或暂定状态时,不会改变播放状态,仅改变播放进度.  当非播放和暂停状态时, 内部会自动播放.  我们建议使用startPlayIndex:timeSeconds:方法
/// @warning 若同时使用该方法和PAGSDetailPageConfig的setStartPlayAtTimeSeconds: 方法.  PAGSDetailPageConfig的设置会失效
- (void)setCurrentPlayTimeSeconds:(long)playbackTime;

///播放指定剧集并设置播放位置
///@param index 要播放的集数
///@param playbackTime 指定的播放位置, 单位为秒,  当<=0  或者 >当前剧集duration时长时会失效.
/// @warning 若同时使用该方法和PAGSDetailPageConfig的setStartPlayAtTimeSeconds: 方法.  PAGSDetailPageConfig的设置会失效
- (void)startPlayIndex:(int)index timeSeconds:(long)playbackTime;

/// 预缓存
/// @warning 在调用startPlay前调用preLoadVideo, 反之则视频直接进行播放 不进行预加载.
- (void)preLoadVideo;

/// 视频销毁,释放资源
/// @warning 销毁后需要重新创建
- (void)distroy;

/// 设置分辨率
/// @note 生效范围: app维度
- (void)setResolution:(PAGS_PLAYRESOLUTIONTYPE)resolution;

/// 手动进入沉浸模式
- (void)requestStartImmersiveMode;

/// 手动退出沉浸模式
- (void)requestStopImmersiveMode;

/// 设置视频播放页底部区域视图
/// @param view  要被添加的视图
/// @param type 视图类型
- (void)setBottomExtraViewContent:(UIView *)view type:(PAGSBottomViewType)type;

/// 设置播放器控制层布局delegate
/// @note 若需要自定义控制层视图 则必须设置该Delegate
- (void)setControlViewDelegate:(id<PAGSPlayerControlDelegate>)controlViewDelegate;

/// 设置视频播放速度
/// @param speed 设置播放速度, 取值范围(0,3] 建议取值 0.75x | 1x | 1.25x | 1.5x | 2x | 3x
/// @note 生效范围:剧维度
- (void)setVideoSpeed:(CGFloat)speed;

///设置静音
///@param muted YES为静音, NO为非静音
///@note 生效范围:剧维度
- (void)setMuted:(BOOL)muted;

@end

NS_ASSUME_NONNULL_END
