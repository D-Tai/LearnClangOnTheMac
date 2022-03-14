//
//  chapterEleven.h
//  hello
//
//  Created by Bytedance on 2022/3/10.
//

#ifndef chapterEleven_h
#define chapterEleven_h

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>        // getpwuid()
#include <unistd.h>     // getuid()

extern void handleFile(void);
void readAndPrintFile(char filePath[]);
void writeFile(char filePath[], char content[], char mode[]);

#endif /* chapterEleven_h */
