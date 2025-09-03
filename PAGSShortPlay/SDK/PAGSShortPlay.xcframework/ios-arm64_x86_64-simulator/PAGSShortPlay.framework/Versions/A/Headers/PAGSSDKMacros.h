//
//  PAGSSDKMacros.h
//  PAGSShortPlay
//
//  Created by zth on 2024/7/29.
//

#ifndef PAGSSDKMacros_h
#define PAGSSDKMacros_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM (NSUInteger, PAGSControlStatus) {
    ///未知
    PAGSControlStatusUnknown = 0,
    /// 正常
    PAGSControlStatusNormal = 1,
    /// 选中
    PAGSControlStatusSelected = 2
};

///播放器控制层视图控件类型
typedef NS_ENUM (NSUInteger, PAGSControlType) {
    
    /// 未知
    PAGSControlTypeUnknown  = 0,
    /// 点赞
    PAGSControlTypeLike     = 1,
    /// 收藏
    PAGSControlTypeCollect  = 2,
    /// 分享
    PAGSControlTypeShare    = 3,
    /// loading view
    PAGSControlTypeLoading    = 4,
    /// 播放器错误提示视图
    PAGSControlTypeErrorPage    = 5,
    /// 自定义视图
    PAGSControlTypeCustom    = 99,
};

///播放页Cell类型
typedef NS_ENUM (NSUInteger, PAGSFragmentItemType) {
    
    /// 未知
    PAGSFragmentItemTypeUnknown   = 0,
    /// 播放器界面
    PAGSFragmentItemTypeVideo     = 1,
    /// 信息流广告
    PAGSFragmentItemTypeDrawAd    = 2
};

/// 播放页底部区域视图类型
typedef NS_ENUM (NSUInteger, PAGSBottomViewType) {
    /// 未知
    PAGSBottomViewTypeUnknown = 0,
    ///广告
    PAGSBottomViewTypeAd      = 1,
    ///定制化视图
    PAGSBottomViewTypeCustom  = 2
};

/// 短剧完结状态
typedef NS_ENUM (NSUInteger, PAGSShortState) {
    
    PAGS_SHORTSTATE_UNKNOWN = 0,/** 未知*/
    PAGS_SHORTSTATE_END     = 1,/** 完结*/
    PAGS_SHORTSTATE_NOT_END = 2/** 未完结*/
};

// 业务错误码
typedef NS_ENUM(NSInteger, PAGSErrorCode) {
    
    /// 通用错误，msg里描述具体错误信息.
    PAGSErrorCodeCommonError            = -1,
    /// sdk 还未初始化成功
    PAGSErrorCodeNotInitialized         = -2,
    /// 合规设置未通过
    PAGSErrorCodeNotEligibleAudience    = -3,
    /// sdk初始化 失败
    PAGSErrorCodeInitializedFail        = -4,
    /// 检查AppID和securityKey是否正确
    PAGSErrorCodeInvalidAppID           = 10003,
    /// 当前不是合规地区，无法播放
    PAGSErrorCodeCurrentlyNotAvailable  = 10011,
    /// 未命中有效数据
    PAGSErrorCodeValidData              = 10013,

};

/// 当前地区是否可支持
typedef NS_ENUM (NSUInteger, PAGSAvailable) {
    /** 未知*/
    PAGSAvailableUnknown    = 0,
    /** 支持*/
    PAGSAvailableSupport    = 1,
    /** 不支持*/
    PAGSAvailableNotSupport = 2,
    /** 未知错误*/
    PAGSAvailableError      = 3,
};

/// 广告收入场景
typedef NS_ENUM (NSUInteger, PAGSRevenueType) {
    /** 未知*/
    PAGSRevenueTypeUnknown     = 0,
    /** IAP模式*/
    PAGSRevenueTypeIAP         = 1,
    /** IAA模式*/
    PAGSRevenueTypeIAA         = 2,
};

