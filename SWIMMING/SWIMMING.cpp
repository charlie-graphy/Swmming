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

void gotoxy(int x, int y)//x����y����
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
	system("mode con: cols=80 lines=26"); //ȭ��â ũ�⼳��
	int a, b = 1; // Ű���� �⺻�� �̸� ����

	
	cout << endl << endl << endl << endl;
	cout << "   ,---.  ,--.   ,--. ,--. ,--.   ,--. ,--.   ,--. ,--. ,--.  ,--.  ,----." << endl;
	cout << "  '  .-'  |  |   |  | |  | |   `.'   | |   `.'   | |  | |   '.|  | '  .-./" << endl;
	cout << "  `. `-.  |  |.'.|  1 |  | |  | 2 |  | |  | 2 |  | |  | |   8 '  | |  | .---. " << endl;
	cout << " . -'   | |   ,'.   | |  | |  |   |  | |  |   |  | |  | |  | `   | '  '--'  |" << endl;
	cout << " `-----'  '--'   '--' `--' `--'   `--' `--'   `--' `--' `--'  `--'  `------' " << endl;

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	cout << setw(42) << " �����ϱ�" << endl;  //�̶� setw(����)�� ȭ�� �� ����
	cout << setw(42) << " ���ӹ��" << endl;
	cout << setw(42) << " ��Ϻ���" << endl;
	

	gotoxy(30, 18);
	cout << "��" << endl;

	//�޴� ����	
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 80 && b == 2) { //�Ʒ��� ������
				gotoxy(30, 18);
				cout << " " << endl;
				gotoxy(30, 19);
				cout << " " << endl;
				gotoxy(30, 20);
				cout << "��" << endl;
				b = 3;
				Sleep(100);
			}
			else if (a == 72 && b == 3) {
				gotoxy(30, 18);
				cout << " " << endl;
				gotoxy(30, 19);
				cout << "��" << endl;
				gotoxy(30, 20);
				cout << " " << endl;
				b = 2;
				Sleep(100);
			}
			else if (a == 72 && b == 2) { // ���� ������
				gotoxy(30, 18);
				cout << "��" << endl;
				gotoxy(30, 19);
				cout << " " << endl;
				gotoxy(30, 20);
				cout << " " << endl;
				b = 1;
				Sleep(100);
			}
			else if (a == 80 && b != 3) { //�Ʒ��� ������
				gotoxy(30, 18);
				cout << " " << endl;
				gotoxy(30, 19);
				cout << "��" << endl;
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
	//����Ʋ (���)
	system("cls");
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "1 ��                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�� 2                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 2 �� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �� 8 " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
	cout << setw(62) << "�ۡ�                  ��                 �ۡ� " << endl;
	cout << setw(62) << "�ܡ�                  ��                 �ܡ� " << endl;
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
	int rnd[6]; // �������� ���� �迭
	int wave[6] = { 1,5,9,13,17,22 }, wave2[6] = { 2,6,10,14,18,23 };

	for (int i = 0; i < 6; i++) {
		rnd[i] = rand() % 100;
	}

	int rnd2; //��ֹ��߰�����

			  //ĳ���� �⺻ ��ġ
	gotoxy(26, 24);
	cout << "������";

	gotoxy(62, 2);
	cout << "�ð� : ";
	gotoxy(62, 3);
	cout << "���� : ";

	do {
		if (first == 1) { // ���� ù ���� �⺻���� ��ֹ� ����
			while (m < 6) {
				if (rnd[m] % 2 == 0) { //¦���� ����
					gotoxy(left, wave[m]);
					cout << "��������" << endl;
					gotoxy(left, wave2[m]);
					cout << " �������";
				}
				else { //Ȧ���������
					gotoxy(right, wave[m]);
					cout << "��������" << endl;
					gotoxy(right, wave2[m]);
					cout << " �������";
				}
				m++;
			}
			first++;
		}
		//���ӽ���
		a = _getch();
		
		if (a == 224) {
			character(a, left, right, rnd, score); //ĳ���� �̵�
			score++;
			//���� �� ������
			gotoxy(69, 3);
			cout << score;
		}

		//ĳ���� �̵��ϸ鼭 ��ֹ� �������� �ϹǷ� �迭�� ��ĭ�� �̵�
		for (int i = 5; i >= 0; i--) {
			int ai = i - 1;
			rnd[i] = rnd[ai];
		}

		//��ֹ��̵�
		for (int i = 1, j = 1; j < 6; i++, j++) {
			if (rnd[i] % 2 == 0) { //¦���� ����
				gotoxy(left, wave[j]);
				cout << "��������" << endl;
				gotoxy(left, wave2[j]);
				cout << " �������";
			}
			else { //Ȧ���������
				gotoxy(right, wave[j]);
				cout << "��������" << endl;
				gotoxy(right, wave2[j]);
				cout << " �������";
			}
		}

		//��ֹ� ����
		rnd2 = rand() % 100;
		rnd[0] = rnd2;
		if (rnd[0] % 2 == 0) { //¦���� ����
			gotoxy(left, wave[0]);
			cout << "��������" << endl;
			gotoxy(left, wave2[0]);
			cout << " �������";
		}
		else { //Ȧ���������
			gotoxy(right, wave[0]);
			cout << "��������" << endl;
			gotoxy(right, wave2[0]);
			cout << " �������";
		}
	} while (a != 13);

}

