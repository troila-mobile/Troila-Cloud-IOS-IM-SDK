//
//  TCLocationMessage.h
//  TroilaImLib
//
//  Created by zhuolang12 on 2020/6/23.
//  Copyright © 2020 troila. All rights reserved.
//

#import "TCMessageContent.h"
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TCLocationMessage : TCMessageContent

/** base64 */
@property(nonatomic, strong) NSString *thumb;

@property(nonatomic) CLLocationDegrees lat;

@property(nonatomic) CLLocationDegrees lng;

@property(nonatomic, strong) NSString *title;

+ (instancetype)messageWithThumb:(NSString *)thumb Lat:(double)lat Lng:(double)lng Title:(NSString *)title;
@end

NS_ASSUME_NONNULL_END
