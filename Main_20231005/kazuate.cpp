#include <iostream>
#include <ctime>
#include <cstdlib>
#include "kazuate.h"
#define SEE_ANSWER_KAZUATE   //答えを見れるようにするかどうか
using namespace std;

static enum judge {
	correctAnswer,//正解
	incorrectAnswer,//不正解
};

static judge Judge(int Player, int CPU, int turn);
static int answer = 0;//答え入力用
static int cpu = 0;//CPU選んだ数字
static int continu = 0;//継続選択用

static const char* const RESULT[] = {
	"回目で正解しました！！！\n",
	"\nあなたの負けです　正解：",
};

static const char* const HINT[] = {
	"\n正解はその数より小さいです\n",
	"\n正解はその数より大きいです\n",
};

void Kazuate()
{
	do {
		srand((unsigned int)time(NULL));
		cpu = rand() % 10 + 1;

		system("cls");
		printf("CPUが選んだ１～１０までの数字を３回以内に当てるゲームです\n\n");

		for(int i = 1; i < 4; ++i){
			do {
			#ifdef SEE_ANSWER_KAZUATE   //答えを見れるようにするかどうか
				printf("答えは%dです\n\n", cpu);
			#endif
				printf("%d回目　＞　", i);
				cin >> answer;
			}while(answer < 1 || 10 < answer);
			if (Judge(answer, cpu, i) == correctAnswer) {
				printf("\n%d%s\n", i, RESULT[0]);
				break; 
			}else if(i >= 3){
				printf("%s%d\n\n", RESULT[1], cpu);
			}
		}

		do {
			printf("1:ゲームを続ける　2:ゲーム選択へ戻る\n\n　＞　");
			cin >> continu;
			system("cls");
		} while (continu < 1 || 2 < continu);
	} while (continu == 1);
}

static judge Judge(int Answer, int CPU, int turn)
{
	if (Answer == CPU) {
		return correctAnswer;
	}
	else if (Answer > CPU) {
		if (turn < 3) printf("%s\n", HINT[0]);
		return incorrectAnswer;
	}
	else if (Answer < CPU) {
		if (turn < 3) printf("%s\n", HINT[1]);
		return incorrectAnswer;
	}
}