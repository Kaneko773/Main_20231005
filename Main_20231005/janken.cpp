#include <iostream>
#include <ctime>
#include <cstdlib>
#include "janken.h"
#define SEE_ANSWER_JANKEN   //相手の手を見れるようにするかどうか
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

#ifdef SEE_ANSWER_JANKEN   //相手の手を見れるようにするかどうか
static const char* const ANSWER[] = {
	"CPUの手はグーです\n",
	"CPUの手はチョキです\n",
	"CPUの手はパーです\n",
};
#endif

void Janken()
{
	do {
		srand((unsigned int)time(NULL));
		cpu = rand() % 3 + 1;

		do {
			system("cls");
			#ifdef SEE_ANSWER_JANKEN   //CPUの手を見れるようにするかどうか
			printf("%s\n", ANSWER[cpu - 1]);
			#endif
			printf("1:グー　2:チョキ　3:パー\n\n　＞　");
			cin >> input;
		} while (input < 1 || 3 < input);

		switch (Judge(input, cpu)) {
		case win: printf("%s", RESULT[0]); break;
		case lose: printf("%s", RESULT[1]); break;
		case draw: printf("%s", RESULT[2]); break;
		}

		do {
			printf("1:ゲームを続ける　2:ゲーム選択へ戻る\n\n　＞　");
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