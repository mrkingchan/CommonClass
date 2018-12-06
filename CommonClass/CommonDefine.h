//
//  CommonDefine.h
//  CommonClass
//
//  Created by Jason on 2018/12/6.
//  Copyright © 2018年 Chan. All rights reserved.
//

#ifndef CommonDefine_h
#define CommonDefine_h

#define kAppWindow  [[[UIApplication sharedApplication] delegate] window]
#define AppVersion  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

#define AppName  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]

#define kIOS11Later [[[UIDevice currentDevice] systemVersion] floatValue] >= 11.0
#define iToastLoading(xxx)     [SVProgressHUD showWithStatus:xxx]
#define iToastHide   if ([SVProgressHUD isVisible]) {\
[SVProgressHUD dismiss]; \
}

#define AdaptiveRate [UIScreen mainScreen].bounds.size.height / 736
#define fontScale kScreenWidth/375
#define kFontSize(size) [UIFont systemFontOfSize:size*fontScale]

#define kNavBarTintColor UIColorHex(F05B48)
#define kWhiteColor [UIColor whiteColor]

#define UIIMAGE(named) [UIImage imageNamed:named]

// MARK: - frame &adapter
#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define Rect(x,y,w,h) CGRectMake(x*fontScale, y*AdaptiveRate, w*fontScale, h*AdaptiveRate)
#define kStatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height
#define KNavBarHeight (kStatusBarHeight+44)
#define KToolHeight (kDevice_Is_iPhoneX?83:49)
#define kDevice_Is_iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define kBodyHeight     (kScreenHeight - 44 - 20)
#define kMiddleHeight   (kBodyHeight - 49)

#define kTabbarHeight       49
#define kSearchBarHeight    45
#define kStatusBarHeight    20
#define kNavigationHeight   44
#define ScreenMutiple (iPhone6?1.171875:(iPhone6plus?1.29375:1))


// MARK: - scrollViewInsets
#define  adjustsScrollViewInsets_NO(scrollView,vc)\
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
if ([UIScrollView instancesRespondToSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:")]) {\
[scrollView   performSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:") withObject:@(2)];\
} else {\
vc.automaticallyAdjustsScrollViewInsets = NO;\
}\
_Pragma("clang diagnostic pop") \
} while (0)

// MARK: - weak &strong
#define kSelfWeak __weak typeof(self) weakSelf = self
#define kSelfStrong __strong __typeof__(weakSelf) strongSelf = weakSelf

#pragma mark -   weakify( x ) && strongify( x )
/// block self
#ifndef    weakify
#if __has_feature(objc_arc)

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x; \
_Pragma("clang diagnostic pop")

#else

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __block __typeof__(x) __block_##x##__ = x; \
_Pragma("clang diagnostic pop")

#endif
#endif

#ifndef    strongify
#if __has_feature(objc_arc)

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __weak_##x##__; \
_Pragma("clang diagnostic pop")

#else

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __block_##x##__; \
_Pragma("clang diagnostic pop")

#endif


// MARK: - color
#define kColorWhite [UIColor whiteColor]
#define kColorClear [UIColor clearColor]
#define kColorRed [UIColor redColor]
#define kColorBlue [UIColor blueColor]
#define kColorGreen [UIColor greenColor]
#define kColorBlack [UIColor blackColor]
#define kColorGray [UIColor grayColor]
#define kColorLightGray [UIColor lightGrayColor]
#define kColorOrange [UIColor orangeColor]
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1]
#define kColor(R,G,B)  [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:1]
#define UIColorHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
// 设置颜色与透明度 示例：UIColorHEX_Alpha(0x26A7E8, 0.5)
#define UIColorHex_Alpha(rgbValue, al) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:al]
// 设置颜色 示例：UIColorHexStr(@"#7b7b7b");
#define UIColorHexStr(hex)     [UIColor colorWithHexString:hex]


