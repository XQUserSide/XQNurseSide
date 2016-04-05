//
//  MJAlertView.h
//  IDEXX
//
//  Created by MrChenMj on 15/12/17.
//  Copyright © 2015年 MrChenMj. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MJAlertView : UIView

+ (instancetype)shareInstance;
- (id)initWithView:(UIView *)view;
- (id)initWithWindow:(UIWindow *)window;
- (void)showText:(NSString *)text;
- (void)showText:(NSString *)text duration:(NSTimeInterval)duration;

@end
