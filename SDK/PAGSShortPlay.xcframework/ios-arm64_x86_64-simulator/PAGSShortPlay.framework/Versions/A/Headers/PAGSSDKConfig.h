//
//  PAGSPSDKConfig.h
//  PAGShortPlay
//
//  Created by zth on 2024/3/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 短剧sdk 配置类
 */
@interface PAGSSDKConfig : NSObject

/// 应用id
@property (nonatomic, copy, readonly) NSString  *appId;
/// vid (播放器使用)
@property (nonatomic, copy, readonly) NSString  *vodAppId;
/// 播放器鉴权id
@property (nonatomic, copy, readonly) NSString  *securityKey;
/// 鉴权文件路径(播放器使用)
@property (nonatomic, copy,readonly) NSString  *licenseAssertPath;
/// bug模式 默认为NO
@property (nonatomic, assign, readonly) BOOL debug;
/// 用户账户的userid, 默认为空
@property (nonatomic, copy, readonly) NSString *userId;
/// 网络请求超时时长
@property (nonatomic, assign, readonly) NSUInteger requestTimeOut;



/// 构建方法
- (instancetype)initWithAppid:(NSString *)appid  vodAppId:(NSString *)vodAppId securityKey:(NSString *)securityKey licenseAssertPath:(NSString *)licenseAssertPath  NS_DESIGNATED_INITIALIZER;

- (instancetype)init __attribute__((unavailable));

/// 设置为debug模式
- (void)setSDKDebug:(BOOL)debug;

/// 设置媒体的user id
/// @Warning 请不要输入空字符串 或 空格
- (void)setAppUserId:(NSString *)userId;

/// 设置sdk的网络请求超时
- (void)setAppRequestTimeOut:(NSUInteger)timeOut;


@end

NS_ASSUME_NONNULL_END