void character(int a, int left, int right, int rnd[6], int score) {
	int b;
	int wave[6] = { 2,6,10,14,18,22 }, wave2[6] = { 3,7,11,15,19,23 };

	//ĳ�����̵�
	a = _getch();
	if (a == 75) { //�������� �̵�
		b = 75;
		gotoxy(46, 24);
		cout << "     " << endl;
		gotoxy(26, 24);
		cout << "������";
		Sleep(100);
		if (rnd[5] % 2 == 0) { //�������� �̵��ߴµ� �ؿ� ��ֹ��� ���ʿ� ������
			
			over(score);
		}
		else {
			clean(left, right);
		}
	}

	else if (a == 77) { //���������� �̵�
		b = 77;
		gotoxy(26, 24);
		cout << "     " << endl;
		gotoxy(46, 24);
		cout << "������";
		Sleep(100);
		if (rnd[5] % 2 != 0) { //���������� �̵��ߴµ� �ؿ� ��ֹ��� �����ʿ� ������
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
	cout << setw(62) << "�ۡܡ�1�ۡܡۡܡ�2�ۡܡ�2�ۡܡۡܡ�8�ۡܡۡ� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                GAME OVER!              �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                ���� :                  �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��          �����ϱ�      ��������        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "�ۡܡ�1�ۡܡۡܡ�2�ۡܡ�2�ۡܡۡܡ�8�ۡܡۡ� " << endl;

	gotoxy(42, 13);
	cout << score;

	ofstream outFile("record.txt", ios::app);

	outFile << score << "\n"; //���Ͽ� ���� �ֱ�

	outFile.close();

	gotoxy(26, 16);
	cout << "��" << endl;
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 75) {
				b = 1;
				gotoxy(41, 16);
				cout << " " << endl;
				gotoxy(26, 16);
				cout << "��" << endl;
				Sleep(100);
			}
			else if (a == 77) {
				b = 2;
				gotoxy(26, 16);
				cout << " " << endl;
				gotoxy(41, 16);
				cout << "��" << endl;
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


	cout << endl << "���ӹ��\n\n\n\n\n";
	gotoxy(11, 10);
	cout << "�ۡܡۡܡۡܡ�1�ۡܡۡܡ�2�ۡܡ�2�ۡܡۡܡ�8�ۡܡۡܡۡܡ�\n\n";
	cout << setw(62) << "������ ��, ���� �̿��ؼ� �����ϴ� ���� �Դϴ�." << endl;
	cout << setw(59) << "����Ű�� ������ �ĵ��� ���� �ٰ����� �˴ϴ�." << endl << endl << endl;
	cout << setw(59) << "��������  �̿� ���� �ĵ��� ��Ÿ����" << endl;
	cout << setw(55) << " �������   �ݵ�� ���ؾ� �˴ϴ�." << endl << endl << endl;
	cout << setw(53) << "�ð� �ȿ� ���� �� �Ÿ��� �����ϸ�" << endl;
	cout << setw(65) << "�� �Ÿ��� �� ����� �̱�� ����� �����Դϴ�.\n\n" << endl;
	gotoxy(11, 23);
	cout << "�ۡܡۡܡۡܡ�1�ۡܡۡܡ�2�ۡܡ�2�ۡܡۡܡ�8�ۡܡۡܡۡܡ�\n\n";
	cout << endl << endl << endl << endl << endl ;
	cout << setw(70) << "���ӽ��� \t��������" << endl;
	gotoxy(50, 24);
	cout << "��" << endl;
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 75) {
				b = 1;
				gotoxy(62, 24);
				cout << " " << endl;
				gotoxy(50, 24);
				cout << "��" << endl;
				Sleep(100);
			}
			else if (a == 77) {
				b = 2;
				gotoxy(50, 24);
				cout << " " << endl;
				gotoxy(62, 24);
				cout << "��" << endl;
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
	cout << setw(62) << "�ۡܡ�1�ۡܡۡܡ�2�ۡܡ�2�ۡܡۡܡ�8�ۡܡۡ� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��         ����� �̸��� �Է��ϼ���.      �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��             �̸� :                     �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "��                                        �� " << endl;
	cout << setw(62) << "�ۡܡ�1�ۡܡۡܡ�2�ۡܡ�2�ۡܡۡܡ�8�ۡܡۡ� " << endl;

	ofstream outFile("record.txt",ios::app);

	gotoxy(39, 13);
	cin >> name;

	outFile << name << "\t\t\t "; //���Ͽ� �̸� �ֱ�

	outFile.close();

	setting();
}

void record() {
	int a, b = 1, m = 7;
	system("cls");
	cout << "���";
	char inputString[50];

	gotoxy(10, 3);
	cout << "�ۡܡۡܡۡܡ�1�ۡܡۡܡ�2�ۡܡ�2�ۡܡۡܡ�8�ۡܡۡܡۡܡۡܡ�";
	gotoxy(24, 5);
	cout << " �̸�\t\t\t����" << endl; 

	ifstream inFile("record.txt");


	while (!inFile.eof()) { //eof() �Լ��� ������ ���� ������ true, �׷����ʴٸ� false
		gotoxy(24, m);

		inFile.getline(inputString, 100);
		cout << inputString << endl;
		m++;
	}
	inFile.close();

	gotoxy(51, 23);
	cout << "���ӽ��� \t��������" << endl;
	gotoxy(49, 23);
	cout << "��" << endl;
	do {
		a = _getch();
		if (a == 224) {
			a = _getch();
			if (a == 75) {
				b = 1;
				gotoxy(62, 23);
				cout << " " << endl;
				gotoxy(49, 23);
				cout << "��" << endl;
				Sleep(100);
			}
			else if (a == 77) {
				b = 2;
				gotoxy(49, 23);
				cout << " " << endl;
				gotoxy(62, 23);
				cout << "��" << endl;
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