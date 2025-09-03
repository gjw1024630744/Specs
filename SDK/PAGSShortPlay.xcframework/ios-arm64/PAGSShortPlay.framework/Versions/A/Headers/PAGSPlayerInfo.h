//
//  PAGSPlayerInfo.h
//  PAGSShortPlay
//
//  Created by zth on 2024/7/30.
//

#import "PAGSBaseModel.h"
#import "PAGSPPlayBackState.h"
NS_ASSUME_NONNULL_BEGIN
/**
 承接短剧信息类
 */
@interface PAGSPlayerInfo : PAGSBaseModel

@property (nonatomic, assign) PAGS_PLAYRESOLUTIONTYPE currentResolution;
@property (nonatomic, strong) NSArray <NSNumber *>  *supportResolutions;

@end

NS_ASSUME_NONNULL_END
