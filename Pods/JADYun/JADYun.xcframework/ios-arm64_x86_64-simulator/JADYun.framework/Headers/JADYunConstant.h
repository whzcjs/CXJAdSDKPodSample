//
//  JADYunConstant.h
//  JADYun
//
//  Created by wangshuai331 on 2021/7/12.
//

#ifndef JADYunConstant_h
#define JADYunConstant_h

typedef NS_ENUM(NSUInteger, JADClickEventTriggerType) {
    /// 支持点击、滑动手势触发的点击事件
    JADClickEventTriggerTypeNormal,
    /// 只支持点击手势触发的点击事件
    JADClickEventTriggerTypeClickOn,
};

/// 落地页打开方式
typedef NS_ENUM(NSInteger, JADInteractionType) {
    /// custom
    JADInteractionTypeCustom = 0,
    /// 原生落地页方式
    JADInteractionTypeURL = 1,
    /// App方式
    JADInteractionTypePage = 2,
};

///  开屏关闭类型
typedef NS_ENUM(NSInteger, JADSplashAdCloseType) {
    JADSplashAdCloseType_Unknow = 0,             // unknow
    JADSplashAdCloseType_ClickSkip = 1,          // click skip
    JADSplashAdCloseType_CountdownToZero = 2,    // countdown
    JADSplashAdCloseType_ClickAd = 3             // click Ad
};

/// 代码位类型
typedef NS_ENUM(NSUInteger, JADSlotType) {
    /// 未知类型 unknown
    JADSlotTypeUnknown = 0,
    /// 开屏广告 splash ads
    JADSlotTypeSplash = 1,
    /// 信息流图 feed ads
    JADSlotTypeFeed = 2,
    /// 插屏广告 interstitial ads
    JADSlotTypeInterstitial = 4,
    /// 横幅广告 banner ads
    JADSlotTypeBanner = 5,
};

/// 广告渲染方式
typedef NS_ENUM(NSUInteger, JADRenderModelType) {
    /// 模板渲染
    JADRenderModelTypeTemplatedAd = 1,
    /// 原生渲染
    JADRenderModelTypeNativeAd = 2,
    /// 动态化渲染
    JADRenderModelTypeDynamicAd = 3,
};

/// 开屏样式
typedef NS_ENUM(NSUInteger, JADSplashStyle) {
    /// 采用服务端配置
    JADSplashStyleServerConfig,
    /// 只显示文案，全屏可点击
    JADSplashStyleOnlyText,
    /// 只有文案部分可点击
    JADSplashStyleOnlyTextClick,
    /// 不处理，无文案，全屏可点击
    JADSplashStyleNormal,
    /// 不处理，有文案，全屏可点击
    JADSplashStyleTextNormal,
};

/// 落地页跳转触发来源
typedef NS_ENUM(NSUInteger, JADTriggerSourceType) {
    JADTriggerSourceTypeClick,   /// 点击
    JADTriggerSourceTypeSAc,     /// 摇一摇 - 原始的综合加速度触发方式
    JADTriggerSourceTypeSwipeUp, /// 向上滑动
    JADTriggerSourceTypeSAcAg,   /// 摇一摇 - 加速度+角度
    JADTriggerSourceTypeSAcAgT,  /// 摇一摇 - 加速度+角度+时长
    JADTriggerSourceTypeSACT,    /// 摇一摇 - 加速度+时长
    JADTriggerSourceTypeSAg,     /// 摇一摇 - 角度
    JADTriggerSourceTypeSAgT,    /// 摇一摇 - 角度+时长
};

/// 广告事件交互方式
typedef NS_ENUM(NSUInteger, JADEventInteractionType) {
    JADEventInteractionTypeNormal,   // 默认点击交互方式
    JADEventInteractionTypeShake,    // 摇一摇交互方式
    JADEventInteractionTypeSwipeUp,  // 上划交互方式
};

/// 点击区域类型
typedef NS_ENUM(NSUInteger, JADClickAreaType) {
    JADClickAreaTypeFullScreen = 1, // 全屏
    JADClickAreaTypeLimit,          // 限点
};

/// 规格集
typedef NS_ENUM(NSUInteger, JADMediaSpecSetType) {
    JADMediaSpecSetType_Normal                  = 0,       // 无规格集
    JADMediaSpecSetType_Splash2_3_Single        = 10001,   // 开屏2:3单图
    JADMediaSpecSetType_Splash9_16_Single       = 10002,   // 开屏9:16单图
    JADMediaSpecSetType_Feed16_9_Single         = 10003,   // 信息流16:9单图
    JADMediaSpecSetType_Feed3_2_Single          = 10004,   // 信息流3:2单图
    JADMediaSpecSetType_Feed3_2_Group           = 10005,   // 信息流3:2组图
    JADMediaSpecSetType_Feed2_1_Single          = 10006,   // 信息流2:1单图
    JADMediaSpecSetType_Feed16_9_Single_Video   = 10007,   // 信息流16:9单视频
    JADMediaSpecSetType_Feed9_16_Single_Video   = 10008,   // 信息流9:16单视频
    JADMediaSpecSetType_Splash9_16_Single_Video = 10009,   // 开屏9:16单视频
    JADMediaSpecSetType_Feed9_16_Single         = 10010,   // 信息流9:16单图
    JADMediaSpecSetType_Interstitial9_16_Single = 10011,   // 插屏9:16单图
};

/// 广告交互类型
typedef NS_ENUM(NSUInteger, JADAnimationType) {
    /// 静态可点区域
    JADAnimationTypeHotSpot,
    /// 静态全屏可点击
    JADAnimationTypeFullScreen,
    /// 摇一摇动效类型
    JADAnimationTypeShake,
    /// 向上滑动动效类型
    JADAnimationTypeSwipeUp,
};

/// Video Sound Mode
typedef NS_ENUM(NSUInteger, JADVideoSoundMode) {
    JADVideoSoundModeDefault,   // 默认的未设置
    JADVideoSoundModeUnmuted,   // 视频有声音播放
    JADVideoSoundModeMuted,     // 视频无声播放
};

/// Video Autoplay Mode
typedef NS_ENUM(NSUInteger, JADVideoAutoplayMode) {
    JADVideoAutoplayModeDefault,            // 默认的未设置
    JADVideoAutoplayNoAutoplay,             // 不自动播放
    JADVideoAutoplayModeWifiAutoplay,       // WiFi下自动播放
    JADVideoAutoplayModeNetworkAutoplay,    // 有网络自动播放
};

/// Video Player Status
typedef NS_ENUM(NSUInteger, JADVideoPlayerStatus) {
    JADVideoPlayerStatusDefault,    // 默认状态
    JADVideoPlayerStatusWillStart,  // 调用play方法
    JADVideoPlayerStatusBuffered,   // 缓存完成
    JADVideoPlayerStatusStarted,    // 播放中
    JADVideoPlayerStatusFinished,   // 播放完成
    JADVideoPlayerStatusPaused,     // 播放暂停
    JADVideoPlayerStatusResumed,    // 播放复播
    JADVideoPlayerStatusError,      // 播放异常
};

#endif /* JADYunConstant_h */
