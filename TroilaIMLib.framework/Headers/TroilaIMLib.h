//
//  TroilaImLib.h
//  TroilaImLib
//
//  Created by 李杰 on 2020/6/19.
//  Copyright © 2020 troila. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for TroilaImLib.
FOUNDATION_EXPORT double TroilaImLibVersionNumber;

//! Project version string for TroilaImLib.
FOUNDATION_EXPORT const unsigned char TroilaImLibVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TroilaImLib/PublicHeader.h>

/// IMLib核心类
#import <TroilaIMLib/TCIMClient.h>
#import <TroilaIMLib/TCStatusDefine.h>
/// 消息相关类
#import <TroilaIMLib/TCMessage.h>
#import <TroilaIMLib/TCMessageContent.h>
#import <TroilaIMLib/TCTextMessage.h>
#import <TroilaIMLib/TCVoiceMessage.h>
#import <TroilaIMLib/TCGifMessage.h>
#import <TroilaIMLib/TCImageMessage.h>
#import <TroilaIMLib/TCNewsMessage.h>
#import <TroilaIMLib/TCLocationMessage.h>
#import <TroilaIMLib/TCCustomMessage.h>
#import <TroilaIMLib/TCOtherMessage.h>
#import <TroilaIMLib/TCNotifyMessage.h>
#import <TroilaIMLib/TCFileMessage.h>
#import <TroilaIMLib/TCCustomMessage.h>
#import <TroilaIMLib/TCNotification.h>
