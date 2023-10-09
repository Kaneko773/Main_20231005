#include <iostream>
#include <ctime>
#include <cstdlib>
#include "kazuate.h"
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
	srand((unsigned int)time(NULL));
	cpu = rand() % 10 + 1;

	do {
		system("cls");
		printf("CPUが選んだ１～１０までの数字を３回以内に当てるゲームです\n\n");

		for(int i = 1; i < 4; ++i){
			do {
				cout << i << "回目" << "　＞　" << flush;
				cin >> answer;
			}while(answer < 1 || 10 < answer);
			if (Judge(answer, cpu, i) == correctAnswer) {
				cout << endl << i << RESULT[0] << endl;
				break; 
			}else if(i >= 3){
				cout << RESULT[1] << cpu << endl << endl;
			}
		}

		do {
			cout << "1:ゲームを続ける　2:ゲーム選択へ戻る\n\n　＞　" << flush;
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
		if(turn < 3) cout << HINT[0] << endl;
		return incorrectAnswer;
	}
	else if (Answer < CPU) {
		if (turn < 3) cout << HINT[1] << endl;
		return incorrectAnswer;
	}
}