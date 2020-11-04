//
//  TCConversationListSearchViewController.h
//  TroilaImKit
//
//  Created by 李杰 on 2020/9/24.
//  Copyright © 2020 troila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCConversationModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TCConversationListSearchDelegate <NSObject>
- (void)onSelectedTableRow:(TCConversationModel *)model atIndexPath:(NSIndexPath *)indexPath;
- (void)inactiveSearchController;
@end

@interface TCConversationListSearchViewController : UIViewController<UISearchResultsUpdating>
@property (nonatomic, weak, nullable) id <TCConversationListSearchDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