// MARK: - formatter
#define kDateFormatDefault     @"yyyy-MM-dd HH:mm:ss"
#define kDateFormat_yyMdHm     @"yy-MM-dd HH:mm"
#define kDateFormat_yyyyMdHm   @"yyyy-MM-dd HH:mm"
#define kDateFormat_yMd        @"yyyy-MM-dd"
#define kDateFormat_MdHms      @"MM-dd HH:mm:ss"
#define kDateFormat_MdHm       @"MM-dd HH:mm"
#define kDateFormat_MdHm1      @"MM/dd HH:mm"
#define kDateFormatTime        @"HH:mm:ss"
#define kDateFormat_MSS        @"mm:ss:SSS"
#define kDateFormat_Hm         @"HH:mm"
#define kDateFormat_Md         @"MM-dd"
#define kDateFormat_yyMd       @"yy-MM-dd"
#define kDateFormat_YYMMdd     @"yyyyMMdd"
#define kDateFormat_yyyyMdHms  @"yyyyMMddHHmmss"
#define kDateFormat_yyyyMMddHHmmssSSS   @"yyyy-MM-dd HH:mm:ss:SSS"
#define kDateFormat_yyyyMdHm_ForPoint   @"yyyy.MM.dd HH:mm"
#define kDateFormat_yyyyMMddHHmm        @"yyyy/MM/dd HH:mm"
#define KDateFormat_yyyy @"yyyy"
#define kDateFormat_yyyyMM @"yyyy-MM"
#define kDateFormat_yyyMMddWeek @"yyyy-MM-dd EEE"


// MARK: - shorcut
#define kURLWithString(str)  [NSURL URLWithString:str]
#define kGetUserDefaults(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]
#define kUserDefaults(key, value) [[NSUserDefaults standardUserDefaults] setObject:value forKey:key]
#define kSynchronize [[NSUserDefaults standardUserDefaults] synchronize]
#define kRemoveOUserDefaults(key) [[NSUserDefaults standardUserDefaults] removeObjectForKey:key]

// MARK: - LOG

#ifndef __OPTIMIZE__
#define NSLog(...) NSLog(__VA_ARGS__)
#define DLog(fmt, ...) {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#else
#define DLog(...)
#define NSLog(...) {}
#endif


// MARK: - CG_INLINE method
CG_INLINE UIColor *UIColorRGB(float R,float G,float B) {
    return [UIColor colorWithRed:R/255.0
                           green:G/255.0
                            blue:B/255.0
                           alpha:1.0];
}

CG_INLINE void kUserDefaultSet(id value,NSString *key) {
    [kUserDefaults setObject:value forKey:key];
    [kUserDefaults synchronize];
}

CG_INLINE id  kUserDefaultsForKey(NSString * key) {
    return [kUserDefaults objectForKey:key];
}

