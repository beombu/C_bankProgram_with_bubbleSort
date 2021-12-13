#define NAME_LEN 20

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


typedef struct bank {//계좌정보 구조체
	char* name[NAME_LEN]; //예금주
	int id;//계좌번호
	int money;//잔액
	struct bank* next;//자기 참조 구조체 포인터
}bank;


bank* head, * tail;//노드의 처음과 끝

void InitAccount(FILE* fp);//노드의 처음과 끝에 메모리 할당하고, 파일에서 입력을 받도록 하는 함수
void MakeAccount(FILE* fp);//계좌를 생성하는 함수
int GetBankLength(bank* t);//구조체의 길이를 구해주는 함수
void BubbleSort(bank* t);//버블정렬 함수
void Deposit(FILE* fp);//입금 함수
void WithDraw(FILE* fp);//출금 함수
void SaveAccount(FILE* fp);//계좌의 정보를 저장하는 함수
void SwapBankData(bank* node1, bank* node2);//구조체의 값을 바꿔주는 함수
void ReadAccount(void);//계좌를 조회하는 함수
void WriteAccount(int id, char* name, int money);//텍스트 파일에서 입력을 받는 함수