//
//  MJBaseViewController.m
//  小趣护士版
//
//  Created by MrChenMj on 16/3/31.
//  Copyright © 2016年 窦建斌. All rights reserved.
//

#import "MJBaseViewController.h"
#import "MJAlertView.h"

#define kTouchBackgroundTag 200

@interface MJBaseViewController ()<UIGestureRecognizerDelegate>

@end

@implementation MJBaseViewController

+ (instancetype)shareInitViewControllerWithStroyboardName:(NSString *)name ID:(NSString *)stID
{
    return [[UIStoryboard storyboardWithName:name bundle:nil] instantiateViewControllerWithIdentifier:stID];
}
- (void)viewDidLoad {
    [super viewDidLoad];
//    if ([self respondsToSelector:@selector(edgesForExtendedLayout)]) {
//        self.edgesForExtendedLayout = UIRectEdgeNone;
//        self.extendedLayoutIncludesOpaqueBars = YES;
//    }
//    
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    if (self.showBackButton == YES) {
        UIButton *backButton = [[UIButton alloc] init];
        backButton.frame = CGRectMake(0, 0, 44, 44);
        [backButton setImageEdgeInsets:UIEdgeInsetsMake(16, 0, 12, 28)];
        backButton.backgroundColor = [UIColor clearColor];
        [backButton setImage:[UIImage imageNamed:@"back.png"] forState:UIControlStateNormal];
        [backButton setImage:[UIImage imageNamed:@"btn_nav_back_selected"] forState:UIControlStateHighlighted];
        [backButton addTarget:self
                       action:@selector(backButtonAction:)
             forControlEvents:UIControlEventTouchUpInside];
        self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc]
                                                 initWithCustomView:backButton];
    }
    NSArray *nArr = self.navigationController.viewControllers;
    
    if (IOS_7) {
        [self.navigationItem setHidesBackButton:YES];
        self.navigationController.interactivePopGestureRecognizer.delegate = self;
        
        
        
        if (nArr.count>1) {
            
            self.navigationController.interactivePopGestureRecognizer.enabled = YES;
            
        }else
        {
            self.navigationController.interactivePopGestureRecognizer.enabled = NO;
        }
        
        
    }
    // Do any additional setup after loading the view.
}

- (void)backButtonAction:(id)sender {
    if (self.navigationController) {
        [self.navigationController popViewControllerAnimated:YES];
    }
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    // [MobClick beginLogPageView:[self descForUmeng]];
}
- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    //[MobClick endLogPageView:[self descForUmeng]];
}

- (void)viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];
}

- (BOOL)shouldAutorotate {
    return NO;
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
    [super didRotateFromInterfaceOrientation:fromInterfaceOrientation];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)showLoadingViewWithText:(NSString *)text {
    self.hud.text = text;
    [self.hud showWithAnimation:YES];
}

- (void)hideLoadingView {
    [self.hud dismiss];
}

- (CLProgressHUD *)hud {
    if (_hud == nil) {
        CLProgressHUD *hud = [[CLProgressHUD alloc] initWithView:self.view];
        [self.view addSubview:hud];
        _hud = hud;
    }
    return _hud;
}

- (void)showAlertViewWithText:(NSString *)text {
    MJAlertView *hud = nil;
    hud = [[MJAlertView alloc] initWithView:self.view];
    [self.view addSubview:hud];
    [hud showText:text];
}

- (void)ShowText:(NSString *)text
{
    MJAlertView *hud = nil;
    hud = [[MJAlertView alloc] initWithView:self.view];
    [self.view addSubview:hud];
    [hud showText:text];
}
- (void)showAlertViewWithText:(NSString *)text duration:(NSTimeInterval)duration {
    MJAlertView *hud = nil;
    hud = [[MJAlertView alloc] initWithView:self.view];
    [self.view addSubview:hud];
    [hud showText:text duration:duration];
}

- (void)showErrorViewWithText:(NSString *)text {
    MJAlertView *hud = nil;
    hud = [[MJAlertView alloc] initWithView:self.view];
    [self.view addSubview:hud];
    [hud showText:text];
}

- (void)addTouchBackroundWithBlock:(TapBlock)block {
    self.block = block;
    
    UIView *touchBackground = [[UIView alloc] initWithFrame:self.view.bounds];
    touchBackground.backgroundColor = RGBA(0, 0, 0, 0.8);
    touchBackground.tag = kTouchBackgroundTag;
    touchBackground.alpha = 0.0f;
    [self.view bringSubviewToFront:self.view];
    [self.view insertSubview:touchBackground belowSubview:self.view];
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self
                                                                          action:@selector(backgroundTapAction:)];
    [touchBackground addGestureRecognizer:tap];
    [UIView animateWithDuration:0.3f
                     animations:^{
                         touchBackground.alpha = 1.0f;
                     }];
}

- (void)addTouchBackroundBelowView:(UIView *)view withBlock:(TapBlock)block {
    self.block = block;
    
    UIView *touchBackground = [[UIView alloc] initWithFrame:self.view.bounds];
    touchBackground.backgroundColor = RGBA(0, 0, 0, 0.5);
    touchBackground.tag = kTouchBackgroundTag;
    [self.view insertSubview:touchBackground belowSubview:view];
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self
                                                                          action:@selector(backgroundTapAction:)];
    [touchBackground addGestureRecognizer:tap];
    [UIView animateWithDuration:0.3f
                     animations:^{
                         touchBackground.alpha = 1.0f;
                     }];
}

- (void)backgroundTapAction:(UITapGestureRecognizer *)gestureRecognizer {
    _block();
    UIView *touchBackground = [self.view viewWithTag:kTouchBackgroundTag];
    [UIView animateWithDuration:0.3f animations:^{
        touchBackground.alpha = 0.0f;
    } completion:^(BOOL finished) {
        [touchBackground removeFromSuperview];
    }];
}

- (NSString *)descForUmeng {
    return [[self class] description];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
