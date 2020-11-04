//
//  TCConversationModel.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/21.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TroilaIMLib/TroilaIMLib.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCConversationModel : NSObject

/*!
 会话类型
 */
@property(nonatomic, copy) TCConversationType conversationType;

/*!
 目标会话ID
 */
@property(nonatomic, copy) NSString *targetId;

/*!
 会话的标题
 */
@property(nonatomic, copy) NSString *conversationTitle;

/*!
 会话中的未读消息数
 */
@property(nonatomic, assign) int unreadCount;

/*!
 当前会话是否置顶
 */
@property(nonatomic, assign) BOOL isTop;

/*!
 会话中最后一条消息的发送时间（Unix时间戳、毫秒）
 */
@property(nonatomic, assign) long long sendTime;

/*!
 当前会话是否免打扰
 */
@property(nonatomic, assign) BOOL blocked;

/*!
发送状态
*/
@property(nonatomic, assign) TCSentStatus sentStatus;

/*!
 会话中最后一条消息的内容
 */
@property(nonatomic, strong) TCMessageContent *lastestMessage;

/*!
 会话中是否存在被@的消息
 */
@property(nonatomic, assign) BOOL hasUnreadMentioned;

/*!
 发送人userId
 */
@property(nonatomic, copy) NSString *senderUserId;

/** 消息撤回 */
@property(nonatomic, assign) BOOL recalled;

/*!
 会话中存在的草稿
 */
@property (nonatomic, copy) NSString *draft;

/*!
 初始化会话显示数据模型

 @param conversation          会话
 @return 会话Cell的数据模型对象
 */
+ (instancetype)initWithConversation:(TCConversation *)conversation;


@end

NS_ASSUME_NONNULL_END
