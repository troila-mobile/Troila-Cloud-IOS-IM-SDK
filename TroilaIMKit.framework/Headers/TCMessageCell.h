//
//  RCMessageCell.h
//  TroilaImKit
//
//  Created by sml on 2020/7/21.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCMessageBaseCell.h"
#import "TCUIView.h"
NS_ASSUME_NONNULL_BEGIN

/*!
展示的消息Cell类

@discussion 需要展示用户信息和内容的消息Cell可以继承此类，
如：TCTextMessageCell、TCImageMessageCell、TCLocationMessageCell、TCVoiceMessageCell、TCRichContentMessageCell等。
如果您需要显示自定义消息，可以继承此类。
*/
@interface TCMessageCell : TCMessageBaseCell


/*!
消息发送者的用户头像
*/
@property(nonatomic, strong) UIImageView *portraitImageView;

/*!
 消息发送者的用户名称
 */
@property(nonatomic, strong) UILabel *nicknameLabel;

/*!
 消息内容的View
 */
@property(nonatomic, strong) TCUIView *messageContentView;

/*!
 显示发送状态的View

 @discussion 其中包含messageFailedStatusView子View。
 */
@property(nonatomic, strong) UIView *statusContentView;

/*!
 显示发送失败状态的View
 */
@property(nonatomic, strong) UIButton *messageFailedStatusView;

/*!
 消息发送指示View
 */
@property(nonatomic, strong) UIActivityIndicatorView *messageActivityIndicatorView;

/*!
 消息内容的View的宽度
 */
@property(nonatomic, readonly) CGFloat messageContentViewWidth;

/*!
 是否显示用户名称
 */
@property(nonatomic, readonly) BOOL isDisplayNickname;

/*!
 显示消息已阅读状态的View
 */
@property(nonatomic, strong) UIView *messageHasReadStatusView;

/*!
 显示是否消息回执的Button

 @discussion 仅在群组和讨论组中显示
 */
@property(nonatomic, strong) UIButton *receiptView;

/*!
 消息阅读人数的Label

 @discussion 仅在群组和讨论组中显示
 */
@property(nonatomic, strong) UILabel *receiptCountLabel;

/*!
消息撤回提示的Label

@discussion 仅在群组和讨论组中显示
*/
@property(nonatomic, strong) UILabel *recallLabel;

/*!
 显示消息发送失败的UIImageView
 */
@property(nonatomic, strong) UIImageView *sendMessageStatusView;

/*!
 显示消息发送成功状态的View
 */
@property(nonatomic, strong) UIView *messageSendSuccessStatusView;

/*!
 设置当前消息Cell的数据模型

 @param model 消息Cell的数据模型
 */
- (void)setDataModel:(TCMessageModel *)model;

/*!
 更新消息发送状态

 @param model 消息Cell的数据模型
 */
- (void)updateStatusContentView:(TCMessageModel *)model;

@end

NS_ASSUME_NONNULL_END
