//
//  TCConversation.h
//  TroilaImLib
//
//  Created by sml on 2020/7/2.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCMessage.h"
#import "TCConversationStatus.h"


NS_ASSUME_NONNULL_BEGIN

@interface TCConversation : NSObject

/*!
目标会话ID
*/
@property(nonatomic, copy) NSString *targetId;

/*!
会话类型
*/
@property(nonatomic, copy) TCConversationType conversationType;

/*!
会话中的未读消息数量
*/
@property(nonatomic, assign) int unreadCount;

/*!
会话中最后一条消息
*/
@property(nonatomic, strong) TCMessage* lastMsg;

/*!
会话中最后一条消息的操作时间
*/
@property(nonatomic, assign) long long timestamp;

/*!
会话的会话状态
*/
@property(nonatomic, strong) TCConversationStatus *status;

/*!
 会话中是否存在被@的消息

 @discussion 在清除会话未读数（clearMessagesUnreadStatus:targetId:）的时候，会将此状态置成 NO。
 */
@property(nonatomic, assign) BOOL hasUnreadMentioned;

/*!
 会话中存在的草稿
 */
@property (nonatomic, copy) NSString *draft;

+ (instancetype)initWithTRConversation:(id)trConversation;

@end

NS_ASSUME_NONNULL_END

