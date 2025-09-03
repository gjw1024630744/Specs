//
//  PAGSRevenueInfo.h
//  PAGSShortPlay
//
//  Created by zth on 2024/8/13.
//

#import <Foundation/Foundation.h>
#import "PAGSSDKMacros.h"

NS_ASSUME_NONNULL_BEGIN
/**
 广告收入相关信息
 */
@interface PAGSRevenueInfo : NSObject

/// 解锁场景
@property (nonatomic, assign, readonly) PAGSRevenueType revenueType;
/// 货币类型(字符串)
@property (nonatomic, copy, readonly) NSString *currency;
/// 货币类型
@property (nonatomic, assign, readonly) PAGSCurrencyType currencyType;
/// adn name
@property (nonatomic, copy)  NSString *adnName;

@property (nonatomic, assign) CGFloat revenue;
/// 广告类型
@property (nonatomic, assign) PAGSAdFormat adFormat;
/// 是否和广告解锁有关
@property (nonatomic, assign) BOOL aboutUnlock;




- (instancetype)init __attribute__((unavailable));

- (instancetype)initWithRevenueType:(PAGSRevenueType)revenueType currencyType:(PAGSCurrencyType)currencyType NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
