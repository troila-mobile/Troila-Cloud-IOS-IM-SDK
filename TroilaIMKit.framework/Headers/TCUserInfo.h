//
//  TCUserInfo.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/17.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCUserInfo : NSObject

/*!
 用户ID
 */
@property(nonatomic, copy) NSString *userId;

/*!
 用户名称
 */
@property(nonatomic, copy) NSString *name;

/*!
 用户头像的URL
 */
@property(nonatomic, copy) NSString *portraitUri;

/**
 用户信息附加字段
 */
@property(nonatomic, copy) NSString *extra;

/*!
 用户信息的初始化方法

 @param userId      用户ID
 @param username    用户名称
 @param portrait    用户头像的URL
 @return            用户信息对象
 */
+ (instancetype)initWithUserId:(NSString *)userId name:(NSString *)username portrait:(NSString *)portrait;


@end

NS_ASSUME_NONNULL_END
