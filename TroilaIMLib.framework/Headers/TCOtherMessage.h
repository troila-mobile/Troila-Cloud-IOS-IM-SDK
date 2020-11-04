//
//  TCOtherMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/28.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCOtherMessage : TCMessageContent

@property(nonatomic, strong) NSString *content;

+ (instancetype)messageWithContent:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
