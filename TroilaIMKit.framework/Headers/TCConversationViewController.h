//
//  TCConversationViewController.h
//  TroilaImKit
//
//  Created by sml on 2020/7/14.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TroilaIMLib/TroilaIMLib.h>
#import "TCChatSessionInputBarControl.h"
#import "TCPluginBoardView.h"
#import "TCUserInfo.h"
#import "TCMessageCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCConversationViewController : UIViewController

#pragma mark - 初始化

/*!
 初始化会话页面

 @param conversationType 会话类型
 @param targetId         目标会话ID

 @return 会话页面对象
 */
- (id)initWithConversationType:(TCConversationType)conversationType targetId:(NSString *)targetId conversationTitle:(NSString*)conversationTitle;

#pragma mark - 会话属性

/*!
 当前会话的会话类型
 */
@property(nonatomic) TCConversationType  conversationType;

/*!
 目标会话ID
 */
@property(nonatomic, copy) NSString *targetId;

/*!
会话页面标题
*/
@property(nonatomic, copy) NSString *conversationTitle;

#pragma mark - 输入工具栏

/*!
 会话页面下方的输入工具栏
 */
@property(nonatomic, strong) TCChatSessionInputBarControl *chatSessionInputBarControl;

#pragma mark group通知（TCNotificationType_GroupMemberJoined、TCNotificationType_GroupMemberQuited、TCNotificationType_GroupMemberKicked）调用方法
-(void)onGroupMemberChanged:(NSString*)groupId;

/*!
 扩展功能板的点击回调

 @param pluginBoardView 输入扩展功能板View
 @param tag             输入扩展功能(Item)的唯一标示
 */
- (void)pluginBoardView:(TCPluginBoardView *)pluginBoardView clickedItemWithTag:(NSInteger)tag;
/*!
 扩展功能板的点击回调

 @param targetId 目标会话ID
 @param messageId  消息ID
 */

-(void)onClickGroupReceipt:(NSString *)targetId MessageId:(NSString *)messageId;
/*!
 输入框内输入了@符号，即将显示选人界面的回调

 @param selectedBlock 选人后的回调
 @param cancelBlock   取消选人的回调

 @discussion
 开发者如果想更换选人界面，可以重写方法，弹出自定义的选人界面，选人结束之后，调用selectedBlock传入选中的UserInfo即可。
 */
- (void)showChooseUserViewController:(void (^)(TCUserInfo *selectedUserInfo))selectedBlock cancel:(void (^)(void))cancelBlock;

/*!
 输入框中内容发生变化的回调

 @param inputTextView 文本输入框
 @param range         当前操作的范围
 @param text          插入的文本
 */
- (void)inputTextView:(UITextView *)inputTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

/*!
 准备发送消息的回调

 @param messageContent 消息内容

 @return 修改后的消息内容

 @discussion 此回调在消息准备向外发送时会回调，您可以在此回调中对消息内容进行过滤和修改等操作。
 如果此回调的返回值不为nil，SDK会对外发送返回的消息内容。
 */
- (TCMessageContent *)willSendMessage:(TCMessageContent *)messageContent;

/*!
 发送消息完成的回调

 @param status          发送状态，0表示成功，非0表示失败
 @param messageContent   消息内容
 */
- (void)didSendMessage:(NSInteger)status content:(TCMessageContent *)messageContent;


/*!
 即将在会话页面插入消息的回调

 @param message 消息实体
 @return        修改后的消息实体

 @discussion 此回调在消息准备插入数据源的时候会回调，您可以在此回调中对消息进行过滤和修改操作。
 如果此回调的返回值不为nil，SDK会将返回消息实体对应的消息Cell数据模型插入数据源，并在会话页面中显示。
 */
- (TCMessage *)willAppendAndDisplayMessage:(TCMessage *)message;

/*!
 即将显示消息Cell的回调

 @param cell        消息Cell
 @param indexPath   该Cell对应的消息Cell数据模型在数据源中的索引值

 @discussion 您可以在此回调中修改Cell的显示和某些属性。
 */
- (void)willDisplayMessageCell:(TCMessageCell *)cell atIndexPath:(NSIndexPath *)indexPath;


/*!
 点击Cell中头像的回调

 @param userId  点击头像对应的用户ID
 */
-(void)onClickCellAvatar:(NSString *)userId;


/*!
 长按Cell中头像的回调

 @param userId  点击头像对应的用户ID
 */
- (void)didLongPressCellPortrait:(NSString *)userId;


/*!
 点击Cell中的消息内容的回调

 @param model 消息Cell的数据模型

 @discussion SDK在此点击事件中，针对SDK中自带的图片、语音、位置等消息有默认的处理，如查看、播放等。
 您在重写此回调时，如果想保留SDK原有的功能，需要注意调用super。
 */
- (void)onMessageCellClick:(TCMessageModel *)model;


/*!
 长按Cell中的消息内容的回调

 @param model 消息Cell的数据模型

 @discussion SDK在此长按事件中，会默认展示菜单。
 您在重写此回调时，如果想保留SDK原有的功能，需要注意调用super。
 */
- (void)longPressMessageCell:(TCMessageModel *)model;


/*!
 开始录制语音消息的回调
 */
- (void)onBeginRecordEvent;

/*!
 结束录制语音消息的回调
 */
- (void)onEndRecordEvent;

/*!
 取消录制语音消息的回调(不会再走 onEndRecordEvent)
 */
- (void)onCancelRecordEvent;


@end

NS_ASSUME_NONNULL_END

