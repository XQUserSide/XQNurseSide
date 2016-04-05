//
//  MJBaseViewController.h
//  小趣护士版
//
//  Created by MrChenMj on 16/3/31.
//  Copyright © 2016年 窦建斌. All rights reserved.
//

#import <UIKit/UIKit.h>
#define MainStroyboardName @"Main"
#import "CLProgressHUD.h"

typedef void(^TapBlock)();
/**
 *  所有控制器类的父类
 */
@interface MJBaseViewController : UIViewController
@property (nonatomic, weak) CLProgressHUD *hud;
@property (nonatomic, copy) TapBlock block;
@property (nonatomic, readonly, weak) UIViewController *rootController;
@property (nonatomic, assign) BOOL showBackButton;
- (void)configLeftItemNavigation;
- (void)configRightItemNavigation;
- (void)addTouchBackroundWithBlock:(TapBlock)block;
- (void)addTouchBackroundBelowView:(UIView *)view withBlock:(TapBlock)block;
/**
 *  友盟统计需要的界面名称
 *
 *  @return
 */
- (NSString *)descForUmeng;
- (void)showLoadingViewWithText:(NSString *)text;
- (void)hideLoadingView;

/**
 *  显示错误提示框
 *
 *  @param text 错误信息
 */
- (void)showErrorViewWithText:(NSString *)text;

/**
 *  显示提示信息
 *
 *  @param text 信息
 */
- (void)ShowText:(NSString *)text;
/**
 *  显示提示信息
 *
 *  @param text 信息
 */
- (void)showAlertViewWithText:(NSString *)text duration:(NSTimeInterval)duration;

/**
 *  显示提示信息
 *
 *  @param name Stroyboard名字
 *  @param stID Stroyboard ID
 */
+ (instancetype)shareInitViewControllerWithStroyboardName:(NSString *)name ID:(NSString *)stID;


@end
