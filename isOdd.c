//
//  isOdd.c
//  hello
//
//  Created by Bytedance on 2022/2/7.
//

#include "isOdd.h"
#include <stdio.h>

void isOdd() {
    for (int i = 0; i<20; i++) {
        if(i%2 ==0) {
            printf("%d is odd \n", i);
        } else {
            printf("%d is not odd \n", i);
        }
        if(i % 3 == 0) {
            printf("%d is 3 \n", i);
        }
    }
}
