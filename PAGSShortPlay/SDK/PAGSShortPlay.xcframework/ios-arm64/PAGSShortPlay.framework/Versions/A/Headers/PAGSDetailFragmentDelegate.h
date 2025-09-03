//
//  PAGSDetailFragmentDelegate.h
//  PAGSShortPlay
//
//  Created by zth on 2024/7/19.
//

#import <Foundation/Foundation.h>
#import "PAGSPPlayBackState.h"

@protocol PAGSControlProtocol;
@class PAGSDetailFragment,PAGSShort,PAGSPlayBlockResultListener,PAGSPlayerInfo;
NS_ASSUME_NONNULL_BEGIN

@protocol PAGSDetailFragmentDelegate <NSObject>

@required

/// 询问index集是否锁定，锁定后则该集无法自动播放，需要通过showAdIfNeed里完成解锁. 每一集播放时均会询问
///@param shortPlay 剧集model
///@param index 第几集
- (BOOL)detailFragmentShortPlay:(PAGSShort *)shortPlay needBlockAtIndex:(int)index;

///当isNeedBlock指定index集锁定后，在用户切换到该集时，SDK不会播放视频，同时会调用此回调，可在此时展示激励广告或购买等交互，用户达成后调用listener.onShortPlayUnlocked告知SDK可播放该集
///@param shortPlay 剧集model
///@param index 第几集
///@param listener 剧集解锁listener
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay showAdIfNeedAtIndex:(int)index unlockListener:(PAGSPlayBlockResultListener *)listener;

@optional

/// 每一集开始播放时的回调, 可以用来记录播放的历史
/// @param shortPlay 剧目信息
/// @param index 第index集
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay playStartIndex:(int)index;

/// item展示在屏幕时
///@param shortPlay 剧目信息
///@param position 展示视图所在的列表位置
///@param type 在详情页播放的视图类型
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay itemSelectedWithPosition:(NSInteger)position type:(PAGSFragmentItemType)type;

/// 视频播放失败
/// @param shortPlay 剧目信息
/// @param error 播放失败原因
/// @param index 第index集
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay playFailed:(NSError *)error index:(int)index;

/// 视频播放失败
/// @param error 视频播放失败原因
/// @return 返回YES 则需要外部对error时的弹框提示, NO 则由SDK自带的弹框进行提示
- (BOOL)detailFragmentPlayFailed:(NSError *)error;

/// 视频状态发生改变
/// @param shortPlay 剧目信息
/// @param state 播放状态
/// @param index 第index集
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay playStateChanged:(PAGSPlayBackState)state index:(int)index;

/// 视频加载状态发生改变
/// @param shortPlay 剧目信息
/// @param loadState 视频加载状态
/// @param index 第index集
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay loadStateDidChanged:(PAGSLoadState)loadState index:(int)index;

/// 视频进度发生改变
///@param shortPlay 剧目信息
///@param currentPlayTime 当前时间,单位为秒
///@param duration 时长, 单位为秒
///@param index 第index集
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay progressChanged:(long)currentPlayTime duration:(long)duration index:(int)index;

/// 视频播放完成
/// @param shortPlay 剧目信息
/// @param index 第index集
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay playFinishAtIndex:(int)index;

/// 进入沉浸模式
///@param shortPlay 剧目信息
- (void)detailFragmentShortPlayEnterImmersiveMode:(PAGSShort *)shortPlay;

/// 退出沉浸模式
/// @param shortPlay 剧目信息
- (void)detailFragmentShortPlayExitImmersiveMode:(PAGSShort *)shortPlay;

/// 视频信息已就绪
/// @param shortPlay 剧目信息
/// @param indo 视频相关的信息, 作为shortPlay 对剧目中视频信息的补充
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay onVideoInfoFetched:(PAGSPlayerInfo *)info AtIndex:(int)index;

/// 视频播放页销毁, 可以在这里进行广告释放等操作
///@param shortPlay 剧目信息
- (void)detailFragmentShortPlayDestroy:(PAGSShort *)shortPlay;

/// 滑到最顶部和最底部时候回调
///@param position 最顶部：PAGSScrollEventTop  最底部：PAGSScrollEventBottom
- (void)detailFragmentOnOverScroll:(PAGSScrollEvent)position;

@end

/**
 广告相关的协议
 */
@protocol PAGSAdDelegate <NSObject>

@optional
// MARK: - 中插信息流广告
/// 获取信息流广告的插入位置
/// @param shortPlay  剧目信息
/// @discussion [1,3,5]表示在第1集、第3集、第5集后插入信息流广告, 插入位置不能重复,不能超过播放短剧的最大集数
/// @return 返回数字数组
- (NSArray <NSNumber *> *)detailFragmentGetDetailDrawAdPositions:(PAGSShort *)shortPlay;

/// 即将展示信息流广告, 可以在这里进行广告提前加载
/// @param shortPlay  剧目信息
/// @param index 播放第index集后将插入信息流广告,
/// @discussion 1. 该时间节点可以进行提前加载, 但建议在创建播放页前就提前进行广告请求,保证需要展示时有广告view可用 2. 除非有特殊场景,否则无需因index来区分提前加载逻辑
- (void)detailFragmentShortPlay:(PAGSShort *)shortPlay drawAdPrepareWithIndex:(NSInteger)index;

///获取一个信息流广告进行展示
/// @param shortPlay  剧目信息
/// @param index 播放第index集后将插入信息流广告
///@return 返回一个信息流广告, 通过判断广告是否可用决定是否返回, 无可用广告请返回nil.
- (UIView *_Nullable)detailFragmentShortPlay:(PAGSShort *)shortPlay drawAdObtainAdViewWithIndex:(NSInteger)index;

@end

/**
 播放器控制层视图处理相关的协议
 */
@protocol PAGSPlayerControlDelegate <NSObject>

@optional

/// 构建每一集播放器界面的控制层时,接受媒体传入的视图控件.
///@param shortPlay 剧目信息
///@return 返回一组遵循了PAGSControlProtocol协议的视图
///@note 目前支持点赞|收藏|分享视图控件的添加, 无法识别的控件无法被添加.  外部无需持有这些视图控件, 控制层会强持有, 该方法可能被多次调用
///@warning 1. 该方法内不应该执行其他耗时操作,否则会影响控制层的渲染,降低用户交互体验, 2.请在【主线程】返回视图控件
- (NSArray <UIView<PAGSControlProtocol>*>*)detailFragmentOnObtainPlayerControlViews;

///是否拦截播放器界面的点击事件
///@return YES表示拦截该点击事件,SDK不会处理点击事件.  NO表示不拦截, SDK处理点击事件
- (BOOL)detailFragmentOnInterceptClick;


@end

NS_ASSUME_NONNULL_END
