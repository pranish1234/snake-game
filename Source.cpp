#include<iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruit_x, fruit_y, score, fruits_eaten;

enum direction{Stop =0, Left, Right, Up, Down};
direction dir;
void setup() {
	gameover = false;
	dir = Stop;
	x = width / 2;
	y = height / 2;
	fruit_x = rand() % width;
	fruit_y = rand() % height;
}

void draw() {
	system("cls");
	for (int i = 0; i < width+2; i++)
		cout << "_";
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width;j++) {

			if (j == 0)
				cout << "|";
			if (i == y && j == x)
				cout << "O";

			
			else if (i == fruit_y && j == fruit_x)
				cout << "*";
			else
				cout << " ";

			if (j == width - 1)
				cout << "|";
		}
		cout << endl;
	}

	for (int i = 0; i <= width+1; i++)
		cout << "_";
	cout << endl;
	cout << "fruits eaten::" << fruits_eaten<<endl;
	cout << "score::" << score<<endl;
	
}

void input() {
	if (_kbhit)
	{
		switch (_getch()) {
		case 'a':
			dir = Left;
			break;
		case 'd':
			dir = Right;
			break;
		case 's':
			dir = Up;
			break;
		case 'w':
			dir = Down;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}
void logic() {
	switch (dir)
	{
	case Left:
		x--;
		break;
	case Right:
		x++;
		break;
	case Up:
		y++;
		break;
	case Down:
		y--;
		break;
	default:
		break;
	}
	if (x > width || x<0 || y>height || y < 0)
		gameover = true;

	if (x == fruit_x && y == fruit_y)
	{
		
		fruits_eaten += 1;
		score += 10;
		fruit_x = rand() % width;
		fruit_y = rand() % height;
	}
		
	  
}
int main(){
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
		Sleep(10);
	}

	system("pause");
}