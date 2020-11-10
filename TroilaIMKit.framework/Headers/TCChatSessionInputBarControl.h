//
//  SendMessageView.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/24.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCPluginBoardView.h"
#import <TroilaIMLib/TroilaIMLib.h>
#import "TCUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TCChatSessionInputBarControlDelegate <NSObject>
- (void)showChooseUserViewController:(void (^)(TCUserInfo *selectedUserInfo))selectedBlock cancel:(void (^)(void))cancelBlock;
- (void)inputTextView:(UITextView *)inputTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (TCMessageContent *)willSendMessage:(TCMessageContent *)messageContent;
- (void)didSendMessage:(NSInteger)status content:(TCMessageContent *)messageContent;
@end


@interface TCChatSessionInputBarControl : UIView

@property(nonatomic) TCConversationType  conversationType;
@property(nonatomic, copy) NSString *targetId;
@property UITableView *tableview;
@property UITextView *textInput;
@property BOOL pluginBoardIsOpen;
@property BOOL emojiBoardIsOpen;
@property BOOL keybordIsOpen;
@property TCPluginBoardView *pluginBoardView;
@property (nonatomic) void(^onPluginBoardViewItemClick)(TCPluginBoardView *pluginBoardView,NSInteger tag);
@property NSInteger offsetHeight;
@property BOOL showTextView;
@property NSInteger textOffsetHeight;
@property NSInteger SafeAreaBottomHeight;
@property UIButton *recordButton;
@property (nonatomic, weak, nullable) id <TCChatSessionInputBarControlDelegate> delegate;
@property (nonatomic,assign) NSTimeInterval sendStatusMessageTimeOffset;
- (void)keyboardWillShow:(NSNotification*)notification;
- (void)keyboardWillHide:(NSNotification *)notification;
- (void)resetHeight;
- (void)textInputAppendingMentionUser:(TCUserInfo * _Nonnull)userInfo;
- (void)checkConversationDraft;
@end




NS_ASSUME_NONNULL_END
