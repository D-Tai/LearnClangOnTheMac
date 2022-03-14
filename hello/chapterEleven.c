//
//  chapterEleven.c
//  hello
//
//  Created by Bytedance on 2022/3/10.
//

#include "chapterEleven.h"

void handleFile() {
    printf("hello file. \n");
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    int usr = getuid();
    struct passwd *pwd = getpwuid(usr);
    printf("User's directory is %s \n", pwd->pw_dir);
    chdir(pwd->pw_dir);
    char filePath[] = "./code/hello/hello/brick.txt";
    printf("\nBefore Write: \n");
    readAndPrintFile(filePath);
    char appendContent[] = "Hello World";
    writeFile(filePath, appendContent, "a");
    printf("\nAfter Write: \n");
    readAndPrintFile(filePath);
    writeFile(filePath, "Another brick in the wall.", "w");
}

void writeFile(char filePath[], char content[], char mode[]) {
    FILE *file;
    file = fopen(filePath, mode);
    if(file == NULL) {
        printf("failed to write the file. \n");
        return;
    }
    fputc('\n', file);

    for (int i = 0; i<strlen(content); i++) {
        fputc(content[i], file);
    }
    fclose(file);
}

void readAndPrintFile(char filePath[]){
    FILE  *file;
    file = fopen(filePath, "r");
    if(file == NULL) {
        printf("failed to read the file. \n");
        return;
    }

//    char content[1000];
//    fgets(content, sizeof(content), file);
//    printf("file content is: %s \n", content);
    char c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    printf("\n");
    fclose(file);
}
