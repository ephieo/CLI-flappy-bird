//#include "utils.h"
//
//
//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <dos.h>
//#include <stdlib.h>
//#include<string.h>
//#include <time.h>
//
//
//#define SCREEN_WIDTH 90
//#define SCREEN_HEIGHT 26
//#define WIN_WIDTH 70
//#define MENU_WIDTH 20
//#define GAP_SIZE 7 
//#define PIP_DIF 45
//
//using namespace std;
//
//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//COORD CursorPosition;
//
//
//int pipePos[3];
//int gapPos[3];
//int pipeFlag[3];
//char bird[2][6] = { '/','-','-','o','\\',' ','|','_','_','_',' ','>' };
//int birdPos = 6;
//int score = 0;
//
//
//void getZeroXY (int x, int y) {
//	CursorPosition.X = x;
//	CursorPosition.Y = y;
//	SetConsoleCursorPosition(console, CursorPosition);
//
//}
//void setcursor (bool visible, DWORD size){
//	// I'm passing in a variable called size wiht the type of DWORD
//	//if this is equal to zero I reassign it to 20. 
//	// then I save the struct info to lpCursor 
//	// I assign to the  bVisible method?  to either true or false via the visible variable. 
//	// assign sie to the 
//	if (size == 0) {
//		size = 20;
//	}
//	CONSOLE_CURSOR_INFO lpCursor;
//	lpCursor.bVisible = visible;
//	lpCursor.dwSize = size;
//	SetConsoleCursorInfo(console, &lpCursor);
//}
//void drawBorder() {
//
//	for (int i = 0; i < SCREEN_WIDTH; i++) {
//		getZeroXY(i, 0); std::cout << "�";
//		getZeroXY(i, SCREEN_HEIGHT); std::cout << "�";
//	}
//
//	for (int i = 0; i < SCREEN_HEIGHT; i++) {
//		getZeroXY(0, i); cout << "�";
//		getZeroXY(SCREEN_WIDTH, i); std::cout << "�";
//	}
//	for (int i = 0; i < SCREEN_HEIGHT; i++) {
//		getZeroXY(WIN_WIDTH, i); std::cout << "�";
//	}
//}
//void genPipe(int ind) {
//	gapPos[ind] = 3 + rand() % 14;
//}
//
//void drawPipe(int ind) {
//	if (pipeFlag[ind] == true) {
//		for (int i = 0; i < gapPos[ind]; i++) {
//			getZeroXY(WIN_WIDTH - pipePos[ind], i + 1); std::cout << "***";
//		}
//		for (int i = gapPos[ind] + GAP_SIZE; i <SCREEN_HEIGHT -1; i++) {
//			getZeroXY(WIN_WIDTH - pipePos[ind], i + 1); std::cout << "***";
//		}
//	}
//}
//
//void erasePipe(int ind) {
//	if (pipeFlag[ind] == true) {
//		for (int i = 0; i < gapPos[ind]; i++) {
//			getZeroXY(WIN_WIDTH - pipePos[ind], i + 1);
//			std::cout << "   ";
//		}
//		for (int i = gapPos[ind] + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++) {
//			getZeroXY(WIN_WIDTH - pipePos[ind], i + 1);
//			std::cout << "   ";
//		}
//	}
//}
//
//void drawBird() {
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 6; j++) {
//			getZeroXY(j + 2, i + birdPos); cout << bird[i][j];
//		}
//	}
//}
//
//void eraseBird() {
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 6; j++) {
//			getZeroXY(j + 2, i + birdPos); cout << " ";
//		}
//	}
//}
//
//
//int collision() {
//	if (pipePos[0] >= 61) {
//		if (birdPos<gapPos[0] || birdPos > gapPos[0] + GAP_SIZE) {
//			//std::cout << "HIT";
//			//getch()??????
//
//			return 1;
//		}
//	}
//	return 0;
//}
//
//void debug() {
//	//getZeroXY(SCREEN_WIDTH =3,4) std::cout<<"Pipe Position " <<pipePos[0];
//}
//
//void endGame (){
//	system("cls");
//	//commands the system to clean the screen 
//	std::cout << std::endl;
//	std::cout << "\t\t-------------------------------------" << std::endl;
//	std::cout << "\t\t------------ Game Over --------------" << std::endl;
//	std::cout << "\t\t-------------------------------------" << std::endl;
//	std::cout << "\t\t Press any key to go back to menu.   \n" << std::endl;
//	std::cout << "\t\t  YOUR FINAL SCORE :  "<<score<< std::endl;
//	//getch() is another way to get user content similar to cin>> ?? 
//	getch();
//}
//
//void updateScore() {
//	getZeroXY(WIN_WIDTH + 7, 5);
//		std::cout << "Score:" << score << std::endl; 
//}
//
//void instructions() {
//	system("cls");
//	//commands the system to clean the screen 
//	std::cout << std::endl;
//	std::cout << "Instructions" << std::endl;
//	std::cout << "\n--------------------------" << std::endl;
//	std::cout << "\n Press spacebar to make the bird fly" << std::endl;
//	std::cout << "\n\n Press any key to go back to menu " << std::endl;
//	//getch() is another way to get user content similar to cin>> ?? 
//	getch();
//}
//
//void play() {
//
//	birdPos = 6;
//	score = 0;
//	pipeFlag[0] = 1;
//	pipeFlag[1] = 0;
//	pipePos[0] = pipePos[1] = 4;
//
//	system("cls");
//	drawBorder();
//	genPipe(0);
//	updateScore();
//	getZeroXY(WIN_WIDTH + 5, 2); std::cout << "FLAPPY BIRD";
//	getZeroXY(WIN_WIDTH + 6, 4); std::cout << "----------";
//	getZeroXY(WIN_WIDTH + 6, 6); std::cout << "----------";
//	getZeroXY(WIN_WIDTH + 7, 12); std::cout << "Control ";
//	getZeroXY(WIN_WIDTH + 7, 13); std::cout << "-------- ";
//	getZeroXY(WIN_WIDTH + 2, 14); std::cout << " Spacebar = jump";
//
//	getZeroXY(10, 5); std::cout << "Press any key to start";
//	getch();
//	getZeroXY(10, 5); cout << "                      ";
//
//	while (1) {
//
//		if (kbhit()) {
//			char ch = getch();
//			if (ch == 32) {
//				if (birdPos > 3)
//					birdPos -= 3;
//			}
//			if (ch == 27) {
//				break;
//			}
//		}
//
//		drawBird();
//		drawPipe(0);
//		drawPipe(1);
//		debug();
//		if (collision() == 1) {
//			endGame();
//			return;
//		}
//		Sleep(100);
//		eraseBird();
//		erasePipe(0);
//		erasePipe(1);
//		birdPos += 1;
//
//		if (birdPos > SCREEN_HEIGHT - 2) {
//			endGame();
//			return;
//		}
//
//		if (pipeFlag[0] == 1)
//			pipePos[0] += 2;
//
//		if (pipeFlag[1] == 1)
//			pipePos[1] += 2;
//
//		if (pipePos[0] >= 40 && pipePos[0] < 42) {
//			pipeFlag[1] = 1;
//			pipePos[1] = 4;
//			genPipe(1);
//		}
//		if (pipePos[0] > 68) {
//			score++;
//			updateScore();
//			pipeFlag[1] = 0;
//			pipePos[0] = pipePos[1];
//			gapPos[0] = gapPos[1];
//		}
//
//	}
//
//}