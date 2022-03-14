//
//  capterTen.c
//  hello
//
//  Created by Bytedance on 2022/3/8.
//

#include "chapterTen.h"

static struct DVDInfo *gHead;
static struct DVDInfo *gTail;

void dataStructure(void){

    printf("hello chapter 10 \n");
    linkListAndMalloc();
    return;
    trySruct();
    multiArray();
}

void linkListAndMalloc(void) {
    char cmd;
    do {
        printf("\n------------------------\n\n");
        cmd = getCommand();
        printf("Your command is: %c \n", cmd);
        if(cmd == 'n') {
            printf(" ---- Start adding new DVD ---- \n");
            struct DVDInfo *newDVD = (struct DVDInfo *)malloc(sizeof(struct DVDInfo));
            char rating[10];
            char buffer[kMaxTitleLength];
            printf("Input the title: \n");
            fgets(buffer, kMaxTitleLength, stdin);
            strcpy(newDVD->title, trimStr(buffer));
            printf("Input the comment: \n");
            fgets(buffer, kMaxCommentLength, stdin);
            strcpy(newDVD->comment, trimStr(buffer));
            do{
                printf("Input the rate between 1-10: \n");
                fgets(rating, sizeof(rating), stdin);
                newDVD->rating = atoi(trimStr(rating));
            } while(newDVD->rating>10 || newDVD->rating<1);
            printf("You just add a new DVD named %s \n", newDVD->title);
            addToList(newDVD);
        } else if (cmd == 'l') {
            printf("Here is all DVDs: \n");
            walkWhtoughTheLinkList();
        } else if(cmd == 'q') {
            break;
        } else {
            printf("I can't understand your command, please try again.\n");
        }
    } while (cmd != 'q');
    return;
}

void walkWhtoughTheLinkList(void) {
    struct DVDInfo *current = gHead;
    while (current != NULL) {
        printf("title: %s, comment: %s, rating: %d \n", (*current).title, current->comment, current->rating);
        current = current->next;
    }
}

void addToList(struct DVDInfo *item) {
    if(gHead == NULL) {
        gHead = item;
        gTail = gHead;
    } else {
        gTail->next = item;
        gTail = item;
    }
    gTail->next = NULL;
}

char getCommand(void) {
    printf("Please input your command: [n for new, q for exit, l for list]\n");
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    return *trimStr(input);
}

char *trimStr(char line[]) {
    size_t length = strlen(line);
    while (isspace(line[length-1])) {
        line[length-1]--;
        length--;
    };
    while (isspace(line[0])) {
        line++;
    }
    return line;
};

void trySruct() {
    struct DVDInfo myDVDInfo;
    myDVDInfo.rating = 9;
    printf("size of myDVDInfo.title   is %4zu \n", sizeof(myDVDInfo.title));
    printf("size of myDVDInfo.comment is %4zu \n", sizeof(myDVDInfo.comment));
    printf("size of myDVDInfo.rating  is %4zu \n", sizeof(myDVDInfo.rating));
    printf("size of myDVDInfo         is %4zu \n", sizeof(myDVDInfo));
    printf("address of myDVDInfo: %28p \n", &myDVDInfo);
    printDVDStruct(&myDVDInfo, myDVDInfo);
}

void printDVDStruct(struct DVDInfo *dvdInfo, struct DVDInfo dvdInfoCpy) {
    printf("title: %s, comment: %s, rating: %d \n", (*dvdInfo).title, dvdInfo->comment, dvdInfo->rating);
    printf("address of dvdInfo   : %28p \n", &(dvdInfo->rating));
    printf("address of dvdInfoCpy: %28p \n", &(dvdInfoCpy.rating));
}

void multiArray() {
    char title[kMaxDvDs][kMaxTitleLength];
    char *testStr;
    size_t bufSize = 32;
    testStr = (char *)malloc(bufSize * sizeof(char));
    
    getline(&testStr, &bufSize, stdin);
    printf("here is %s", testStr);
//    return;
    for (int i = 0; i < kMaxDvDs; i++) {
        printf("Input a DVD: \n");
        fgets(title[i], kMaxTitleLength, stdin);
        title[i][strlen(title[i])-1] = '\0';
//        printf("Input the comment: \n");
//        fgets(comment[i], kMaxCommentLength, stdin);
//        printf("input the rate, ranging 1-10:");
//        scanf("%d", &rate[i]);
    }
    printDVDTitle(title);
}

void printDVDTitle(char title[][kMaxTitleLength]) {
    for (int i = 0; i<kMaxDvDs; i++) {
        printf("DVD #%d: %s\n", i+1, title[i]);
    }
}

