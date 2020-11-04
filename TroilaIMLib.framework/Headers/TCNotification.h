//
//  TCNotification.h
//  MaoYunIMLib
//
//  Created by 李杰 on 2020/10/13.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCStatusDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCNotification : NSObject

/*!
目标会话ID
*/
@property(nonatomic, copy) NSString *targetId;

/*!
会话类型
*/
@property(nonatomic, copy) TCConversationType conversationType;

@end

NS_ASSUME_NONNULL_END
