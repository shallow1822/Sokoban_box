#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
#define Width 15
#define Hight 10
#define Blank 0
#define Wall 1
#define Target 2
#define Box 3
#define LuckyDog 4
#define StarX 6
#define StarY 5
#define B_SIZE 60
void InitMap();
void DrawMap();
void Move(int xMove, int yMove);
int judge();
void gotoxy(int x, int y);
void begin();
void music_move();
void music_win();
void music_main1();
void music_main1close();
void music_main1stop();
void music_main1continue();
void music_main2();
void music_main2close();
void music_main2stop();
void music_main2continue();
void music_get();
void music_lose();
void music_loseclose();
void music_fail();
int esc; 
int score=0;
int a, b;
int x, y;
char input;
int get=0;
int map[Hight][Width];
int boxmap[Hight][Width];
int totalmap[][Hight][Width] = { 
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,3,0,2,0,0,3,1,1,0,0,1},
	{1,0,0,0,0,3,2,1,0,0,0,0,0,0,1},
	{1,3,1,0,0,0,2,0,0,0,1,1,2,0,1},
	{1,0,0,0,1,0,3,0,0,1,1,2,1,0,1},
	{1,2,0,0,0,0,0,1,0,0,0,0,3,0,1},
	{1,1,1,1,1,1,3,0,0,1,1,3,0,0,1},
	{1,0,0,2,0,0,0,0,0,2,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	},
	{ 
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,3,1,0,2,0,0,3,0,0,0,0,1},
	{1,0,0,0,0,3,2,1,0,0,1,1,0,1,1},
	{1,3,1,1,0,0,2,0,0,0,1,0,0,2,1},
	{1,0,0,0,1,0,3,0,0,1,1,2,1,0,1},
	{1,2,0,0,1,0,0,1,0,0,0,0,3,0,1},
	{1,1,1,0,1,1,3,0,0,1,1,3,0,0,1},
	{1,0,0,2,0,0,0,0,0,2,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	},
	{ 
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{4,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,3,0,0,0,0,3,1,1,0,0,1},
	{1,0,0,3,0,1,2,1,0,0,0,0,0,0,1},
	{1,3,1,1,1,1,2,0,0,0,1,1,2,0,1},
	{1,0,0,0,1,0,3,0,0,1,1,2,1,0,1},
	{1,2,0,0,0,0,0,1,0,0,0,0,3,0,1},
	{1,1,1,1,1,1,3,0,0,1,1,3,0,0,1},
	{1,0,0,2,0,0,0,0,0,2,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	}
};

