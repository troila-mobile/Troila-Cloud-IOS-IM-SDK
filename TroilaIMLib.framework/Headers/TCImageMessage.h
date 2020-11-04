//
//  TCImageMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/23.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"
NS_ASSUME_NONNULL_BEGIN


@interface TCImageMessage : TCMessageContent


@property(nonatomic, strong) NSString *content;

@property(nonatomic) float size;

@property(nonatomic) float width;

@property(nonatomic) float height;

@property(nonatomic, strong) NSString *url;

// 是否发送原图
@property(nonatomic) BOOL isOriginal;

+ (instancetype)messageWithContent:(NSString *)content size:(float)size width:(float)width height:(float)height url:(NSString *)url isOriginal:(BOOL)isOriginal;

@end

NS_ASSUME_NONNULL_END
