//
//  TCDelegate.h
//  TroilaImLib
//
//  Created by sml on 2020/6/19.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCStatusDefine.h"
#import "TCMessage.h"


NS_ASSUME_NONNULL_BEGIN

@protocol TCConnectionStatusChangeDelegate <NSObject>
- (void)onConnectionStatusChanged:(TCConnectionStatus)status;
@end

@protocol TCSyncHistoryMessagesStatusChangeDelegate <NSObject>
- (void)onSyncHistoryMessagesChange:(BOOL)status;
@end

@protocol TCConversationStatusChangeDelegate <NSObject>
-(void)onConversationStatusChange;
@end

@protocol TCNotificationDelegate <NSObject>
- (void)onReceivedNotification:(TCNotificationType)notificationType tcMessage:(TCMessage *)tcMessage tcMessages:(NSArray<TCMessage *> *)tcMessages messageId:(NSString *)messageId targetId:(NSString *)targetId conversationType:(TCConversationType)conversationType;
@end

@protocol TCDeleteMessageDelegate <NSObject>
- (void)onDeleteMessages:(NSArray<NSString *> *)messageIds;
- (void)onClearConversationMessages:(NSString *)targetId conversationType:(TCConversationType)conversationType;
@end

@protocol TCReceivedMessageDelegate <NSObject>
- (void)onReceivedMessage:(TCMessage *)message left:(int)left offline:(BOOL)offline;
@end

@protocol TCCustomNotificationDelegate <NSObject>
- (void)onReceivedCustomNotification:(NSDictionary *)notification targetId:(NSString *)targetId conversationType:(TCConversationType)conversationType;
@end

@protocol TCReceivedStatusDelegate <NSObject>
- (void)onReceivedStatusType:(NSString*)statusType  messageType:(NSString *)messageType targetId:(NSString *)targetId conversationType:(TCConversationType)conversationType;
@end

NS_ASSUME_NONNULL_END
