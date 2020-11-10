//
//  TCConversationListViewController.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/14.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCConversationModel.h"
#import "TCConversationViewController.h"
#import "TCConversationCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCConversationListViewController : UIViewController

/*!
 点击会话列表中Cell的回调


 @param model                   当前点击的会话的Model
 @param indexPath               当前会话在列表数据源中的索引值

 @discussion 您需要重写此点击事件，跳转到指定会话的会话页面。
 */
- (void)onSelectedTableRow:(TCConversationModel *)model atIndexPath:(NSIndexPath *)indexPath;

- (TCConversationViewController *)contextMenuConfigurationForRowAtIndexPath:(NSIndexPath *)indexPath model:(TCConversationModel *)model;

- (void)onReceivedNotification:(nonnull TCNotificationType)notificationType tcMessage:(nonnull TCMessage *)tcMessage tcMessages:(nonnull NSArray<TCMessage *> *)tcMessages messageId:(nonnull NSString *)messageId targetId:(nonnull NSString *)targetId conversationType:(nonnull TCConversationType)conversationType;

- (void)didDeleteConversationCell:(TCConversationModel *)model;

- (NSMutableArray *)willReloadTableData:(NSMutableArray *)dataSource;

- (void)willDisplayConversationTableCell:(TCConversationCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END
