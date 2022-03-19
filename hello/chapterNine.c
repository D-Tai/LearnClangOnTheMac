//
//  chapterNine.c
//  hello
//
//  Created by Bytedance on 2022/3/17.
//

#include "chapterNine.h"

void chapterNine(void) {
    printf("========== Divide Line ============= \n");
    countWords();
};

void countWords(void) {
    char line[kMaxLineLength];
    int charNum = readLine(line);
    int wordNum = 0;
    bool inWord = false;
    printf("Char count is %d, line is %s.\n", charNum, line);
    for (int i = 0; i<charNum; i++) {
        if(!inWord && !isspace(line[i])) {
            inWord = true;
            wordNum++;
        } else if(isspace(line[i])){
            inWord = false;
        }
    }
    printf("Word count is %d.\n", wordNum);
}

int readLine(char *line) {
    int inputLength = 0;
    int c;
    printf("Please input something: \n");
    while ((c = getchar())!= EOF && inputLength < kMaxLineLength && c != '\n') {
        *line++ = c;
        inputLength++;
    }
    *line = '\0';
    return inputLength;
}
