//
//  JADNativeAdData.h
//  JADYun
//
//  Created by wangshuai331 on 2020/11/2.
//

#import <Foundation/Foundation.h>

#if __has_include(<JADYunCore/JADYunConstant.h>)
#import <JADYunCore/JADYunConstant.h>
#else

#import "JADYunConstant.h"

#endif

NS_ASSUME_NONNULL_BEGIN

@interface JADNativeAdData : NSObject

// ad image address URL
@property (strong, nonatomic) NSArray <NSString *> *adImages;

// ad image width
@property (assign, nonatomic) NSInteger adImageWidth;

// ad image height
@property (assign, nonatomic) NSInteger adImageHeight;

// ad source
@property (copy, nonatomic) NSString *adResource;

// ad title
@property (copy, nonatomic) NSString *adTitle;

// ad description
@property (copy, nonatomic) NSString *adDescription;

// ad price 广告价格（单位：分）
@property (assign, nonatomic) NSInteger adPrice;

// video duration (单位：ms)
@property (assign, nonatomic) NSInteger adVideoDuration;

// video url
@property (copy, nonatomic, readonly) NSString *adVideoUrl;

// video resolution width
@property (assign, nonatomic, readonly) NSInteger adVideoResolutionWidth;

// video resolution height
@property (assign, nonatomic, readonly) NSInteger adVideoResolutionHeight;

// video sound mode
@property (assign, nonatomic) JADVideoSoundMode adVideoSoundMode;

// video autoplay mode
@property (assign, nonatomic) JADVideoAutoplayMode adVideoAutoplayMode;

@end

NS_ASSUME_NONNULL_END
