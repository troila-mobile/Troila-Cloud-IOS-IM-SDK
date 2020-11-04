//
//  TCFileMessage.h
//  MaoYunIMLib
//
//  Created by 李杰 on 2020/8/14.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCFileMessage : TCMessageContent
@property (nonatomic) float size;
@property (nonatomic,strong) NSString *url;
@property (nonatomic,strong) NSString *mimeType;
@property (nonatomic,strong) NSString *name;
@property (nonatomic,strong) NSString *localPath;
@end

NS_ASSUME_NONNULL_END
