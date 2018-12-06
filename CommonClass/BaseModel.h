//
//  BaseModel.h
//  RenCaiYingHang
//
//  Created by Chan on 2017/12/7.
//  Copyright © 2017年 Chan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BaseModel : NSObject <NSCoding>

- (instancetype)initWithDictionary:(NSDictionary *)dic;

@end
