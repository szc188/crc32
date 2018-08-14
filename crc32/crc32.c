//
//  crc32.c
//  crc32
//
//  Created by 石志超 on 2018/8/6.
//  Copyright © 2018年 石志超. All rights reserved.
//

#import "crc32.h"

static uint32_t crc32_table[256];

void make_crc32_table(void) {
    for(uint32_t i = 0; i < 256; i++) {
        crc32_table[i] = i;
        for(uint32_t bit = 0; bit < 8; bit++)
            crc32_table[i] = crc32_table[i] & 1 ? crc32_table[i] >> 1 ^ 0xEDB88320 : crc32_table[i] >> 1;
    }
}

uint32_t crc32(uint8_t *data, uint32_t length) {
    uint32_t crc = 0xFFFFFFFF;
    while (length--)
        crc = (crc >> 8) ^ (crc32_table[(crc ^ *data++) & 0xff]);
    crc ^= 0xFFFFFFFF;
    return crc;
}
