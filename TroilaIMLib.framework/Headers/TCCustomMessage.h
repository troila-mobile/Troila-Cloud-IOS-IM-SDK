//
//  TCCustomMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/28.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"

NS_ASSUME_NONNULL_BEGIN


@interface TCCustomMessage : TCMessageContent

@property(nonatomic, strong)NSString  *data;

+ (instancetype)messageWithContent:(NSString *)data;
@end

NS_ASSUME_NONNULL_END
