//
//  MessageTimeInfo.h
//  TroilaImKit
//
//  Created by sml on 2020/7/16.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TroilaIMLib/TroilaIMLib.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCMessageModel : NSObject

@property TCMessageContent *messageContent;

@property  TCMessageType messageType;

@property(nonatomic) TCSentStatus sentStatus;

@property(strong, nonatomic) NSString* targetId;

@property(strong, nonatomic) NSString* sendUserId;

@property(strong, nonatomic) NSString* messageId;

@property(nonatomic) long long sendTime;

@property(strong, nonatomic) NSString* showTime;

@property(nonatomic) NSUInteger messageDirection;

@property(strong, nonatomic) NSString* conversationType;

@property(nonatomic) bool receiptRequired;

@property(nonatomic) bool read;

@property(nonatomic) bool recalled;

@property(nonatomic, strong) NSArray *readbitmaskList;

@property(nonatomic, strong) NSArray *groupSnapshotList;





- (id)initWithTCMessage:(TCMessage*)tcMessage;

- (id)initTCMessageTimeModelWithSendTime:(long long)sendTime;

@end

NS_ASSUME_NONNULL_END
