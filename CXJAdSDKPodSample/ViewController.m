//
//  ViewController.m
//  CXAdSDKSample
//
//  Created by AustinYang on 2025/8/25.
//

#import "ViewController.h"
#import <CXJAdSDK/CXJAdSDK.h>
#import "AdTypeListModel.h"

#import <MBProgressHUD.h>
#import "RewardVideoViewController.h"
#import "BannerViewController.h"
#import "InterstitialAdViewController.h"
#import "NativeExpressAdViewController.h"
#import "NativeAdViewController.h"
#import <Toast.h>

#import "SplashAdDelegate.h"

@interface ViewController ()<UITableViewDataSource, UITableViewDelegate>
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (strong, nonatomic) NSArray <AdTypeListModel *>*contentList;

@property (strong, nonatomic) UIView *bottomView;
@property (strong, nonatomic) CXJSplashAd *cxjSplashAd;
@property (strong, nonatomic) SplashAdDelegate *splashDelegate;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setup];
}

- (void)setup {
    self.contentList = [AdTypeListModel getDataList];
    [self.tableView registerClass:UITableViewCell.class forCellReuseIdentifier:@"cell"];
}

#pragma mark -UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.contentList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    AdTypeListModel *listModel = self.contentList[indexPath.row];
    cell.textLabel.text = listModel.title;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    AdTypeListModel *listModel = self.contentList[indexPath.row];
    switch (listModel.adType) {
        case AdTypeSplash:
        {
            [MBProgressHUD showHUDAddedTo:self.view animated:YES];
            [self.cxjSplashAd loadAd];
        }
            break;
            
        case AdTypeBanner:
        {
            BannerViewController *vc = BannerViewController.new;
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
            
        case AdTypeInterstitial:
        {
            InterstitialAdViewController *vc = InterstitialAdViewController.new;
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
        case AdTypeNativeExpress:
        {
            NativeExpressAdViewController *vc = NativeExpressAdViewController.new;
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
            
        case AdTypeNative:
        {
            NativeAdViewController *vc = NativeAdViewController.new;
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
            
        case AdTypeRewardVideo:
        {
            RewardVideoViewController *vc = RewardVideoViewController.new;
            [self.navigationController pushViewController:vc animated:YES];
        }
            break;
            
        default:
            break;
    }
}

- (CXJSplashAd *)cxjSplashAd {
    if (!_cxjSplashAd) {
        _cxjSplashAd = [[CXJSplashAd alloc] initWithPlacementId:kSplashId];
        _cxjSplashAd.delegate = self.splashDelegate;
        _cxjSplashAd.viewController = self;
    }
    return _cxjSplashAd;
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
        _splashDelegate = [[SplashAdDelegate alloc] initWithWithWindow:self.view.window
                                                             cxjSplash:_cxjSplashAd];
        __weak ViewController *weakSelf = self;
        _splashDelegate.compeleteBlock = ^{
            [MBProgressHUD hideHUDForView:weakSelf.view animated:YES];
        };
    }
    return _splashDelegate;
}

@end
