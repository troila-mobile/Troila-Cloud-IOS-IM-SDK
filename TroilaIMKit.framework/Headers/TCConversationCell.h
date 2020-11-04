//
//  TCConversationCell.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/15.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCConversationModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCConversationCell : UITableViewCell

/*!
 会话的标题
 */
@property(nonatomic, strong) UILabel *conversationTitle;
/*!
 Cell头像View
 */
@property(nonatomic, strong) UIImageView *headerImageView;
/*!
 显示最后一条内容的Label
 */
@property(nonatomic, strong) UILabel *messageContentLabel;
/*!
 显示最后一条消息发送时间的Label
 */
@property(nonatomic, strong) UILabel *messageCreatedTimeLabel;
/*!
 未读消息提示的View
 */
@property(nonatomic, strong) UIView *bubbleTipView;
/*!
 会话免打扰状态显示的View
 */
@property(nonatomic, strong) UIImageView *conversationStatusImageView;
/*!
 未读消息数字
 */
@property(nonatomic, strong) UILabel *unreadNumLabel;

/*!
 显示最后一台消息发送状态
 */
@property(nonatomic, strong) UIImageView *lastSendMessageStatusView;

- (void)setUnreadCount:(int)unreadCount;

- (void)setConversationStatus:(bool)blocked;

/*!
 设置当前会话Cell的数据模型

 @param model 会话Cell的数据模型
 */
- (void)setDataModel:(TCConversationModel *)model;

@end

NS_ASSUME_NONNULL_END
