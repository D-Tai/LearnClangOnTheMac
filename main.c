//
//  main.c
//  hello
//
//  Created by Bytedance on 2022/1/29.
//

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <strings.h>
#include "chapterNine.h"
#include "chapterTen.h"
#include "chapterEleven.h"

void sayHello(int number);
void isOddFoo(void);
void nextPrime(int num);
bool checkPrime(int num);
void primeBwtween1And100(void);
void first100Prime(void);
int factor(int number);
void chapterSeven(void);
void addOne(int *number);
int multipyIt(int myVar);
int doubleIt(int myVar);
void chapterEight(void);
int rollOnce(void);
void printfForDice(int result[]);
void printFullName(char firstName[], char lastName[]);

int main(int argNum, char** arg) {
    printf("The number of arguments is %d \n", argNum);
    printf("You are runing chapter %s \n", arg[1]);
    int chapter = atoi(arg[1]);
    switch (chapter) {
        case 9:
            chapterNine();
            break;
        case 10:
            dataStructure();
            break;
        case 11:
            handleFile();
            break;
        default:
            break;
    }
    return 0;
    int sum = 0;
    for (int i = 0; i<=10; i++) {
        sum += i;
    }
    sayHello(666);
    printf("the sum of 1 to 10 is %d \n", sum);
    
    int myInt;
    myInt = 3 * 2;
    printf("3 * 2 = %d\n", myInt);
    myInt += 1;
    printf("myInt+=1 %d\n", myInt);
    myInt -= 5;
    printf("myInt -=5 %d \n", myInt);
    myInt *= 10;
    printf("myInt *=10 %d \n", myInt);
    myInt /= 4;
    printf("myInt /= 4 %d \n", myInt);
    myInt /=2;
    printf("myInt /= 2 %d \n", myInt);
    printf("myInt++ %d \n", myInt++);
    printf("++myInt %d \n", ++myInt);
    bool isNumber = true;
    bool notNumber = !isNumber;
    printf("notNumber is %d", notNumber);
    int i = 0;
    while (++i<3) {
        printf("while loops %d times \n", i);
    }
    int j;
    for (j = 1; j<3; j++) {
        printf("for loops %d times \n", j);
    }
    printf("i is %d \n", i);
    printf("j is %d \n", j);
    switch (i) {
        case 3:
            printf("i is 3 \n");
        break;
        case 4:
            printf("i is 4 \n");
            break;
        default:
            printf("i is ? \n");
    }
    isOddFoo();
    nextPrime(235);
    primeBwtween1And100();
    first100Prime();
    int targetNum, firstFactor, anotherFactor;
    targetNum = 69;
    firstFactor = factor(targetNum);
    anotherFactor = targetNum / firstFactor;
    printf("factors: %d, %d \n", firstFactor, anotherFactor);
    printf("targetNum is prime: %d \n", firstFactor == 1);
    int a = 100;
    long int b = 1000000000000000;
    size_t c = sizeof(a);
    printf("sizeof a: %zu \n", c);
    printf("b is: %li \n", b);
    float d = 1234.567890123456789f;
    printf("d is %f \n", d);
    printf("d is %30.20f \n", d);
    double e = 1234.567890123456789;
    printf("e is %25.15f \n", e);
    long double f = 1234.567890123456789L;
    printf("f is %.15Lf \n", f);
    chapterSeven();
    for (int m = 1; m<10; m++) {
        int isOdd = m%2;
        if(isOdd) {
            printf("%d is odd \n", m);
        }
    }
    chapterEight();
//    char something[20];
//    printf("Please input something: \n");
//    scanf(" %s", something);
//    printf("You just input: %s \n", something);
    chapterNine();
    return 0;
}

int factor(int targetNum) {
    int factor = 1;
    int anotherFactor = targetNum;
    for (int i = 2; i<targetNum; i++) {
        if(targetNum % i == 0) {
            factor = i;
            anotherFactor = targetNum / i;
            return factor;
        }
    }
    return factor;
}

void sayHello(int number){
    printf("hello %d\n", number);
}

void isOddFoo(void) {
    for (int i = 0; i<20; i++) {
        if(i%2 ==0) {
            printf("%d is even \n", i);
        } else {
            printf("%d is odd \n", i);
        }
        if(i % 3 == 0) {
            printf("and %d  is a multiple of 3 \n", i);
        }
    }
}

void nextPrime(int startPoint) {
    bool isPrime = checkPrime(startPoint);
    
    while(!isPrime) {
        startPoint++;
        isPrime = checkPrime(startPoint);
    }
    printf("%d is next prime \n", startPoint);
    
}

bool checkPrime(int num) {
    
    for (int i = 2; i<num; i++) {
        if(num % i == 0){
            return false;
            break;
        }
    }
    return true;
}

void primeBwtween1And100(void) {
    printf("2 \n");
    printf("3 \n");
    for (int i = 5; i<100; i+=2) {
        if(checkPrime(i)){
            printf("%d \n", i);
        }
    }
}

void first100Prime(void) {
    printf("2 \n");
    printf("3 \n");
    int count = 2;
    int start = 5;
    while (count<100) {
        if(checkPrime(start)) {
            printf("%d \n", start);
            count++;
        }
        start +=2;
    }
}


/* ************* Chapter Seven **************** */
int gNumber = 2;
int gNumber2;
void chapterSeven(void) {
    int number = 5;
    for (int i = 0; i<20; i++) {
        addOne(&number);
    }
    printf("number is %d \n", number);
    
    for (int i = 1; i<=2; i++) {
        gNumber *= multipyIt(gNumber);
    }
    printf("gNumber is %d \n", gNumber);
    
    gNumber2 = 1;
    for (int i = 0; i<10; i++) {
        gNumber2 = doubleIt(gNumber2);
    }
    printf("gNumber2 is %d \n", gNumber2);
}

void addOne(int *number) {
    (*number)++;
}

int multipyIt(int myVar) {
    return myVar * gNumber;
}

int doubleIt(int myVar) {
    return 2*myVar;
}

/* ************* Chapter Eight **************** */
void rollDice(void);
#define kDiceNumbers 3
#define kDiceSize 6
#define kResultNum kDiceNumbers * kDiceSize
#define kResultArrLength kResultNum + 1
#define kRollTimes 1000

void chapterEight(void){
    rollDice();
    char firstName[] = "yoyoyoyo";
    char lastName[] = "yoyoyoyocindy";
    printFullName(firstName, lastName);
}

void rollDice(void) {
    int result[kResultArrLength];
    for (int i = 0; i<kResultArrLength; i++) {
        result[i] = 0;
    }
    for (int i  = 0; i<kRollTimes; i++) {
        int t = 0;
        for (int m = 0; m<kDiceNumbers; m++) {
            t += rollOnce();
        }
        result[t]++;
    }
    printfForDice(result);
}

int rollOnce(void) {
    srand((unsigned int)clock());
    int i = rand();
    return (i%kDiceSize)+1;
}

void printfForDice(int result[]) {
    for (int i=kDiceNumbers; i<kResultArrLength; i++) {
        printf("%d got %d times \n", i, result[i]);
    }
}

void printFullName(char *firstName, char *lastName) {
    char fullName[strlen(firstName) + strlen(lastName) + 2 + 1];
    strcpy(fullName, firstName);
    strcat(fullName, ", ");
    strcat(fullName, lastName);
    
    printf("%s \n", fullName);
}



