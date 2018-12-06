//
//  BaseModel.m
//  RenCaiYingHang
//
//  Created by Chan on 2017/12/7.
//  Copyright © 2017年 Chan. All rights reserved.
//

#import "BaseModel.h"
#import <objc/runtime.h>

@implementation BaseModel

// MARK: - 未定义的属性
- (void)setValue:(id)value forUndefinedKey:(NSString *)key {
    
}

// MARK: - json->model
- (instancetype)initWithDictionary:(NSDictionary *)dic {
    if (self = [super init]) {
        //转model
//        [self mj_setKeyValues:dic];
    }
    return self;
}

// MARK: - runtime解编码
- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    unsigned int count = 0;
    id model = [[self class] new];
    Ivar *vars = class_copyIvarList([self class], &count);
    for (int i = 0; i< count; i ++) {
        NSString *key = [NSString stringWithUTF8String:ivar_getName(vars[i])];
        id value = [aDecoder valueForKey:key];
        if (value != nil) {
            [model setValue:value forKey:key];
        }
    }
    return  model;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    id model = [[self class] new];
    unsigned int count = 0;
    Ivar *vars = class_copyIvarList([self class], &count );
    for (int i = 0 ;  i < count; i ++) {
        NSString *key = [NSString  stringWithUTF8String:ivar_getName(vars[i])];
    }
}
@end
