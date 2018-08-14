//
//  crc32.h
//  crc32
//
//  Created by 石志超 on 2018/8/6.
//  Copyright © 2018年 石志超. All rights reserved.
//

#ifndef crc32_h
#define crc32_h

#import <stdio.h>
#import <stdint.h>

void make_crc32_table(void);
uint32_t crc32(uint8_t *data, uint32_t length);

#endif /* crc32_h */