/// 广告类型
typedef NS_ENUM (NSUInteger, PAGSAdFormat) {
    /** 未知*/
    PAGSAdFormatUnkwown              = 0,
    /** BANNER*/
    PAGSAdFormatBanner               = 1,
    /** INTERSTITIAL_IMAGE*/
    PAGSAdFormatInterstitialImage    = 2,
    /** APP_OPEN*/
    PAGSAdFormatAppOpen              = 3,
    /** PRELOAD_APP_OPEN*/
    PAGSAdFormatPreloadAppOpen       = 4,
    /** PRELOAD_APP_OPEN*/
    PAGSAdFormatNative               = 5,
    /** IN_STREAM_VIDEO*/
    PAGSAdFormatInStreamVideo        = 6,
    /** REWARD_VIDEO*/
    PAGSAdformatRewardVideo          = 7,
    /** INTERSTITIAL_VIDEO*/
    PAGSAdformatInterstitialVideo    = 8,
    /** DRAW*/
    PAGSAdformatDraw                 = 9,
    /** MIXED*/
    PAGSAdformatMixed                = 10,
    /** REWARD_INTERSTITIAL*/
    PAGSAdformatRewardInterstitial   = 11,
};

/// 货币类型
typedef NS_ENUM (NSUInteger, PAGSCurrencyType) {
    ///未知
    PAGSCurrencytypeUnknown     = 0,
    ///USD
    PAGSCurrencytypeUsd         = 1,
    ///VND
    PAGSCurrencytypeVnd         = 2,
    ///CNY
    PAGSCurrencytypeCny         = 3,
    /// THP
    PAGSCurrencytypeThp         = 4,
    ///RM
    PAGSCurrencytypeRm          = 5,
    /// IDR
    PAGSCurrencytypeIdr         = 6,
    /// SGD
    PAGSCurrencytypeSgd         = 7,
};

/// 获取当前设备的系统语言
/// @note 获取手机系统当前语言,请调用该方法.
static inline NSString * pags_get_current_language() {
    
    NSString *currentLanguage = [[NSLocale preferredLanguages] firstObject];
    NSLocale *locale = [NSLocale localeWithLocaleIdentifier:currentLanguage];
    // 语言
    NSString *primaryLanguage = [locale objectForKey:NSLocaleLanguageCode];
    // 地区
    NSString *LocaleScriptCode = [locale objectForKey:NSLocaleScriptCode];
    NSString *result = nil;
    if(LocaleScriptCode.length > 0) {
        result = [NSString stringWithFormat:@"%@_%@",primaryLanguage,LocaleScriptCode];
    } else {
        result = primaryLanguage;
    }
    return [result lowercaseString];
}

// MARK: - 语言相关

typedef NSString * PAGSLocalLanguageType;

/// 英语
static  PAGSLocalLanguageType const PAGSLocalEnglishLanguage = @"en";
/// 简体中文
static  PAGSLocalLanguageType const PAGSLocalSimplifiedZHLanguage = @"zh_hans";
/// 繁体中文
static  PAGSLocalLanguageType const PAGSLocalZHHantLanguage = @"zh_hant";
/// 越南语
static  PAGSLocalLanguageType const PAGLocalVietnameseLanguage = @"vi";
/// 泰语
static  PAGSLocalLanguageType const PAGLocalThaiLanguage = @"th";
/// 印尼语
static  PAGSLocalLanguageType const PAGLocalIndonesianLanguage = @"in";
/// 日语
static  PAGSLocalLanguageType const PAGLocalJapanLanguage = @"ja";
/// 韩语
static  PAGSLocalLanguageType const PAGLocalKoLanguage = @"ko";
/// 葡萄牙语
static  PAGSLocalLanguageType const PAGLocalPortugalLanguage = @"pt";
/// 西班牙语
static  PAGSLocalLanguageType const PAGLocalSpanishLanguage = @"es";

// MARK: - 通知相关

/// preload pool 达到满负载的通知
static NSString *const PAGSNotificationPreloadPoolReachFullLoad = @"pags_preloadpool_full_load";

// MARK: - 剧目标签相关

typedef NSInteger PAGSShortTag;

///收藏榜
static PAGSShortTag const PAGSShortTagCollect = 4;




#endif /* PAGSSDKMacros_h */
