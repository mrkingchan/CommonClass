//
//  UIImage+ImageCate.m
//  RenCaiYingHang
//
//  Created by Jason on 2018/12/6.
//  Copyright © 2018年 Macx. All rights reserved.
//

#import "UIImage+ImageCate.h"

@implementation UIImage (ImageCate)

+ (UIImage*)imageWithColor:(UIColor*)color withSize:(CGSize)size {
    CGRect rect= CGRectMake(0.0f,0.0f,size.width,size.height);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context=UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage*theImage=UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return theImage;
}


@end
