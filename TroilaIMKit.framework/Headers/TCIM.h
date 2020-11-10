//
//  TCIM.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/13.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCUserInfo.h"
#import "TCGroupInfo.h"
//#import "TCCache.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 用户信息提供者

 @discussion SDK需要通过您实现的用户信息提供者，获取用户信息并显示。
 */
@protocol TCIMUserInfoDataSource <NSObject>

/*!
 获取用户信息

 @param userId      用户ID
 @param completion  获取用户信息完成之后需要执行的Block [userInfo:该用户ID对应的用户信息]

 @discussion SDK通过此方法获取用户信息并显示，请在completion中返回该用户ID对应的用户信息。
 在您设置了用户信息提供者之后，SDK在需要显示用户信息的时候，会调用此方法，向您请求用户信息用于显示。
 */
- (void)getUserInfoWithUserId:(NSString *)userId completion:(void (^)(TCUserInfo *userInfo))completion;

@end


/*!
 群组信息提供者

 @discussion SDK需要通过您实现的群组信息提供者，获取群组信息并显示。
 */
@protocol TCIMGroupInfoDataSource <NSObject>

/*!
 获取群组信息

 @param groupId     群组ID
 @param completion  获取群组信息完成之后需要执行的Block [groupInfo:该群组ID对应的群组信息]

 @discussion SDK通过此方法获取群组信息并显示，请在completion的block中返回该群组ID对应的群组信息。
 在您设置了群组信息提供者之后，SDK在需要显示群组信息的时候，会调用此方法，向您请求群组信息用于显示。
 */
- (void)getGroupInfoWithGroupId:(NSString *)groupId completion:(void (^)(TCGroupInfo *groupInfo))completion;

@end


/*!
 群组成员列表提供者
 */
@protocol TCIMGroupMemberDataSource <NSObject>

/*!
 获取当前群组成员列表（需要实现用户信息提供者 TCIMUserInfoDataSource）

 @param groupId     群ID
 @param resultBlock 获取成功之后需要执行的Block [userIdList:群成员ID列表]
 
 @discussion SDK通过此方法群组中的成员列表，请在resultBlock中返回该群组ID对应的群成员ID列表。
 在您设置了群组成员列表提供者之后，SDK在需要获取群组成员列表的时候，会调用此方法，向您请求群组成员用于显示。
 */
- (void)getAllMembersOfGroup:(NSString *)groupId result:(void (^)(NSArray<NSString *> *userIdList))resultBlock;
@end

/*!
 缓存信息变更
 */
@protocol TCCacheInfoChangeDelegate <NSObject>
@optional
/*!
 用户信息变更

 @param userInfo      用户信息

 */
- (void)userInfoChange:(TCUserInfo *)userInfo;

/*!
 群组信息变更

 @param groupInfo      群组信息

 */
- (void)groupInfoChange:(TCGroupInfo *)groupInfo;

@end

@interface TCIM : NSObject

/*!
 获取卯云界面组件IMKit的核心类单例

 @return    卯云界面组件IMKit的核心类单例

 @discussion 您可以通过此方法，获取IMKit的单例，访问对象中的属性和方法。
 */
+ (instancetype)sharedTCIM;

#pragma mark - SDK初始化

/*!
 初始化卯云SDK

 @param appKey  从卯云开发者平台创建应用后获取到的App Key

 */
- (void)initWithAppKey:(int)appKey;

#pragma mark - 连接与断开服务器

/*!
与卯云服务器建立连接

@param token                   从您服务器端获取的token(用户身份令牌)
@param userId            用户id

*/
- (void)connectWithToken:(NSString *)token userId:(NSString *)userId success:(void (^)(NSString *userId))successBlock error:(void (^)(NSError *error))errorBlock;

/*!
 
断开与卓朗服务器的连接
*/
- (void)disconnect;


@property (nonatomic, weak) id<TCIMUserInfoDataSource> userInfoDataSource;

@property (nonatomic, weak) id<TCIMGroupInfoDataSource> groupInfoDataSource;

/*!
 群成员信息提供者

 @discussion 如果您使用了@功能，SDK需要通过您实现的群用户成员提供者，获取群组中的用户列表。
 */
@property(nonatomic, weak) id<TCIMGroupMemberDataSource> groupMemberDataSource;

- (void)addTCCacheInfoChangeDelegate:(id<TCCacheInfoChangeDelegate>)delegate;

- (void)userInfoChange:(TCUserInfo *)userInfo;

- (void)groupInfoChange:(TCGroupInfo *)groupInfo;

- (TCUserInfo *)getUserInfoCache:(NSString *)userId;

- (TCGroupInfo *)getGroupInfoCache:(NSString *)groupId;

- (void)refreshUserInfoCache:(NSString *)userId;

- (void)refreshGroupInfoCache:(NSString *)groupId;

- (void)getUserInfoWithUserId:(NSString *)userId completion:(void (^)(TCUserInfo *userInfo))completion;

@end


NS_ASSUME_NONNULL_END

