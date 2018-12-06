//
//  UIColor+HexColor.h
//  RenCaiYingHang
//
//  Created by Jason on 2018/12/6.
//  Copyright © 2018年 Macx. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (HexColor)

+ (UIColor*)colorWithHex:(NSString *)colorStr alpha:(CGFloat)alphaValue;

@end
