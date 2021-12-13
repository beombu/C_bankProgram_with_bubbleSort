#include "header.h"

void InitAccount(FILE* fp)
{
	int id;
	char name[NAME_LEN];
	int money;
	head = (bank*)malloc(sizeof(bank));
	tail = (bank*)malloc(sizeof(bank));
	head->next = tail;
	tail->next = tail;

	while (fscanf(fp, "%d %s %d", &id, name, &money) == 3) {
		WriteAccount(id, name, money);
	}
}


void WriteAccount(int id, char* name, int money)
{
	bank* t;
	t = (bank*)malloc(sizeof(bank));
	t->id = id;
	strcpy(t->name, name);
	t->money = money;

	t->next = head->next;
	head->next = t;
}


void MakeAccount(FILE* fp)
{
	int id;
	char name[NAME_LEN];
	int money;
	bank* t;
	t = (bank*)malloc(sizeof(bank));

	printf("\n*********계좌 생성*********\n");
	printf("계좌번호 : ");
	scanf("%d", &id);
	printf("예 금 주 : ");
	scanf("%s", name);
	printf("입 금 액 : ");
	scanf("%d", &money);

	t->id = id;
	strcpy(t->name, name);
	t->money = money;

	t->next = head->next;
	head->next = t;

	BubbleSort(t);
	SaveAccount(fp);
}


void Deposit(FILE* fp)
{
	int id;
	int money;
	bank* t;
	printf("계좌번호 : ");
	scanf("%d", &id);
	printf("입 금 액 : ");
	scanf("%d", &money);

	for (t = head->next; t != tail; t = t->next)
	{
		if (t->id == id)
		{
			t->money += money;
			SaveAccount(fp);
			return;
		}
	}
	printf("없는 계좌번호입니다.\n");

}

void WithDraw(FILE* fp)
{
	int id;
	int money;
	bank* t;
	printf("계좌번호 : ");
	scanf("%d", &id);
	printf("출 금 액 : ");
	scanf("%d", &money);

	for (t = head->next; t != tail; t = t->next)
	{
		if (t->id == id)
		{
			if (t->money < money)
			{
				printf("출금액이 잔액을 초과할 수 없습니다.\n");
				return;
			}
			else {
				t->money -= money;
			}
			SaveAccount(fp);
			return;
		}
	}
	printf("없는 계좌번호입니다.\n");
}

void ReadAccount(void)
{
	int id;
	bank* t;

	printf("계좌번호 : ");
	scanf("%d", &id);

	for (t = head->next; t != tail; t = t->next)
	{
		if (t->id == id) {
			printf("\n*********잔액 조회*********\n");
			printf("계좌번호 : %d\n", t->id);
			printf("예 금 주 : %s님\n", t->name);
			printf("잔    액 : %d원\n\n", t->money);
			return;
		}
	}
	printf("없는 계좌번호입니다.\n");
}

int GetBankLength(bank* t) {
	int count = 0;
	bank* cur = t;

	while (cur != tail->next)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void SwapBankData(bank* node1, bank* node2)
{
	int temp;
	temp = node1->id;
	node1->id = node2->id;
	node2->id = temp;
}

void BubbleSort(bank* t) {
	 bank* cur = t;

	int size = GetBankLength(t);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (cur->id < cur->next->id) {
				SwapBankData(cur, cur->next);
			}
			cur = cur->next;
		}
		cur = t->next;
	}
}

void SaveAccount(FILE* fp)

{
	bank* t;
	rewind(fp);//포인터를 처음으로 보내줌

	for (t = head->next; t != tail; t = t->next)
	{
		fprintf(fp, "%d %s %d\n", t->id, t->name, t->money);
	}
}

