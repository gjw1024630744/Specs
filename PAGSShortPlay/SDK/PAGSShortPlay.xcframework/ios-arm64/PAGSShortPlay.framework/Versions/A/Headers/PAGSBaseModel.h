//
//  PAGSBaseModel.h
//  PAGShortPlay
//
//  Created by zth on 2024/7/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 项目 Model基类.
 @note 请注意,基类的方法请加前缀, 举一个badecase
 @code
 PAGSBaseModel 有一个方法为- (NSData *)data; 其子类PAGSShortList 有一个表示剧集数组的data(服务端返回字段)
 此时出现bad case:PAGSShortList实例对象调用.data 时获取的是数组.
 同理,当其他父类定义属性时,请注意避开一些公共属性命名.
 @endcode
 */
@interface PAGSBaseModel : NSObject<NSCoding, NSCopying>


+ (instancetype)pags_modelWithJSON:(id)json;

- (id)pags_modelToJSONObject;

- (NSString *)pags_modelToJSONString;

+ (instancetype)pags_modelWithData:(NSData *)data;

- (NSData *)pags_data;

/// obj 的md5值
- (NSString *)pags_md5;



@end

NS_ASSUME_NONNULL_END
