//
//  TCMessageCellDelegate.h
//  TroilaImKit
//
//  Created by sml on 2020/7/20.
//  Copyright © 2020 troila. All rights reserved.
//
#import "TCMessageModel.h"
#import "TCUserInfo.h"
/*!
消息Cell点击的回调
*/
@protocol TCMessageCellDelegate <NSObject>

/*!
 点击Cell内容的回调

 @param model 消息Cell的数据模型
 */
- (void)onMessageCellClick:(TCMessageModel *)model;
/*!
 长按Cell内容的回调

 @param model 消息Cell的数据模型
 */
- (void)longPressMessageCell:(TCMessageModel *)model;
/*!
 点击Cell中用户头像的回调

 @param userId 头像对应的用户ID
 */
- (void)onClickCellAvatar:(NSString *)userId;

/*!
 长按Cell中用户头像的回调

  @param userInfo 头像对应的用户ID
 */
- (void)onLongClickCellAvatar:(TCUserInfo *)userInfo;

/*!
 消息重发
  @param messageId 消息ID
 */
- (void)resendMessage:(NSString *)messageId;

/*!
 查看已读消息群组人员信息
  @param model 消息Cell的数据模型
 */
- (void)onClickReceipt:(TCMessageModel *)model;;

/*!
 点击消息空白
 */
-(void)contentViewClick;

@end
