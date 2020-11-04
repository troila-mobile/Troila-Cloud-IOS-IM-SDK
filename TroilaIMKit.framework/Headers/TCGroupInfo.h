//
//  TCGroupInfo.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/20.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCGroupInfo : NSObject

/*!
 群组ID
 */
@property(nonatomic, copy) NSString *groupId;

/*!
 群组名称
 */
@property(nonatomic, copy) NSString *groupName;

/*!
 群组头像的URL
 */
@property(nonatomic, copy) NSString *portraitUri;

/*!
 创建人
 */
@property(nonatomic, copy) NSString *creator;

/*!
 通知
 */
@property(nonatomic, copy) NSString *notice;

/*!
 群组信息的初始化方法

 @param groupId         群组ID
 @param groupName       群组名称
 @param portraitUri     群组头像的URL
 @return                群组信息对象
 */
+ (instancetype)initWithGroupId:(NSString *)groupId groupName:(NSString *)groupName portraitUri:(NSString *)portraitUri creator:(NSString *)creator notice:(NSString *)notice;


@end

NS_ASSUME_NONNULL_END
