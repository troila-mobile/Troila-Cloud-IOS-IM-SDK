//
//  TCVoiceMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/23.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"
NS_ASSUME_NONNULL_BEGIN


@interface TCVoiceMessage : TCMessageContent

@property(nonatomic, strong) NSString *content;

@property(nonatomic) int duration;

+ (instancetype)messageWithContent:(NSString *)content duration:(int)duration;

@end

NS_ASSUME_NONNULL_END
