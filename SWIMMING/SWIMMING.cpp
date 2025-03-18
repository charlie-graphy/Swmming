//getchar(); system("cls");
#include<iostream>
#include<windows.h> 
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<cstring>
#include<fstream>
#include<thread>

using namespace std;

//left=224 75 right= 224 77 up= 224 72 down=244 80

void gotoxy(int x, int y)//x가로y세로
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void record();
void information();
void main_view();
void setting();
void how();
void play();
void character(int a, int left, int right, int rnd[], int score);
void clean(int left, int right);
void over(int score);



int main() {
	main_view();

}

void main_view() {
	system("mode con: cols=80 lines=26"); //화면창 크기설정
	int a, b = 1; // 키보드 기본값 미리 설정

	
	cout << endl << endl << endl << endl;
	cout << "   ,---.  ,--.   ,--. ,--. ,--.   ,--. ,--.   ,--. ,--. ,--.  ,--.  ,----." << endl;
	cout << "  '  .-'  |  |   |  | |  | |   `.'   | |   `.'   | |  | |   '.|  | '  .-./" << endl;
	cout << "  `. `-.  |  |.'.|  1 |  | |  | 2 |  | |  | 2 |  | |  | |   8 '  | |  | .---. " << endl;
	cout << " . -'   | |   ,'.   | |  | |  |   |  | |  |   |  | |  | |  | `   | '  '--'  |" << endl;
	cout << " `-----'  '--'   '--' `--' `--'   `--' `--'   `--' `--' `--'  `--'  `------' " << endl;

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	cout << setw(42) << " 시작하기" << endl;  //이때 setw(숫자)는 화면 폭 지정
	cout << setw(42) << " 게임방법" << endl;
	cout << setw(42) << " 기록보기" << endl;
	

	gotoxy(30, 18);
	cout << "▶" << endl;

	//메뉴 고르기	
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 80 && b == 2) { //아래로 누르면
				gotoxy(30, 18);
				cout << " " << endl;
				gotoxy(30, 19);
				cout << " " << endl;
				gotoxy(30, 20);
				cout << "▶" << endl;
				b = 3;
				Sleep(100);
			}
			else if (a == 72 && b == 3) {
				gotoxy(30, 18);
				cout << " " << endl;
				gotoxy(30, 19);
				cout << "▶" << endl;
				gotoxy(30, 20);
				cout << " " << endl;
				b = 2;
				Sleep(100);
			}
			else if (a == 72 && b == 2) { // 위로 누르면
				gotoxy(30, 18);
				cout << "▶" << endl;
				gotoxy(30, 19);
				cout << " " << endl;
				gotoxy(30, 20);
				cout << " " << endl;
				b = 1;
				Sleep(100);
			}
			else if (a == 80 && b != 3) { //아래로 누르면
				gotoxy(30, 18);
				cout << " " << endl;
				gotoxy(30, 19);
				cout << "▶" << endl;
				gotoxy(30, 20);
				cout << " " << endl;
				b = 2;
				Sleep(100);
			}
		}
	} while (a != 13);
	system("cls");
	if (b == 1) {
		information();
	}
	else if (b == 2) {
		how();
	}
	else if (b == 3) {
		record();
	}
	
}

void setting() {
	//게임틀 (배경)
	system("cls");
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "1 ●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○ 2                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 2 ● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○ 8 " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	cout << setw(62) << "○○                  □                 ○○ " << endl;
	cout << setw(62) << "●●                  □                 ●● " << endl;
	play();

}

