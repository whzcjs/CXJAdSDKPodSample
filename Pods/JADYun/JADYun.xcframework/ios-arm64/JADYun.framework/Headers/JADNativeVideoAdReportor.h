//
//  JADNativeVideoAdReportor.h
//  JADYun
//
//  Created by wangshuai331 on 2023/7/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol JADNativeVideoAdReportor <NSObject>

/// 视频将要开始时上报此事件
- (void)willStartVideo;

/// 视频缓存完成时上报此事件
- (void)didBufferVideo;

/// 视频开始播放时上报此事件，duration为视频时长
- (void)didStartVideoWithVideoDuration:(NSTimeInterval)duration;

/// 视频暂停时上报此事件，duration为视频暂停时视频已播放的时长
- (void)didPauseVideoWithCurrentDuration:(NSTimeInterval)duraiton;

/// 视频播放完成时上报此事件，duration为视频播放完成时视频已播放的时长
- (void)didFinishVideoWithCurrentDuration:(NSTimeInterval)duration;

/// 视频复播时上报此事件，duration为视频复播时视频已播放的时长
- (void)didResumeVideoWithCurrentDuration:(NSTimeInterval)duraiton;

/// 视频播放异常时上报此事件，duration为出现异常时视频已播放的时长
- (void)didFailVideoWithCurrentDuration:(NSTimeInterval)duration error:(NSError *__nullable)error;

@end

NS_ASSUME_NONNULL_END