CG_INLINE NSString *kAppVersion() {
    return [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
}

CG_INLINE NSURL *kURL(NSString *urlStr) {
    return [NSURL URLWithString:urlStr];
}

// MARK: - 判断是否空
CG_INLINE BOOL kEmpty(id value) {
    if ([value isKindOfClass:[NSNull class]] || value == nil) {
        return YES;
    } else if ([value isKindOfClass:[NSString class]]) {
        return [value isEqualToString:@""] || [[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length] == 0;
    }else if ([value isKindOfClass:[NSArray class]]) {
        return [(NSArray *)value count] == 0;
    }else if ([value isKindOfClass:[NSDictionary class]]) {
        return [(NSDictionary *)value count] == 0;
    } else {
        return YES;
    }
}

// MARK: - 转json
CG_INLINE id kJson(id value) {
    id resultValue = nil;
    if ([value isKindOfClass:[NSString class]]) {
        resultValue = [NSJSONSerialization JSONObjectWithData:[((NSString *)value) dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingMutableLeaves error:nil];
        
    } else if ([value isKindOfClass:[NSData class]]) {
        resultValue = [NSJSONSerialization JSONObjectWithData:((NSData *)value) options:NSJSONReadingMutableLeaves error:nil];
    }
    return resultValue == nil?  @{}:resultValue;
}

#warning this class is to code the common UI components more convnient, and @copy right by mr kingchan！

/**
 return a common UIView with given configuration
 
 @param superView superView description
 @param rect rect description
 @param backgroundColor backgroundColor description
 @param clipToBounds clipToBounds description
 @param radius radius description
 @return  a common UIView with given configuration
 */
CG_INLINE UIView *kViewWithConfiguraion(id superView,
                                        CGRect rect,
                                        UIColor *backgroundColor,
                                        BOOL clipToBounds,
                                        CGFloat radius) {
    UIView *subView = [[UIView alloc] initWithFrame:rect];
    subView.backgroundColor = backgroundColor;
    subView.clipsToBounds  = clipToBounds;
    if (clipToBounds) {
        subView.layer.cornerRadius = radius;
    }
    if (superView) {
        [superView addSubview:subView];
    }
    return subView;
}

/**
 return imageView with given configuration
 
 @param superView superView description
 @param rect rect description
 @param image image description
 @param contentModel contentModel description
 @return imageView with given configration
 */
CG_INLINE UIImageView *kImageViewWithConfiguration(id superView,CGRect rect,UIImage *image,UIViewContentMode contentModel) {
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:rect];
    imageView.image = image;
    imageView.contentMode = contentModel;
    if (superView) {
        [superView addSubview:imageView];
    }
    return imageView;
}

/**
 return button With radius
 
 @param superView superView description
 @param rect rect description
 @param textColor textColor description
 @param backgroundColor backgroundColor description
 @param content content description
 @param textFont textFont description
 @param radius radius description
 @return button With radius
 */
CG_INLINE UIButton *kButtonWithRadiusConfiguration(id superView,CGRect rect,UIColor *textColor,UIColor *backgroundColor,NSString *content,UIFont *textFont,CGFloat radius) {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = rect;
    button.titleLabel.font = textFont;
    button.titleLabel.textAlignment = 1;
    [button setTitleColor:textColor forState:UIControlStateNormal];
    [button setTitle:content forState:UIControlStateNormal];
    button.backgroundColor = backgroundColor;
    if (superView) {
        [superView addSubview:button];
    }
    button.clipsToBounds = YES;
    button.layer.cornerRadius = radius;
    return button;
}


/**
 return a button With given configuration
 
 @param superView superView description
 @param rect rect description
 @param textColor textColor description
 @param backgroundColor backgroundColor description
 @param content content description
 @param textFont textFont description
 @return  return a button With given configuration
 
 */
CG_INLINE UIButton *kButtonWithCommonConfiguration(id superView,CGRect rect,UIColor *textColor,UIColor *backgroundColor,NSString *content,UIFont *textFont) {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = rect;
    button.titleLabel.font = textFont;
    button.titleLabel.textAlignment = 1;
    [button setTitleColor:textColor forState:UIControlStateNormal];
    [button setTitle:content forState:UIControlStateNormal];
    button.backgroundColor = backgroundColor;
    if (superView) {
        [superView addSubview:button];
    }
    return button;
}


/**
 return the label with radiuds
 
 @param superView superView description
 @param rect rect description
 @param backgroundColor backgroundColor description
 @param textColor textColor description
 @param textAlignment textAlignment description
 @param font font description
 @param text text description
 @param cornerRadius cornerRadius description
 @return return the label with radiuds
 */
CG_INLINE  UILabel *kLabelWithCornerRadius(id superView,
                                           CGRect rect,
                                           UIColor *backgroundColor,
                                           UIColor *textColor,
                                           NSTextAlignment textAlignment,
                                           UIFont *font,
                                           NSString *text,CGFloat cornerRadius) {
    UILabel *label = [[UILabel alloc] initWithFrame:rect];
    label.font = font;
    label.textColor = textColor;
    label.text = text;
    label.textAlignment = textAlignment;
    label.backgroundColor = backgroundColor;
    if (superView) {
        [superView addSubview:label];
    }
    label.clipsToBounds = YES;
    label.layer.cornerRadius = cornerRadius;
    return label;
}


/**
 return the label with given configuration
 
 @param superView superView description
 @param rect rect description
 @param backgroundColor backgroundColor description
 @param textColor textColor description
 @param textAlignment textAlignment description
 @param font font description
 @param text text description
 @return the label with given configuration
 */
CG_INLINE UILabel *kLabelWithConfiguration(id superView,
                                           CGRect rect,
                                           UIColor *backgroundColor,
                                           UIColor *textColor,
                                           NSTextAlignment textAlignment,
                                           UIFont *font,
                                           NSString *text) {
    UILabel *label = [[UILabel alloc] initWithFrame:rect];
    label.font = font;
    label.textColor = textColor;
    label.text = text;
    label.textAlignment = textAlignment;
    label.backgroundColor = backgroundColor;
    if (superView) {
        [superView addSubview:label];
    }
    return label;
    
}
CG_INLINE UICollectionView *kCollectionViewWithConfiguraiton(id superView,CGRect rect,UICollectionViewFlowLayout *layout,Class cellClass,id <UICollectionViewDataSource>dataSource,id  <UICollectionViewDelegate>delegate) {
    UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:rect collectionViewLayout:layout];
    collectionView.backgroundColor = [UIColor whiteColor];
    if (dataSource) {
        collectionView.dataSource = dataSource;
    }
    if (delegate) {
        collectionView.delegate = delegate;
    }
    if (cellClass) {
        [collectionView registerClass:cellClass forCellWithReuseIdentifier:NSStringFromClass(cellClass)];
    }
    if (superView) {
        [superView addSubview:collectionView];
    }
    return collectionView;
}

/**
 create tableView with given configuration
 @param superView superView
 @param rect rect description
 @param style style description
 @param <UITableViewDataSource>dataSource <UITableViewDataSource>dataSource description
 @param <UITableViewDelegate>delegate <UITableViewDelegate>delegate description
 @param cellClass cellClass description
 @return tableView with the given configuration
 */
CG_INLINE  UITableView *kTableViewWithConfiguration(id superView,
                                                    CGRect rect,
                                                    UITableViewStyle style,
                                                    id <UITableViewDataSource>dataSource,
                                                    id <UITableViewDelegate>delegate,
                                                    Class cellClass) {
    UITableView *tableView = [[UITableView alloc] initWithFrame:rect style:style];
    if (delegate) {
        tableView.delegate = delegate;
    }
    if (dataSource) {
        tableView.dataSource = dataSource;
    }
    if (superView) {
        [superView addSubview:tableView];
    }
    tableView.tableFooterView = [UIView new];
    tableView.backgroundColor = [UIColor whiteColor];
    [tableView registerClass:cellClass forCellReuseIdentifier:NSStringFromClass(cellClass)];
    return tableView;
}


/**
 return a UICollectionViewFlowLayout with the given configuration
 @param itemW itemW description
 @param itemH itemH description
 @param lineSpace lineSpace description
 @param itemInterSpace itemInterSpace description
 @param sectionInsets sectionInsets description
 @return a UICollectionViewFlowLayout with the given configuration
 */
CG_INLINE  UICollectionViewFlowLayout *kLayoutWithCongiguration(CGFloat itemW,CGFloat itemH,CGFloat lineSpace,CGFloat itemInterSpace,UIEdgeInsets sectionInsets) {
    UICollectionViewFlowLayout *layout = [UICollectionViewFlowLayout new];
    layout.itemSize = CGSizeMake(itemW, itemH);
    layout.minimumLineSpacing = lineSpace;
    layout.minimumInteritemSpacing = itemInterSpace;
    layout.sectionInset = sectionInsets;
    return layout;
}

// MARK: - 判断是否空
CG_INLINE BOOL kEmpty(id value) {
    if ([value isKindOfClass:[NSNull class]] || value == nil) {
        return YES;
    } else if ([value isKindOfClass:[NSString class]]) {
        return [value isEqualToString:@""] || [[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length] == 0;
    }else if ([value isKindOfClass:[NSArray class]]) {
        return [(NSArray *)value count] == 0;
    }else if ([value isKindOfClass:[NSDictionary class]]) {
        return [(NSDictionary *)value count] == 0;
    } else {
        return YES;
    }
}

// MARK: - 转json
CG_INLINE id kValueToJson(id value) {
    id resultValue = nil;
    if ([value isKindOfClass:[NSData class]]) {
        resultValue = [NSJSONSerialization JSONObjectWithData:value options:NSJSONReadingMutableLeaves error:nil];
    } else if ([value isKindOfClass:[NSString class]]) {
        resultValue = [NSJSONSerialization JSONObjectWithData:[value dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingMutableLeaves error:nil];
    } else {
        resultValue = value;
    }
    return resultValue;
}

CG_INLINE void kStatusBarLoading(BOOL visible) {
    [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:visible];
}

CG_INLINE UIFont *kFont(CGFloat size) {
    return [UIFont systemFontOfSize:size];
}

CG_INLINE UIFont *kFontBold(CGFloat size) {
    return [UIFont boldSystemFontOfSize:size];
}

#endif /* CommonDefine_h */