void play() {

	srand((unsigned)time(0));
	int a, b = 72;
	int w1 = 2, w2 = 3;
	int s = 10, score = 0;
	int first = 1;
	int m = 0;
	int left = 22, right = 41;
	int rnd[6]; // 랜덤으로 양쪽 배열
	int wave[6] = { 1,5,9,13,17,22 }, wave2[6] = { 2,6,10,14,18,23 };

	for (int i = 0; i < 6; i++) {
		rnd[i] = rand() % 100;
	}

	int rnd2; //장애물추가생성

			  //캐릭터 기본 위치
	gotoxy(26, 24);
	cout << "˙♡˙";

	gotoxy(62, 2);
	cout << "시간 : ";
	gotoxy(62, 3);
	cout << "점수 : ";

	do {
		if (first == 1) { // 게임 첫 시작 기본으로 장애물 생성
			while (m < 6) {
				if (rnd[m] % 2 == 0) { //짝수면 왼쪽
					gotoxy(left, wave[m]);
					cout << "▼▽▽▽▽▽▼" << endl;
					gotoxy(left, wave2[m]);
					cout << " ▼▼▼▼▼▼";
				}
				else { //홀수면오른쪽
					gotoxy(right, wave[m]);
					cout << "▼▽▽▽▽▽▼" << endl;
					gotoxy(right, wave2[m]);
					cout << " ▼▼▼▼▼▼";
				}
				m++;
			}
			first++;
		}
		//게임시작
		a = _getch();
		
		if (a == 224) {
			character(a, left, right, rnd, score); //캐릭터 이동
			score++;
			//점수 값 보여줌
			gotoxy(69, 3);
			cout << score;
		}

		//캐릭터 이동하면서 장애물 내려가야 하므로 배열을 한칸씩 이동
		for (int i = 5; i >= 0; i--) {
			int ai = i - 1;
			rnd[i] = rnd[ai];
		}

		//장애물이동
		for (int i = 1, j = 1; j < 6; i++, j++) {
			if (rnd[i] % 2 == 0) { //짝수면 왼쪽
				gotoxy(left, wave[j]);
				cout << "▼▽▽▽▽▽▼" << endl;
				gotoxy(left, wave2[j]);
				cout << " ▼▼▼▼▼▼";
			}
			else { //홀수면오른쪽
				gotoxy(right, wave[j]);
				cout << "▼▽▽▽▽▽▼" << endl;
				gotoxy(right, wave2[j]);
				cout << " ▼▼▼▼▼▼";
			}
		}

		//장애물 생성
		rnd2 = rand() % 100;
		rnd[0] = rnd2;
		if (rnd[0] % 2 == 0) { //짝수면 왼쪽
			gotoxy(left, wave[0]);
			cout << "▼▽▽▽▽▽▼" << endl;
			gotoxy(left, wave2[0]);
			cout << " ▼▼▼▼▼▼";
		}
		else { //홀수면오른쪽
			gotoxy(right, wave[0]);
			cout << "▼▽▽▽▽▽▼" << endl;
			gotoxy(right, wave2[0]);
			cout << " ▼▼▼▼▼▼";
		}
	} while (a != 13);

}

void character(int a, int left, int right, int rnd[6], int score) {
	int b;
	int wave[6] = { 2,6,10,14,18,22 }, wave2[6] = { 3,7,11,15,19,23 };

	//캐릭터이동
	a = _getch();
	if (a == 75) { //왼쪽으로 이동
		b = 75;
		gotoxy(46, 24);
		cout << "     " << endl;
		gotoxy(26, 24);
		cout << "˙♡˙";
		Sleep(100);
		if (rnd[5] % 2 == 0) { //왼쪽으로 이동했는데 밑에 장애물이 왼쪽에 있으면
			
			over(score);
		}
		else {
			clean(left, right);
		}
	}

	else if (a == 77) { //오른쪽으로 이동
		b = 77;
		gotoxy(26, 24);
		cout << "     " << endl;
		gotoxy(46, 24);
		cout << "˙♡˙";
		Sleep(100);
		if (rnd[5] % 2 != 0) { //오른쪽으로 이동했는데 밑에 장애물이 오른쪽에 있으면
			over(score);
		}
		else {
			clean(left, right);
		}
	}
}

void clean(int left, int right) {
	int wave[6] = { 1,5,9,13,17,22 }, wave2[6] = { 2,6,10,14,18,23 };

	for (int i = 0; i < 6; i++) {
		gotoxy(right, wave[i]);
		cout << "              ";
		gotoxy(right, wave2[i]);
		cout << "             ";
		gotoxy(left, wave[i]);
		cout << "              ";
		gotoxy(left, wave2[i]);
		cout << "             ";
	}
}

