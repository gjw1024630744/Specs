//
//  UIView+UIView_BUToast.h
//  Pods
//
//  Created by yujie.10 on 2021/8/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,PAGSToastPosition) {
    PAGSToastPosition_Center,
    PAGSToastPosition_Top,
    PAGSToastPosition_Bottom
};

@interface PAGSToastConfig : NSObject

/// default position:center
@property (nonatomic, assign) PAGSToastPosition postion;

/// default font : systemFont 13pt
@property (nonatomic, strong) UIFont *textFont;

/// default : white
@property (nonatomic, strong) UIColor *textColor;

/// default: #292929
@property (nonatomic, strong) UIColor *backgroundColor;

/// default: 3s
@property (nonatomic, assign) float duration;

/// default: 2pt
@property (nonatomic, assign) CGFloat cornerRadius;

/// content insets, default: top 11 / left 20 / bottom 11 / right 11
@property (nonatomic, assign) UIEdgeInsets insets;

/// message to show
@property (nonatomic, copy) NSString *message;

/// text alignment, default:center alignment
@property (nonatomic, assign) NSTextAlignment alignment;

/// the size of super view which would show toast
@property (nonatomic, assign) CGSize superViewSize;

///The center of toast view, the position would be ignored;
@property (nonatomic, assign) CGPoint location;
@end


@interface PAGSToastView : UIView
/// Init instance with config
/// @param config config
- (instancetype)initWithConfig:(PAGSToastConfig *)config;
@end

@interface UIView (PAGToast)
/// Show toast message (position:center  duration:3s)
/// @param message text
- (void)pags_showToast:(NSString *)message;

/// Show Toast with custom config
/// @param config PAGToastConfig
- (void)pags_showToastWith:(PAGSToastConfig *)config;
@end

NS_ASSUME_NONNULL_END