int main()
{
	input1:
	music_main1();
//return_:
	clock_t star, end;
	star = clock();
	system("color fc");
	InitMap();
	//PlaySound(TEXT("Spark.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//msuic_lose();
	while (1)
	{
		judge();
		gotoxy(0,0);
		DrawMap();
		FlushBatchDraw();
		input = _getch();
		if (input == 'w') {
			Move(-1, 0);
			
		}
		if (input == 's') {
			Move(1, 0);
		
		}
		if (input == 'a') {
			Move(0, -1);
			
		}
		if (input == 'd') {
			Move(0, 1);
			
		}
		if (input == 27) {
			esc = 1;
		}
		if (input == 'r') {
			system("cls");
			printf("\n");
			system("cls");
			printf("\t\t\t\t\t还想玩嘛??\n");
			printf("\t\t\t\t\tㄟ(▔▽▔ㄟ) (╯▔▽▔)╯\n");
			printf("\t\t\t\t\t继续按：C\n\n\n");
			printf("\t\t\t\t\t退出按：Esc");
			int input1 = _getch();
			if (input1 == 'c') {
				goto input1;
			}
			//goto return_;
		}
		if (input == '1') {
			music_main1();
		}
		if (input == '4') {
			music_main2();
		}
		if (input == '2') {
			
			music_main1close();
		}
		if (input == '3') {
			if (a % 2 != 0) {
				music_main1stop();
				++a;
			}
			else if (a % 2 == 0) {
				music_main1continue();
				++a;
			}
		}
		if (input == '5') {
			music_main2close();
		}
		if (input == '6') {
			if (b % 2 != 0) {
				music_main2stop();
				++b;
			}
			else if (b % 2 == 0) {
				music_main2continue();
				++b;
			}
		}
		if (input == '0') {
			music_loseclose();
		}
		Sleep(75);
		if (judge()) {
			DrawMap();
			break;
		}
	}
	EndBatchDraw();
	end = clock();
	float time = (double)(end - star) / CLOCKS_PER_SEC;
	int time1 = (int)time;
	if (score == 16||score==9) {
		music_loseclose();
		music_main1close();
		music_main2close();
		music_win();
		settextcolor(YELLOW);
		settextstyle(180, 0, _T("宋体"));
		outtextxy(50, 400, _T("YOU WIN!!"));
		settextcolor(YELLOW);
		settextstyle(120, 0, _T("宋体"));
		TCHAR s[5];
		_stprintf(s, _T("%d"), time1);
		outtextxy(10, 60, s);
		printf("太厉害了吧 time=%f\n", time);
		printf("\n----YOU WIN-----\n");
		//printf("%d", score);
		printf("\n");
		//system("cls");
		printf("\t\t\t\t\t还想玩嘛??\n");
		printf("\t\t\t\t\tㄟ(▔▽▔ㄟ) (╯▔▽▔)╯\n");
		printf("\t\t\t\t\t继续按：C\n\n\n");
		printf("\t\t\t\t\t退出按：回车");
		int input1 = _getch();
		system("cls");
		if (input1 == 'c') {
			goto input1;
		}
	}
	else {
		music_loseclose();
		music_main1close();
		music_main2close();
		//music_lose();
		music_fail();
		settextcolor(YELLOW);
		settextstyle(180, 0, _T("微软黑体"));
		outtextxy(50, 400, _T("YOU FAIL!!"));
		settextcolor(YELLOW);
		settextstyle(120, 0, _T("微软黑体"));
		TCHAR s[5];
		_stprintf(s, _T("%d"), time1);	
		outtextxy(10, 60, s);
		printf("\n----YOU FAIL!!-----\n");
		printf("time=%f\n",time);
		//printf("%d", score);

	}

	getchar();//begin函数里接收回车
	getchar();
	return 0;
}
void InitMap() {
	int i, j;
	begin();
	initgraph(1000, 1000);
	setorigin(50, 150);
	//setaspectratio(1, 1);
	setbkcolor(RGB(255, 225, 255));
	BeginBatchDraw();
	cleardevice();
	x = StarX;
	y = StarY;
	for (i = 0; i < Hight; i++) {
		for (j = 0; j < Width; j++) {
			boxmap[i][j] = Blank;
		}
	}
	for (i = 0; i < Hight; i++) {
		for (j = 0; j < Width; j++) {
			if (map[i][j] == Box) {
				boxmap[i][j] = Box;
				map[i][j] = Blank;
			}
			if (map[i][j] == Target) {
				boxmap[i][j] = Target;
			}
			if (map[i][j] == LuckyDog) {
				boxmap[i][j] = LuckyDog;
			}
		}
	}
}

