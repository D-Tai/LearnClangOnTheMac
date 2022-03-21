//
//  chapterNine.c
//  hello
//
//  Created by Bytedance on 2022/3/17.
//

#include "chapterNine.h"

void chapterNine(void) {
    printf("========== Divide Line ============= \n");
    printf("select program: 1: countWords; 2: romanNumber \n");
    int select;
    scanf("%10d", &select);
    fflush(stdin);
    if(select == 1) {
        countWords();
    } else {
        romanNumber();
    }
};

void romanNumber(void){
    printf("Please input a number between %d and %d \n", kMinNumber, kMaxNumber);
    int number;
    char romanNumeral[kMaxRomanNumberLength+1];
    scanf("%d", &number);
    
    if(number> kMaxNumber || number < kMinNumber) {
        printf("The number must between %d and %d \n", kMinNumber, kMaxNumber);
        romanNumber();
        return;
    }
    numberToRomanNumeral(number, romanNumeral);
    printf("Roman Numeral of %d is %s \n", number, romanNumeral);
}

char *numberToRomanNumeral(int number, char romanNumeral[]) {
    static char roman[] = "IVXLCDM";
    
//    romanNumeral[kMaxRomanNumberLength] = '\0';
    char resultContainer[kMaxRomanNumberLength+1];
    resultContainer[kMaxRomanNumberLength] = '\0';
    char *result;
    result = &resultContainer[kMaxRomanNumberLength];
    int numeral = 0;
    while (number!=0) {
        int digit = number % 10;
        switch (digit) {
            case 0:
                break;
            case 3:
                *--result = roman[ numeral ];
            case 2:
                *--result = roman[ numeral ];
            case 1:
                *--result = roman[ numeral ];
                break;
            case 4:
                *--result = roman[ numeral +1];
                *--result = roman[ numeral];
                break;
            case 8:
                *--result = roman[ numeral];
            case 7:
                *--result = roman[ numeral];
            case 6:
                *--result = roman[ numeral];
            case 5:
                *--result = roman[ numeral+1];
                break;
            case 9:
                *--result = roman[ numeral+2];
                *--result = roman[ numeral];
                break;
            default:
                break;
        }
        number = number/10;
        numeral += 2;
    }
    strcpy(romanNumeral, result);
    return romanNumeral;
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
    bool newLine = false;
    printf("Please input something: \n");
    while ((c = getchar())!= EOF && inputLength < kMaxLineLength) {
        *line++ = c;
        inputLength++;
        if(c == '\n') {
            if(newLine) {
                break;
            } else {
                newLine = true;
            }
        } else {
            newLine = false;
        }
    }
    *line = '\0';
    return inputLength;
}