void over(int score) {
	system("cls");
	int a, b = 1;
	cout << endl << endl << endl << endl << endl << endl;
	cout << setw(62) << "○●○1○●○●○2○●○2○●○●○8○●○● " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                GAME OVER!              ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                점수 :                  ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○          저장하기      메인으로        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○●○1○●○●○2○●○2○●○●○8○●○● " << endl;

	gotoxy(42, 13);
	cout << score;

	ofstream outFile("record.txt", ios::app);

	outFile << score << "\n"; //파일에 점수 넣기

	outFile.close();

	gotoxy(26, 16);
	cout << "▶" << endl;
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 75) {
				b = 1;
				gotoxy(41, 16);
				cout << " " << endl;
				gotoxy(26, 16);
				cout << "▶" << endl;
				Sleep(100);
			}
			else if (a == 77) {
				b = 2;
				gotoxy(26, 16);
				cout << " " << endl;
				gotoxy(41, 16);
				cout << "▶" << endl;
				Sleep(100);
			}
		}
	} while (a != 13);
	if (b == 1) {
		record();
	}
	else if (b == 2) {
		main_view();
	}
}

void how() {
	int a, b = 1;


	cout << endl << "게임방법\n\n\n\n\n";
	gotoxy(11, 10);
	cout << "○●○●○●○1○●○●○2○●○2○●○●○8○●○●○●○\n\n";
	cout << setw(62) << "오로지 ←, →을 이용해서 진행하는 게임 입니다." << endl;
	cout << setw(59) << "방향키를 누르면 파도가 점점 다가오게 됩니다." << endl << endl << endl;
	cout << setw(59) << "▼▽▽▽▽▽▼  이와 같은 파도가 나타나면" << endl;
	cout << setw(55) << " ▼▼▼▼▼▼   반드시 피해야 됩니다." << endl << endl << endl;
	cout << setw(53) << "시간 안에 가장 먼 거리를 가야하며" << endl;
	cout << setw(65) << "먼 거리를 간 사람이 이기는 기록형 게임입니다.\n\n" << endl;
	gotoxy(11, 23);
	cout << "○●○●○●○1○●○●○2○●○2○●○●○8○●○●○●○\n\n";
	cout << endl << endl << endl << endl << endl ;
	cout << setw(70) << "게임시작 \t메인으로" << endl;
	gotoxy(50, 24);
	cout << "▶" << endl;
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 75) {
				b = 1;
				gotoxy(62, 24);
				cout << " " << endl;
				gotoxy(50, 24);
				cout << "▶" << endl;
				Sleep(100);
			}
			else if (a == 77) {
				b = 2;
				gotoxy(50, 24);
				cout << " " << endl;
				gotoxy(62, 24);
				cout << "▶" << endl;
				Sleep(100);
			}
		}
	} while (a != 13);
	if (b == 2) {
		main_view();
	}
	else if (b == 1) {
		information();
	}
}

void information() {
	char name[20];
	system("cls");
	cout << endl << endl << endl << endl << endl << endl;
	cout << setw(62) << "○●○1○●○●○2○●○2○●○●○8○●○● " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○         사용자 이름을 입력하세요.      ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○             이름 :                     ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○                                        ○ " << endl;
	cout << setw(62) << "○●○1○●○●○2○●○2○●○●○8○●○● " << endl;

	ofstream outFile("record.txt",ios::app);

	gotoxy(39, 13);
	cin >> name;

	outFile << name << "\t\t\t "; //파일에 이름 넣기

	outFile.close();

	setting();
}

void record() {
	int a, b = 1, m = 7;
	system("cls");
	cout << "기록";
	char inputString[50];

	gotoxy(10, 3);
	cout << "○●○●○●○1○●○●○2○●○2○●○●○8○●○●○●○●○";
	gotoxy(24, 5);
	cout << " 이름\t\t\t점수" << endl; 

	ifstream inFile("record.txt");


	while (!inFile.eof()) { //eof() 함수는 파일의 끝을 만나면 true, 그렇지않다면 false
		gotoxy(24, m);

		inFile.getline(inputString, 100);
		cout << inputString << endl;
		m++;
	}
	inFile.close();

	gotoxy(51, 23);
	cout << "게임시작 \t메인으로" << endl;
	gotoxy(49, 23);
	cout << "▶" << endl;
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 75) {
				b = 1;
				gotoxy(62, 23);
				cout << " " << endl;
				gotoxy(49, 23);
				cout << "▶" << endl;
				Sleep(100);
			}
			else if (a == 77) {
				b = 2;
				gotoxy(49, 23);
				cout << " " << endl;
				gotoxy(62, 23);
				cout << "▶" << endl;
				Sleep(100);
			}
		}
	} while (a != 13);
	if (b == 2) {
		main_view();
	}
	else if (b == 1) {
		information();
	}
}