void DrawMap()
{
	int i, j;
	cleardevice();
	for (i = 0; i < Hight; i++) 
	{
		for (j = 0; j < Width; j++)
		{
			if (i == x && j == y)
			{
				if(i % 2 == 0) {
					if (j % 2 == 0) {
						setfillcolor(RGB(105, 224, 69));
						setlinecolor(RGB(150, 150, 150));
						fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
					
					}
					else {
						setfillcolor(RGB(117, 249, 77));
						setlinecolor(RGB(150, 150, 150));
						fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
						
					}
				}
			else {
				if ((j + 1) % 2 == 0) {
					setfillcolor(RGB(105, 224, 69));
					setlinecolor(RGB(150, 150, 150));
					fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
					
				}
				else {
					setfillcolor(RGB(117, 249, 77));
					setlinecolor(RGB(150, 150, 150));
					fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
				}
			}
				//脸
				//setlinestyle(PS_ENDCAP_ROUND, 1);
				//setlinecolor(BLACK);
				setfillcolor(RGB(240,134,80));
				fillcircle((j + 0.5) * B_SIZE, (i + 0.5) * B_SIZE, 0.4 * B_SIZE);
				//右眼
				setlinecolor(RGB(240, 135, 132));
				setfillcolor(BLACK);
				fillcircle((j + 0.7) * B_SIZE, (i + 0.55) * B_SIZE, 0.09 * B_SIZE);

				//左眼
				setlinecolor(RGB(240, 135, 132));
				setfillcolor(BLACK);
				fillcircle((j + 0.3) * B_SIZE, (i + 0.55) * B_SIZE, 0.09 * B_SIZE);
				//嘴巴
				setlinestyle(PS_ENDCAP_ROUND, 5);
				setlinecolor(RED);
				line((j +0.3) * B_SIZE, (i + 0.7) * B_SIZE, (j + 0.7) * B_SIZE, (i + 0.7) * B_SIZE);
				//鼻子
				/*setlinestyle(PS_ENDCAP_ROUND, 5);
				setlinecolor(BLACK);
				line((j + 0.53) * B_SIZE, (i + 0.5) * B_SIZE, (j + 0.53) * B_SIZE, (i + 0.6) * B_SIZE);*/
				//眉毛
				setlinestyle(PS_ENDCAP_ROUND, 4);
				setlinecolor(BLACK);
				line((j + 0.2) * B_SIZE, (i + 0.45) * B_SIZE, (j + 0.4) * B_SIZE, (i + 0.45) * B_SIZE);
				setlinestyle(PS_ENDCAP_ROUND, 4);
				setlinecolor(BLACK);
				line((j + 0.6) * B_SIZE, (i + 0.45) * B_SIZE, (j + 0.8) * B_SIZE, (i + 0.45) * B_SIZE);
				//底层帽
				setlinestyle(PS_ENDCAP_ROUND, 1);
				setlinecolor(BLACK);
				setfillcolor(RGB(120, 67, 21));
				fillroundrect((j+0.1)*B_SIZE, (i + 0.2) * B_SIZE, (j+0.9)*B_SIZE, (i + 0.4) * B_SIZE,B_SIZE*0.3,B_SIZE*0.1);
				//上层帽
				setlinestyle(PS_DASH, 2);
				setlinecolor(BLACK);
				setfillcolor(RGB(120,63,12));
				fillrectangle((j + 0.15) * B_SIZE, (i) * B_SIZE, (j + 0.85) * B_SIZE, (i + 0.2) * B_SIZE);
				setlinestyle(PS_SOLID, 1);
				printf("m");
			}
			else
			{
				if (boxmap[i][j] == Box) 
				{
					if (map[i][j] == Target|| map[i][j] == LuckyDog)
					{
						setlinecolor(BLACK);
						setfillcolor(YELLOW);
						fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
						setfillcolor(WHITE);
						fillrectangle((j + 0.3) * B_SIZE, (i + 0.3) * B_SIZE,(j + 0.7) * B_SIZE, (i + 0.7) * B_SIZE);
						printf("@");
						//music_get();
						score++;

					}
					else
					{
						setfillcolor(RGB(240, 134, 80));
						setlinecolor(BLACK);
						fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
						setfillcolor(RGB(240, 134, 80));
						setlinecolor(BLACK);
						fillrectangle((j+0.1) * B_SIZE, (i+0.1) * B_SIZE, (j + 0.9) * B_SIZE, (i + 0.9) * B_SIZE);
						setfillcolor(RGB(240,134,80));
						setlinecolor(BLACK);
						fillrectangle((j+0.2) * B_SIZE, (i+0.2) * B_SIZE, (j + 0.8) * B_SIZE, (i + 0.8) * B_SIZE);
						setfillcolor(RGB(240, 134, 80));
						setlinecolor(BLACK);
						fillrectangle((j+0.3) * B_SIZE, (i+0.3) * B_SIZE, (j+0.7)  * B_SIZE, (i+0.7) * B_SIZE);
						printf("o");
						}
				}
				else
				{
					switch (map[i][j])
					{
					case Blank:
						if (i % 2 == 0) {
							if (j % 2 == 0) {
								setfillcolor(RGB(105, 224, 69));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
								printf(" ");
								break;
							}
							else {
								setfillcolor(RGB(117, 249, 77));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
								printf(" ");
								break;
							}
						}
						else {
							if ((j + 1) % 2 == 0) {
								setfillcolor(RGB(105, 224, 69));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j* B_SIZE, i* B_SIZE, (j + 1)* B_SIZE, (i + 1)* B_SIZE);
								printf(" ");
								break;
							}
							else {
								setfillcolor(RGB(117, 249, 77));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j* B_SIZE, i* B_SIZE, (j + 1)* B_SIZE, (i + 1)* B_SIZE);
								printf(" ");
								break;
							}
						}
					case Wall:
						setfillcolor(BLACK);
						setlinecolor(RGB(150, 150, 150));
						fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
						printf("#");
						break;
					case Target:
						if (i % 2 == 0) {
							if (j % 2 == 0) {
								setfillcolor(RGB(105, 224, 69));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
							
							}
							else {
								setfillcolor(RGB(117, 249, 77));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
							
							}
						}
						else {
							if ((j + 1) % 2 == 0) {
								setfillcolor(RGB(105, 224, 69));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
						
							}
							else {
								setfillcolor(RGB(117, 249, 77));
								setlinecolor(RGB(150, 150, 150));
								fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
								
							}
						}
						setfillcolor(WHITE); 
						setlinecolor(BLACK);
						fillrectangle((j + 0.3) * B_SIZE, (i + 0.3) * B_SIZE,(j + 0.7) * B_SIZE, (i + 0.7) * B_SIZE);
						printf("T");
						break;
					case LuckyDog:
						setfillcolor(BLACK);
						setlinecolor(RGB(150, 150, 150));
						fillrectangle(j * B_SIZE, i * B_SIZE, (j + 1) * B_SIZE, (i + 1) * B_SIZE);
						printf("#");
						break;
					}
				}
			}
		}
		putchar('\n');
	}
}

