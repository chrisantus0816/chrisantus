//
//  ArrayList.c
//  Algorithm
//
//  Created by 이원준 on 2017. 12. 30..
//  Copyright © 2017년 LEEWONJUN. All rights reserved.
//
#include <stdio.h>
#include "ArrayList.h"


void ListInit(List* plist) //초기화
{
    (plist->numOfData)=0; //리스트에 저장된 데이터의 수는 0 개 !
    (plist->curPosition)=-1; //현재 아무것도 안가리키고 있다는 의미 (초기화시)
}

void LInsert(List* plist,LData data) //데이터 저장
{
    if(plist->numOfData >= LIST_LEN) //더이상 저장할 공간이없다면
    {
        puts("저장이 불가능합니다.");
        return;
    }
    
    plist->arr[plist->numOfData]=data;//데이터 저장 아무것도 저장이안되있으면 arr[0=초기값] 부터 저장되기 시작한다.
    (plist->numOfData)++;//저장된 데이터의 개수 증가
}

/* LFirst함수는 curPosition에 저장된 값을 0으로 재설정 함으로써 데이터의 참조가 앞에서부터 다시 진행되도록 하는 역할을 한다. */
int LFirst(List *plist,LData *pdata) //첫번째를 조회하기위한 함수
{
    if(plist->numOfData==0) //저장된 데이터가 하나도 없다면
        return FALSE;
    
    (plist->curPosition)=0; //저장된 데이터가 있다면, 참조위치 초기화 , 첫번째 데이터의 참조를 의미
    *pdata=plist->arr[0]; // pdata 가 가리키는 공간에 데이터 저장
    return TRUE;
}

/* LNext함수는 이값을 증가시켜서 순서대로 데이터를 참조할수 있도록 한다. */
int LNext(List* plist, LData *pdata)
{
    if(plist->curPosition >= (plist->numOfData)-1)//더이상 참조할 데이터가 없다면 인덱스 나타냄으로 데이터의개수-1 을 해줌
        return FALSE;
    
    (plist->curPosition)++; //순차적으로 데이터 참조를하기위해 curPosition 값 증가
    *pdata=plist->arr[plist->curPosition]; //0이 저장된 이후부터 1~numOfData-1 까지 pdata가 가리키는 공간에 데이터 저장
    return TRUE;
}

/* curPosition은 최근에 참조가 이루어진 데이터의 인덱스 정보를 담고 있어야한다. 그런데 삭제로 인해 비는공간을 메우려 데이터를 한칸씩 앞으로 이동시키면
 다음 그림에서 보듯이 curPosition은 아직 참조가 이뤄지지않은, 뒤에서 한칸 앞으로 이동한 데이터 D 를 가리키게된다.
 따라서 curPosition을 앞으로 한칸 왼쪽으로 이동시켜야한다. curPosition이 B를 가리키도록 한다. 이후 LNext함수를 호출하게되면 아직 참조가 이루어지지 않은
 데이터값 D를 참조할수 있게된다. */

LData LRemove(List *plist) //최근 조회가 이루어진 데이터를 삭제한다.
{
    int rpos=plist->curPosition; //삭제할 데이터의 인덱스 값 참조
    int num=plist->numOfData;
    int i;
    LData rdata=plist->arr[rpos]; //삭제할 데이터를 임시로 저장 rdata=tmp역할을함
    
    for(i=rpos;i<num-1;i++) //삭제를 위한 데이터의 이동을 진행하는 반복문
        plist->arr[i]=plist->arr[i+1]; //그림 03-1과 같이 삭제할 데이터의 인덱스로 한칸씩 앞으로 이동시킴
    
    (plist->numOfData)--; //데이터의 수 감소
    (plist->curPosition)--; //참조 위치를 하나 되돌린다. 참조위치를 하나 앞으로(배열기준 왼쪽으로 ) 옮긴다.
    return rdata; //삭제된 데이터의 반환
}

int LCount(List *plist)
{
    return plist->numOfData;
}
