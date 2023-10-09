#include <iostream>
#include <ctime>
#include <cstdlib>
#include "kazuate.h"
using namespace std;

static enum judge {
	correctAnswer,//����
	incorrectAnswer,//�s����
};

static judge Judge(int Player, int CPU, int turn);
static int answer = 0;//�������͗p
static int cpu = 0;//CPU�I�񂾐���
static int continu = 0;//�p���I��p

static const char* const RESULT[] = {
	"��ڂŐ������܂����I�I�I\n",
	"\n���Ȃ��̕����ł��@�����F",
};

static const char* const HINT[] = {
	"\n�����͂��̐���菬�����ł�\n",
	"\n�����͂��̐����傫���ł�\n",
};

void Kazuate()
{
	srand((unsigned int)time(NULL));
	cpu = rand() % 10 + 1;

	do {
		system("cls");
		printf("CPU���I�񂾂P�`�P�O�܂ł̐������R��ȓ��ɓ��Ă�Q�[���ł�\n\n");

		for(int i = 1; i < 4; ++i){
			do {
				cout << i << "���" << "�@���@" << flush;
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
			cout << "1:�Q�[���𑱂���@2:�Q�[���I���֖߂�\n\n�@���@" << flush;
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