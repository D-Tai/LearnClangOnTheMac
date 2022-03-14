//
//  chapterTen.h
//  hello
//
//  Created by Xu Xiaofei on 2022/3/8.
//

#ifndef chapterTen_h
#define chapterTen_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define kMaxDvDs 4
#define kMaxTitleLength 256
#define kMaxCommentLength 256

struct DVDInfo {
    int rating;
    char title[kMaxTitleLength];
    char comment[kMaxCommentLength];
    struct DVDInfo *next;
};

void dataStructure(void);
void multiArray(void);
void printDVDTitle(char title[][kMaxTitleLength]);
void trySruct(void);
void printDVDStruct(struct DVDInfo *dvdInfo, struct DVDInfo dvdInfoCpy);
void linkListAndMalloc(void);
char getCommand(void);
char *trimStr(char line[]);
void addToList(struct DVDInfo *item);
void walkWhtoughTheLinkList(void);

#endif /* chapterTen_h */
