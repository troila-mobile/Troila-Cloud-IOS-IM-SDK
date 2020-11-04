//
//  TCessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/22.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCMessageContent.h"
#import "TCStatusDefine.h"
#import "TCTextMessage.h"
#import "TCImageMessage.h"
#import "TCGifMessage.h"
#import "TCVoiceMessage.h"
#import "TCNewsMessage.h"
#import "TCLocationMessage.h"
#import "TCCustomMessage.h"
#import "TCNotifyMessage.h"
#import "TCFileMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCMessage : NSObject 

/**
 * *M
 * 会话类型
 * CT:Private
 * CT:Group
 **/
@property(nonatomic, readwrite, copy, null_resettable) TCConversationType conversationType;

/**
 *
 * 消息类型:
 * CONTENT,STATUS,NOTIFICATION
 **/
@property(nonatomic, readwrite) MessageType type;
/*!
 目标会话ID
 */
@property(nonatomic, copy) NSString *targetId;

/** 消息ID */
@property(nonatomic, readwrite, copy, null_resettable) NSString *messageId;

/** 消息的内容 */
@property(nonatomic, readwrite, strong, null_resettable) TCMessageContent *messageContent;


/** 更新时间 */
@property(nonatomic) long long updateTime;

/** 消息撤回 */
@property(nonatomic) BOOL recalled;

/** 消息是否已读 */
@property(nonatomic) BOOL read;

/*!
 消息的方向
 */
@property(nonatomic, assign) TCMessageDirection messageDirection;

/** 发送人ID */
@property(nonatomic, readwrite, copy, null_resettable) NSString *senderUserId;

/** 发送时间 */
@property(nonatomic, readwrite) long long sendTime;

/** 服务器下发时间 */
@property(nonatomic, readwrite) long long receivedTime;

/** 额外扩展字段 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *extra;

@property(nonatomic, strong) NSArray *readbitmaskList;

@property(nonatomic, strong) NSArray *groupSnapshotList;

@property(nonatomic) TCSentStatus sentStatus;

+ (instancetype)initWithTRMessage:(id)trMessage;

+(NSArray*)initWithTRMessages:(NSArray*)realmMessages;

@property(nonatomic, readwrite) NSString *messageType;

@property(nonatomic, readwrite) bool receiptRequired;

@end

NS_ASSUME_NONNULL_END
