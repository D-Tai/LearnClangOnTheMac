//
//  chapterNine.h
//  hello
//
//  Created by Bytedance on 2022/3/17.
//

#ifndef chapterNine_h
#define chapterNine_h

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
# define kMaxLineLength 200
#define kMaxNumber 3999
#define kMinNumber 1
#define kMaxRomanNumberLength 15


extern void chapterNine(void);
void countWords(void);
int readLine(char *line);
void romanNumber(void);
char *numberToRomanNumeral(int number, char romanNumeral[]);

#endif /* chapterNine_h */
