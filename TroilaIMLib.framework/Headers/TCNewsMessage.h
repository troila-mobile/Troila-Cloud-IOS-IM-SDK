//
//  TCNewsMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/23.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"
NS_ASSUME_NONNULL_BEGIN


@interface TCNewsMessage : TCMessageContent

@property(nonatomic, strong) NSString *title;

@property(nonatomic, strong) NSString *desc;

@property(nonatomic, strong) NSString *url;

@property(nonatomic, strong) NSString *logoUrl;

+ (instancetype)messageWithTitle:(NSString *)title Desc:(NSString *)desc Url:(NSString *)url LogoUrl:(NSString *)logoUrl;

@end

NS_ASSUME_NONNULL_END
