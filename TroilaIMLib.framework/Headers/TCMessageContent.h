//
//  TCMessageContent.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/22.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Imserver.pbobjc.h"
#import "TCStatusDefine.h"


NS_ASSUME_NONNULL_BEGIN

@interface TCMessageContent : NSObject

- (id)getGRPCMessage;
- (void)setContentWithContentMessage:(id)contentMessage;
- (NSString *)conversationDigest;
+ (NSString *)getMessageType;
- (void)decode:(NSString *)content;
- (NSString *)encode;
- (NSString *)keyword;
@end

NS_ASSUME_NONNULL_END
