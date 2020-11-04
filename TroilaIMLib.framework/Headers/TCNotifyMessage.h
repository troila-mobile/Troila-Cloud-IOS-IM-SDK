//
//  TCNotifyMessage.h
//  TroilaImLib
//
//  Created by 李杰 on 2020/7/10.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCNotifyMessage : TCMessageContent

@property(nonatomic, strong) NSString *content;

@property(nonatomic, strong) NSString *extra;

@property(nonatomic, strong) NSString *type;

@end

NS_ASSUME_NONNULL_END
