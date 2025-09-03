//
//  UILabel+PAGS.h
//  PAGAdSDK
//
//  Created by bytedance on 2021/11/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/**
 设备各类安全区域
 */
@interface UIDevice (PAGS)

/// 顶部安全区高度
+ (CGFloat)pags_safeDistanceTop;

/// 底部安全区高度
+ (CGFloat)pags_safeDistanceBottom;

/// 顶部状态栏高度（包括安全区）
+ (CGFloat)pags_statusBarHeight;

/// 导航栏高度
+ (CGFloat)pags_navigationBarHeight;

/// 状态栏+导航栏的高度
+ (CGFloat)pags_navigationFullHeight;

/// 底部tabbar高度
+ (CGFloat)pags_tabBarHeight;

/// 底部Tabber栏高度（包括安全区）
+ (CGFloat)pags_tabBarFullHeight;

@end

NS_ASSUME_NONNULL_END