void Move(int xMove, int yMove) 
{
	music_move();
	if (boxmap[x + xMove][y + yMove] == Box) {
		if (boxmap[x + 2 * xMove][y + 2 * yMove] != Box && map[x + 2 * xMove][y + 2 * yMove] != Wall)
		{
			boxmap[x + xMove][y + yMove] = Blank;
			boxmap[x + 2 * xMove][y + 2*yMove] = Box;
			x += xMove;
			y += yMove;
		}
	}
	else
	{
		if (map[x + xMove][y + yMove] != Wall)
		{
			x += xMove;
			y += yMove;
		}
	}
}

int judge() 
{
	int win = 1;
	int i, j;
	for (i = 0; i < Hight; i++) {
		for (j = 0; j < Width; j++) {
			if (boxmap[i][j] == Box && map[i][j] != Target) {
				win = 0;
				score = 1;
			}
		}
	}
	if (esc == 1) {
		win = 1;
	}
	return win;
}

void gotoxy(int x, int y)
{
	COORD point = { x,y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, point);
}

void music_move() {
	mciSendString("play 走.wav ", 0, 0, 0);
}

void music_win() {
	mciSendString("play 胜利欢呼声.mp3 ", 0, 0, 0);
}

void music_fail() {
	mciSendString("play 你失败了.mp3", 0, 0, 0);
}

void music_lose() {
	mciSendString("play 小马云.wav", 0, 0, 0);
}

void music_loseclose() {
	mciSendString("close 小马云.wav", 0, 0, 0);
}

void music_main1() {
	mciSendString("play rich.wav ", 0, 0, 0);
}

void  music_main1stop() {
	mciSendString("pause rich.wav ", 0, 0, 0);
}

void music_main1continue() {
	mciSendString("resume rich.wav ", 0, 0, 0);
}

void music_main1close() {
	mciSendString("close rich.wav ", 0, 0, 0);
}

void music_main2() {
	mciSendString("play 海里面.wav", 0, 0, 0);
}

void music_main2stop() {
	mciSendString("pause 海里面.wav", 0, 0, 0);
}

void music_main2continue() {
	mciSendString("resume 海里面.wav", 0, 0, 0);
}

void music_main2close() {
	mciSendString("close 海里面.wav ", 0, 0, 0);
}

void music_get() {
	mciSendString("play 到.wav ", 0, 0, 0);
}

void begin() {
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\tㄟ(▔＾▔ㄟ)      \n\n\n");
	printf("\t\t\t\t\t推箱子小游戏      \n\n\n");
	printf("\t\t\t\t\t请选择地图:(╯▔＾▔)╯\n\n");
	printf("\t\t\t\t\t简单：1  中等：2  困难：3\n\n");
	printf("\t\t\t\t\t请输入：");

pre:
	scanf("%d",&get);
	switch (get) {
	case 1:
		for (int k = 0; k < 10; k++) {
			for (int l = 0; l < 15; l++) {
				map[k][l] = totalmap[0][k][l];
			}
		}
		break;
	case 2:
		for (int k = 0; k < 10; k++) {
			for (int l = 0; l < 15; l++) {
				map[k][l] = totalmap[1][k][l];
			}
		}
		break;
	case 3:
		for (int k = 0; k < 10; k++) {
			for (int l = 0; l < 15; l++) {
				map[k][l] = totalmap[2][k][l];
			}
		}
		break;
	default:
		printf("\t\t\t\t\t请选择正确的难度：");
		goto pre;
		break;
	}
	system("cls");
}
