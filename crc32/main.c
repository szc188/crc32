#import <stdio.h>
#import "crc32.h"

int main() {
    make_crc32_table(); //初始化crc 数组(程序开始时调用一次即可)
    
    uint8_t buffer[16]; //要加密的内容
    for (int i = 0; i < sizeof(buffer); i++) {  //填充加密的内容
        buffer[i] = i + 1;
    }
    
    uint32_t result = crc32(buffer, sizeof(buffer));    //计算crc
    
    printf("crc: %08X\r\n", result);    //输出结果
    
    return 0;
}
