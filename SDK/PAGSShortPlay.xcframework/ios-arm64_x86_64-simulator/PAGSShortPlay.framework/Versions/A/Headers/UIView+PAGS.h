//
//  UIView+Additions.h
//  BUAdSDK
//
//  Created by bytedance_yuanhuan on 2018/3/15.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN



@interface UIView (PAGS_FrameAdditions)

@property (nonatomic) float pags_x;
@property (nonatomic) float pags_y;
@property (nonatomic) float pags_width;
@property (nonatomic) float pags_height;
@property (nonatomic, getter = pags_y,setter = setPags_y:) float pags_top;
@property (nonatomic, getter = pags_x,setter = setPags_x:) float pags_left;
@property (nonatomic) float pags_bottom;
@property (nonatomic) float pags_right;
@property (nonatomic) CGSize pags_size;
@property (nonatomic) CGPoint pags_origin;
@property (nonatomic) CGFloat pags_centerX;
@property (nonatomic) CGFloat pags_centerY;

- (UIViewController *)pags_viewController;
@end

@interface UIView (PAGS_Gesture)

@property (nonatomic, strong, nullable) UITapGestureRecognizer *pags_tgr;
// 会移除旧的手势
- (void)pags_addGestureRecognizerWithTarget:(id)target action:(SEL)action;
- (void)pags_removeGestureRecognizer;
@end

@interface UIView (PAGS_FindFirstResponder)
- (UIView *)pags_findViewThatIsFirstResponder;
@end

@interface UIView (PAGS_SafeArea)
- (UIEdgeInsets)pags_safeAreaInsets;

+ (UIEdgeInsets)pags_defaultAreaInsets;

@end
NS_ASSUME_NONNULL_END
