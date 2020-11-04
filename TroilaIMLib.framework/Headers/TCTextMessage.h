//
//  TCTextMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/23.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCTextMessage : TCMessageContent

/*!
 文本消息的内容
 */
@property(nonatomic, strong) NSString *content;
/*!
 被@
 */
@property(nonatomic, readwrite) BOOL receiverMentioned;
/*!
 @人
 */
@property(nonatomic, readwrite) BOOL mentionAll;
/*!
 @人
 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *mentionedMembers;

/*!
 初始化测试消息
 
 @param content 文本内容
 @return        测试消息对象
 */
+ (instancetype)messageWithContent:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
