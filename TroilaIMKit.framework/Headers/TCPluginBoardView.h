//
//  TCPluginBoardView.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/7/27.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCPluginBoardView : UIView

- (void)insertItemWithImage:(UIImage *)image title:(NSString *)title tag:(int)tag;
@property (nonatomic) void(^onPluginBoardViewItemClick)(NSInteger tag);

@end

NS_ASSUME_NONNULL_END
