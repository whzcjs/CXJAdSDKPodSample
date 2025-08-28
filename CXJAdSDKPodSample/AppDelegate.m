//
//  AppDelegate.m
//  CXAdSDKSample
//
//  Created by AustinYang on 2025/8/25.
//

#import "AppDelegate.h"
#import "SplashAdDelegate.h"
#import <CXJAdSDK/CXJAdSDK.h>
#import <Toast.h>
#import <CXJAdSDKPodSample-Swift.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/AdSupport.h>

@interface AppDelegate ()
@property (strong, nonatomic) CXJSplashAd *cxjSplashAd;

@property (strong, nonatomic) UIView *bottomView;
@property (strong, nonatomic) SplashAdDelegate *splashDelegate;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    NSString *sdkVersion = [CXJAdSDKManager sdkVersion];
    NSLog(@"cx ad sdk version = %@", sdkVersion);
    
    
    
    [NetworkOnceTrigger.shared startMonitoringIfNeeded:^{
        [self initCXAdSDK];
    }];

    
    
    return YES;
}

- (void)initCXAdSDK {
    BOOL result = [CXJAdSDKManager initWithAppId:kAppId
                                       secretKey:kSecretKey];
    
    if (!result) {
        NSLog(@"--------SDK初始化失败");
    }
    else {
        [CXJAdSDKManager startWithCompletionHandler:^(BOOL success, NSError * _Nonnull error) {
            NSLog(@"--------sdk 初始化结果 = %@ error = %@", @(success), error);
            if (!success && error) {
                [self.window.rootViewController.view makeToast:[NSString stringWithFormat:@"%@", error]];
            }
            if (success) {
                [self.window.rootViewController.view makeToast:[NSString stringWithFormat:@"sdk初始化成功"]];
                self.cxjSplashAd = [[CXJSplashAd alloc] initWithPlacementId: kSplashId];
                self.cxjSplashAd.delegate = self.splashDelegate;
                self.cxjSplashAd.viewController = self.window.rootViewController;
                self.cxjSplashAd.fetchDelay = 0.1;
                self.cxjSplashAd.bottomView = self.bottomView;
                [self.cxjSplashAd loadAd];
            }
        }];
    }
}

- (UIView *)bottomView {
    if (!_bottomView) {
        _bottomView = [[UIView alloc] initWithFrame:(CGRectMake(0, 0, UIScreen.mainScreen.bounds.size.width, 100))];
        _bottomView.backgroundColor = UIColor.orangeColor;
    }
    return _bottomView;
}

- (SplashAdDelegate *)splashDelegate {
    if (!_splashDelegate) {
        _splashDelegate = [[SplashAdDelegate alloc] initWithWithWindow:self.window
                                                             cxjSplash:self.cxjSplashAd];
    }
    return _splashDelegate;
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
                NSString *idfa = [[ASIdentifierManager sharedManager].advertisingIdentifier UUIDString];
                NSLog(@"--------idfa = %@", idfa);
                
            } else {
                
            }
        }];
    } else {
        
    }

}

@end
