#include <iostream>
#include <ctime>
#include <cstdlib>
#include "janken.h"
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

void Janken()
{
	do {
		do {
			system("cls");
			cout << "1:�O�[�@2:�`���L�@3:�p�[\n\n�@���@" << flush;
			cin >> input;
		} while (input < 1 || 3 < input);

		srand((unsigned int)time(NULL));
		cpu = rand() % 3 + 1;

		switch (Judge(input, cpu)) {
		case win: cout << RESULT[0]; break;
		case lose: cout << RESULT[1]; break;
		case draw: cout << RESULT[2]; break;
		}

		do {
			cout << "1:�Q�[���𑱂���@2:�Q�[���I���֖߂�\n\n�@���@" << flush;
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