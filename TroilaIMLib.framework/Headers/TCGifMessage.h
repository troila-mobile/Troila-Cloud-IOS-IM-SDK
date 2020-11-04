//
//  TCGifMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/23.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"

NS_ASSUME_NONNULL_BEGIN


@interface TCGifMessage : TCMessageContent

@property(nonatomic) uint64_t size;

@property(nonatomic) uint32_t width;

@property(nonatomic) uint32_t height;

@property(nonatomic, strong) NSString *URL;

+ (instancetype)messageWithURL:(NSString *)URL Size:(uint64_t)size Width:(uint32_t)width Height:(uint32_t)height;

@end

NS_ASSUME_NONNULL_END
