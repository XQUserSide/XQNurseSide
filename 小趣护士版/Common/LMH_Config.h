//
//  LMH_Config.h
//  YingMeiHui
//
//  Created by KevinKong on 14-8-26.
//  Copyright (c) 2014年 LinChengyu. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LMH_Debug 1  // 1- Debug 模式. 0-Release 模式.


#if LMH_Debug
#define LMHLog(fmt, ...) NSLog((@"%s [Line %zi] " fmt),__PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define LMHLog(fmt, ...)
#endif

//#define kDNavigationBarHeight ((IS_IOS_7) ? 64.0f : 44.0f)
static const CGFloat kNavigationBarHeight = 44.f;
static const CGFloat kTabBarHeight = 49.0f;

/**
 个推的相关账号.
 */
#define GeXinAPNS_AppleID @"d0mIDMriHX94VM418faNH4"
#define GeXinAPNS_AppKey @"gsX0a4WKv88b1EAp3iyyW1"
#define GeXinAPNS_AppSecret @"xiHPEeLCOX5IIOmE0Ncg56"
#define GeXinAPNS_MasterSecret @"UuvMCwHHqiAfFaimRdCov1"

/*
 全局 frame 相关
 */
#define ScreenW   [UIScreen mainScreen].bounds.size.width
#define ScreenH   [UIScreen mainScreen].bounds.size.height
#define UITabBarHeight 44
/*
 */
#define UIColorRGBA(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define CurrentOSVersion  [[UIDevice currentDevice].systemVersion doubleValue]

//设备
#define STATUSBAR_HEIGHT            [[UIApplication sharedApplication] statusBarFrame].size.height
#define FULL_WIDTH                  [[UIScreen mainScreen] bounds].size.width
#define FULL_HEIGHT                 (ScreenH - ((floor(NSFoundationVersionNumber) >= 7) ? 0 : STATUSBAR_HEIGHT))

//颜色
#define RGBA(r,g,b,a)     [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:a]
#define RGB(r,g,b)        RGBA(r,g,b,1)
//字体
#define FONT(s)          [UIFont systemFontOfSize:s]
//图片加载
#define LOCAL_IMG(img)   [UIImage imageNamed:img]

#import <QuartzCore/QuartzCore.h>



#define COLOR_TEXT_A          [UIColor colorWithRed:50.0f/255.0f green:50.0f/255.0f blue:50.0f/255.0f alpha:1.0f]
#define COLOR_TEXT_B          [UIColor colorWithRed:100.0f/255.0f green:100.0f/255.0f blue:100.0f/255.0f alpha:1.0f]
#define COLOR_TEXT_C          [UIColor colorWithRed:150.0f/255.0f green:150.0f/255.0f blue:150.0f/255.0f alpha:1.0f]
#define IOS7_OR_LATER   ( [[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending )
#define THEME_COLOR [UIColor colorWithRed:246/255.0 green:74/255.0 blue:76/255.0 alpha:1.0]
#define ImageFromResource(x) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:x ofType:nil]]
#define theApp ((AppDelegate *)[[UIApplication sharedApplication] delegate])
#define weaken(object) __typeof__(self) __weak weakSelf = object
#define strongen(object) __typeof__(self) __strong strongSelf = object

#define IS_IPHONE4 (([[UIScreen mainScreen] bounds].size.height - 480) ? NO : YES)
#define IS_IPHONE5 (([[UIScreen mainScreen] bounds].size.height - 568) ? NO : YES)
#define IS_IPHONE6 (([[UIScreen mainScreen] bounds].size.height - 667) ? NO : YES)
#define IS_IPHONE6PLAS (([[UIScreen mainScreen] bounds].size.height - 736) ? NO : YES)


#define DEVICE_SIZE [[UIScreen mainScreen] bounds].size
#define DEVICE_H ([[UIScreen mainScreen] bounds].size.height)
#define DEVICE_W ([[UIScreen mainScreen] bounds].size.width)

#define CONTENTINSET_TOP 44
#define CONTENTINSET_BOTTOM 49
#define IOS7_STATUS_BAR_HEGHT (kSystemVersion>=7 ? 20.0f : 0.0f)
#define kImageVector (0.56)
#define COLOR_RGB(r,g,b) [UIColor colorWithRed:(r/255.0f) green:(g/255.0f) blue:(b/255.0f) alpha:1]//userdefault
#define BUNDLE_FILE_PATH(filename)  [[NSBundle mainBundle] pathForAuxiliaryExecutable:filename]

#define USER_DEFAULT [NSUserDefaults standardUserDefaults]

#define SCREENWIDTH [UIScreen mainScreen].bounds.size.width
#define SCREENHEIGHT [UIScreen mainScreen].bounds.size.height
#define CURRENTRATIO (SCREENWIDTH/414)


#define kdeviceid ([OpenUDID value])

#define kBuildVersion ([[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *) kCFBundleVersionKey])
#define kAppVersion ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])

#define kdevicemodel ([[UIDevice currentDevice] model])
//系统版本
#define kSystemVersion ([[UIDevice currentDevice] systemVersion].intValue)
#define kDevicedistrtype 1
#define kAppversion ([[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *) kCFBundleVersionKey])

//颜色RGB
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]

/* 根据size生成字体Font */
#define kFont(s) ([UIFont fontWithName:@"HelveticaNeue-Light" size:s])
#define kBFont(s) ([UIFont fontWithName:@"HelveticaNeue-Bold" size:s])
#define kNFont(s) ([UIFont fontWithName:@"HelveticaNeue" size:s])
#define kSysFont(s) ([UIFont systemFontOfSize:s])

#define KEY_WINDOW  [[UIApplication sharedApplication]keyWindow]
/*
 定义一些修改逻辑宏.
    定义这些宏是为了在两个版本迭代之间,做一些改动.将代码丢失率降到最低.
 */
#define LMH_Main_Page_Update_logic 1 // 1-修改首页的架构,以TabBarController样式.  0.没有TabBarController 的样式.

CG_INLINE BOOL stringIsEmpty(NSString *string) {
    if([string isKindOfClass:[NSNull class]]){
        return YES;
    }
    if (string == nil) {
        return YES;
    }
    if ([string isEqualToString:@"(null)"]) {
        return YES;
    }
    NSString *text = [string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if ([text length] == 0) {
        return YES;
    }
    return NO;
}


