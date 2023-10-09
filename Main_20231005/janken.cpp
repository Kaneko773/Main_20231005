#include <iostream>
#include <ctime>
#include <cstdlib>
#include "janken.h"
#define SEE_ANSWER_JANKEN   //����̎�������悤�ɂ��邩�ǂ���
using namespace std;

static enum judge {
	win,
	lose,
	draw,
};

static judge Judge(int Player, int CPU);
static int input = 0;//�������͗p
static int cpu = 0;//CPU�̎�
static int continu = 0;//�p���I��p

static const char* const RESULT[] = {
	"\n�����I�I�I\n\n",
	"\n����(�s-�s)\n\n",
	"\n��������\n\n",
};

#ifdef SEE_ANSWER_JANKEN   //����̎�������悤�ɂ��邩�ǂ���
static const char* const ANSWER[] = {
	"CPU�̎�̓O�[�ł�\n",
	"CPU�̎�̓`���L�ł�\n",
	"CPU�̎�̓p�[�ł�\n",
};
#endif

void Janken()
{
	do {
		srand((unsigned int)time(NULL));
		cpu = rand() % 3 + 1;

		do {
			system("cls");
			#ifdef SEE_ANSWER_JANKEN   //CPU�̎�������悤�ɂ��邩�ǂ���
			printf("%s\n", ANSWER[cpu - 1]);
			#endif
			printf("1:�O�[�@2:�`���L�@3:�p�[\n\n�@���@");
			cin >> input;
		} while (input < 1 || 3 < input);

		switch (Judge(input, cpu)) {
		case win: printf("%s", RESULT[0]); break;
		case lose: printf("%s", RESULT[1]); break;
		case draw: printf("%s", RESULT[2]); break;
		}

		do {
			printf("1:�Q�[���𑱂���@2:�Q�[���I���֖߂�\n\n�@���@");
			cin >> continu;
			system("cls");
		} while (continu < 1 || 2 < continu);
	} while (continu == 1);
}

static judge Judge(int Player, int CPU) //1:�O�[�@2:�`���L�@3:�p�[
{
	if (Player == CPU) {
		return draw;
	}else if ((Player == 1 && CPU == 2) || (Player == 2 && CPU == 3) || (Player == 3 && CPU == 1)) {
		return win;
	}else if ((Player == 1 && CPU == 3) || (Player == 2 && CPU == 1) || (Player == 3 && CPU == 2)) {
		return lose;
	}
}