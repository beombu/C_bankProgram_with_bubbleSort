#include "header.h"

int main()
{
	int input;
	FILE* fp;
	fp = fopen("data.txt", "r+");//읽고쓰기 가능
	InitAccount(fp);

	do {
		printf("\n\n안녕하세요! 범철은행입니다! 원하시는 번호를 입력하세요! \n\n\n");
		printf("○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○\n");
		printf("○                                                        ○\n");
		printf("○  1)계좌 생성   2)계좌 조회   3)입금   4)출금   5)종료  ○\n");
		printf("○                                                        ○\n");
		printf("○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○\n");
		printf("입력 : ");
		scanf("%d", &input);

		switch (input) {
		case 1:
			MakeAccount(fp);
			break;
		case 2:
			ReadAccount();
			break;
		case 3:
			Deposit(fp);
			break;
		case 4:
			WithDraw(fp);
			break;
		case 5:
			input = 0;
			free(head);//종료, 메모리 반환
			free(tail);//종료, 메모리 반환
			break;
		default:
			printf("잘못 입력하셨습니다. \n");
			return main();
		}
	} while (input != 0);
}



