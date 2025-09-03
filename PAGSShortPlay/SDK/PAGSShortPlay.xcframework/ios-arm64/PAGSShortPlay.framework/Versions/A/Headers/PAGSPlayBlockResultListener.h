//
//  PAGSPlayBlockResultListener.h
//  PAGSShortPlay
//
//  Created by zth on 2024/7/29.
//

#import "PAGSBaseViewModel.h"

NS_ASSUME_NONNULL_BEGIN
/**
 负责解锁逻辑
 */
@interface PAGSPlayBlockResultListener : PAGSBaseViewModel

- (void)onShortPlayUnlocked;

@end

NS_ASSUME_NONNULL_END
