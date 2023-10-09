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
static int input = 0;//答え入力用
static int cpu = 0;//CPUの手
static int continu = 0;//継続選択用

static const char* const RESULT[] = {
	"\n勝ち！！！\n\n",
	"\n負け(Ｔ-Ｔ)\n\n",
	"\n引き分け\n\n",
};

void Janken()
{
	do {
		do {
			system("cls");
			cout << "1:グー　2:チョキ　3:パー\n\n　＞　" << flush;
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
			cout << "1:ゲームを続ける　2:ゲーム選択へ戻る\n\n　＞　" << flush;
			cin >> continu;
			system("cls");
		} while (continu < 1 || 2 < continu);
	} while (continu == 1);
}

static judge Judge(int Player, int CPU) //1:グー　2:チョキ　3:パー
{
	if (Player == CPU) {
		return draw;
	}else if ((Player == 1 && CPU == 2) || (Player == 2 && CPU == 3) || (Player == 3 && CPU == 1)) {
		return win;
	}else if ((Player == 1 && CPU == 3) || (Player == 2 && CPU == 1) || (Player == 3 && CPU == 2)) {
		return lose;
	}
}