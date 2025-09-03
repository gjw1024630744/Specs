//
//  PAGSControlProtocol.h
//  PAGSShortPlay
//
//  Created by zth on 2024/9/19.
//

#import <Foundation/Foundation.h>
#import "PAGSSDKMacros.h"

@class PAGSShort,PAGSLikeInfo,PAGSCollectInfo;
NS_ASSUME_NONNULL_BEGIN
/**
 添加到播放器控制层的视图控件协议(基类)
 */
@protocol PAGSControlProtocol <NSObject>

@required
/// 控件类型
- (PAGSControlType)controlViewType;

@optional

@end

/**
 点击控件协议
 */
@protocol PAGSControlClickProtocol <PAGSControlProtocol>

@optional

///视图被点击
///@param shortPlay 剧目的信息
///@param index 该剧目的第index集
///@return PAGSControlStatus该视图控件被点击后的状态. 需要正确返回,将影响到下一次调用"setCurrentStatus:withShortPlay:index:"
- (PAGSControlStatus)controlClickWithShortPlay:(PAGSShort *)shortPlay index:(int)index;

@optional

@end

@protocol PAGSControlLoadingProtocol <PAGSControlProtocol>

///开始loading
- (void)startAnimating;
///停止loading
- (void)stopAnimating;

@end

/**
 点赞控件协议
 */
@protocol PAGSControlLikeProtocol <PAGSControlClickProtocol>

/// 设置视图的当前状态
/// @param status 视图控件当前的状态
/// @param shortPlay 剧目的信息
/// @param index 该剧目的第index集
/// @param info 点赞信息类
/// @note 开发者可以在该接口实现视图控件根据不同的status进行状态改变的逻辑. SDK 会在每次构建播放器控制层时调用一次该方法.
- (void)setCurrentStatus:(PAGSControlStatus)status withShortPlay:(PAGSShort *)shortPlay index:(int)index info:(PAGSLikeInfo *)info;

@end

/**
 收藏控件协议
 */
@protocol PAGSControlCollectProtocol <PAGSControlClickProtocol>

/// 设置视图的当前状态
/// @param status 视图控件当前的状态
/// @param shortPlay 剧目的信息
/// @param index 该剧目的第index集
/// @param info 收藏信息类
/// @note 开发者可以在该接口实现视图控件根据不同的status进行状态改变的逻辑. SDK 会在每次构建播放器控制层时调用一次该方法.
- (void)setCurrentStatus:(PAGSControlStatus)status withShortPlay:(PAGSShort *)shortPlay index:(int)index info:(PAGSCollectInfo *)info;

@end

/**
 进度条控件协议
 */
@protocol PAGSControlProgressProtocol <PAGSControlProtocol>

@required

/// 进度条更新
/// @param playTime 当前播放位置, 单位秒
/// @param duration 播放总时长, 单位秒
/// @param bufferProgress 缓冲进度,取值范围(0,100)
/// @param shortPlay 剧目的信息
/// @param index  第几集
- (void)updateProgress:(CGFloat)playTime duration:(CGFloat)duration buffer:(CGFloat)bufferProgress shortPlay:(PAGSShort *)shortPlay index:(int)index;

/// 同步视频播放状态
/// @param isPaused  视频是否处于暂停状态,  YES 处于暂停装该, NO 处于播放状态
/// @note 该方法在视频暂停和播放时会被调用, 通过该方法实现在暂停时 进度条样式该表的交互.
- (void)setVideoPaused:(BOOL)isPaused;

/// 设置视频播放时长
/// @note 通过该方法可以设置初始态的播放时长, 有可能被调用两次.
- (void)setPlayerDuration:(CGFloat)duration;

@end

/**
 自定义控件协议
 */
@protocol PAGSControlCustomProtocol <PAGSControlProtocol>

/// 将剧目信息传递给开发者
/// @param shortPlay 剧目的信息
/// @param index 第几集
- (void)setShortPlay:(PAGSShort *)shortPlay index:(int)index;

@end


NS_ASSUME_NONNULL_END
