//
//  ArrayList.h
//  Algorithm
//
//  Created by 이원준 on 2017. 12. 30..
//  Copyright © 2017년 LEEWONJUN. All rights reserved.
//

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__ //헤더파일의 중복선언을 막기위한 매크로 선언

#define TRUE 1 //참
#define FALSE 0 //거짓

#define LIST_LEN 100
typedef int LData; //LData에 대한 typedef 선언

typedef struct __ArrayList //배열기반 리스트를 정의한 구조체
{
    LData arr[LIST_LEN]; //리스트의 저장소인 배열
    int numOfData; //저장된 데이터의 수
    int curPosition; //데이터 참조위치를 기록
    
}ArrayList;

typedef ArrayList List;

void ListInit(List* plist); //초기화
void LInsert(List* plist, LData data); //데이터 저장

int LFrist(List *plist, LData* pdata); //첫번째 데이터 참조
int LNext(List *plist,LData* pdata); //두번째 이후 데이터 참조

LData LRemove(List* plist); //참조한 데이터 삭제
int LCount(List* plist); //저장된 데이터의 수 반환

#endif /* ArrayList_h */
