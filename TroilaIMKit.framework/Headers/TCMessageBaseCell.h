//
//  TCMessageBaseCellTableViewCell.h
//  TroilaImKit
//
//  Created by sml on 2020/7/20.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCMessageCellDelegate.h"
#import "TCMessageModel.h"
#import <TroilaIMLib/TroilaIMLib.h>


NS_ASSUME_NONNULL_BEGIN

@interface TCMessageBaseCell : UITableViewCell
/*!
 自定义消息Cell的Size

 @param model               要显示的消息model

 @return 自定义消息Cell的高度

 @discussion 当应用自定义消息时，必须实现该方法来返回cell的Size。
 */
+ (CGFloat)heightForMessageModel:(TCMessageModel *)model;

/*!
 消息Cell点击回调
 */
@property(nonatomic, weak) id<TCMessageCellDelegate> delegate;

/*!
 消息Cell的数据模型
 */
@property(strong, nonatomic) TCMessageModel *model;

/*!
 消息的方向
 */
@property(nonatomic) TCMessageDirection messageDirection;
/*!
 Cell显示的View
 */
@property(strong, nonatomic) UIView *baseContentView;

/*!
 是否显示阅读状态
 */
@property(nonatomic) BOOL isDisplayReadStatus;

/*!
 初始化消息Cell

 @param frame 显示的Frame
 @return 消息Cell基类对象
 */
- (instancetype)initWithFrame:(CGRect)frame;

/*!
 设置当前消息Cell的数据模型

 @param model 消息Cell的数据模型
 */
- (void)setDataModel:(TCMessageModel *)model;

@end

NS_ASSUME_NONNULL_END
