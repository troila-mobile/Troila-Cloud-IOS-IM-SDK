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

@end

NS_ASSUME_NONNULL_END

