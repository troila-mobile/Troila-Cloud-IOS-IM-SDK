//
//  TCConversationStatus.h
//  MaoYunIMLib
//
//  Created by 李杰 on 2020/8/26.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCStatusDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCConversationStatus : NSObject

/*!
 目标会话ID
 */
@property(nonatomic, copy) NSString *targetId;

/*!
会话类型
*/
@property(nonatomic, assign) TCConversationType conversationType;

/*!
会话免打扰
*/
@property(nonatomic, assign) bool blocked;

/*!
置顶时间戳
*/
@property(nonatomic, assign) long long sticky;

@end

NS_ASSUME_NONNULL_END
