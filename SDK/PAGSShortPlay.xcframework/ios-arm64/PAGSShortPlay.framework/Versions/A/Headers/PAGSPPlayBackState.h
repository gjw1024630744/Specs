//
//  PAGSPPlayBackState.h
//  Pods
//
//  Created by zth on 2024/7/19.
//

#ifndef PAGSPPlayBackState_h
#define PAGSPPlayBackState_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PAGSPlayerViewModel;
/// 视频播放状态
typedef NS_ENUM (NSUInteger, PAGSPlayBackState) {
    
    /// 默认状态
    PAGSPlayBackStateDefault = 0,
    /// 首帧展示
    PAGSPlayBackStateFirstDisplay,
    ///已停止 
    PAGSPlayBackStateStopped,
    ///播放中
    PAGSPlayBackStatePlaying,
    ///暂停
    PAGSPlayBackStatePaused,
    ///播放错误
    PAGSPlayBackStateError
};

/// 视频加载状态
typedef NS_ENUM(NSUInteger, PAGSLoadState) {
    PAGSLoadStateUnknown        = 0,
    PAGSLoadStatePlayable,
    PAGSLoadStateStalled,
    PAGSLoadStateError,
};

/// 视频填充模式
typedef NS_ENUM(NSInteger, PAGSVideoScalingMode) {
    PAGSVideoScalingModeNone,       // No scaling
    PAGSVideoScalingModeAspectFit,  // Uniform scale until one dimension fits
    PAGSVideoScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    PAGSVideoScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};

typedef NS_ENUM(NSInteger, PAGS_PLAYRESOLUTIONTYPE) {
    ///未知
    PAGS_PLAYRESOLUTIONTYPE_UNKNOWN = 0,
    ///标清  360P
    PAGS_PLAYRESOLUTIONTYPE_SD = 1,
    ///高清  480P
    PAGS_PLAYRESOLUTIONTYPE_HD = 2,
    ///超清  720P
    PAGS_PLAYRESOLUTIONTYPE_FULLHD = 3,
    ///1080P
    PAGS_PLAYRESOLUTIONTYPE_1080P = 4,
    ///2K
    PAGS_PLAYRESOLUTIONTYPE_2K = 5,
    ///4K
    PAGS_PLAYRESOLUTIONTYPE_4K = 6,
    ///底层播放引擎自动处理
    PAGS_PLAYRESOLUTIONTYPE_Auto = 99,
};

/// 滑动事件
typedef NS_ENUM(NSInteger, PAGSScrollEvent) {
    ///默认值
    PAGSScrollEventNone = 0,
    /// 滑动到顶部
    PAGSScrollEventTop = 1,
    ///滑动到底部
    PAGSScrollEventBottom = 2
};

static inline NSString * pags_get_resolution_character(PAGS_PLAYRESOLUTIONTYPE resolution) {
    
    NSString *resolutionCharacter = @"unknown";
    switch (resolution) {
        case PAGS_PLAYRESOLUTIONTYPE_SD:
            resolutionCharacter = @"360p";
            break;
        case PAGS_PLAYRESOLUTIONTYPE_HD:
            resolutionCharacter = @"480p";
            break;
        case PAGS_PLAYRESOLUTIONTYPE_FULLHD:
            resolutionCharacter = @"720p";
            break;
        case PAGS_PLAYRESOLUTIONTYPE_1080P:
            resolutionCharacter = @"1080p";
            break;
        case PAGS_PLAYRESOLUTIONTYPE_2K:
            resolutionCharacter = @"2k";
            break;
        case PAGS_PLAYRESOLUTIONTYPE_4K:
            resolutionCharacter = @"4k";
            break;
        case PAGS_PLAYRESOLUTIONTYPE_Auto:
            resolutionCharacter = @"auto";
            break;
        case PAGS_PLAYRESOLUTIONTYPE_UNKNOWN:
            resolutionCharacter = @"unknown";
            break;
        default:
            break;
    }
    return resolutionCharacter;
}



#endif /* PAGSPPlayBackState_h */
