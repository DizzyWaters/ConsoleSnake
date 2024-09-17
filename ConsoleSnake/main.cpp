#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <conio.h>

const int WIDTH = 80;
const int HEIGHT = 20;

// chars
const char left_top_board_angle = 218;
const char plank = 196;
const char right_top_board_angle = 191;
const char empty_field = 176;
const char vertical_plank = 179;
const char right_bottom_board_angle = 217;
const char left_bottom_board_angle = 192;

char field[HEIGHT][WIDTH];

void Input(int& x, int& y)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'd':
			x++;
			break;
		case 'a':
			x--;
			break;
		default:
			break;
		}
	}
}

void DrawSnake(int x, int y) {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			field[HEIGHT / 4 + y][WIDTH / 4 + x] = 'X';
		}
	}
}

void DrawFruit() {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			field[10][10] = 'G';
		}
	}
}


void Field_Init()
{
	int game_field_width = WIDTH / 2;
	int game_field_height = HEIGHT;


	field[0][0] = left_top_board_angle;
	field[0][game_field_width - 1] = right_top_board_angle;
	field[HEIGHT - 1][game_field_width - 1] = right_bottom_board_angle;
	field[HEIGHT - 1][0] = left_bottom_board_angle;

	for (int i = 1; i < game_field_width - 2; ++i) {
		field[0][i] = plank;
	}
	for (int i = 1; i < game_field_width - 2; ++i)
	{
		field[HEIGHT - 1][i] = plank;
	}
	for (int i = 1; i < HEIGHT - 1; ++i) {
		field[i][0] = vertical_plank;
	}
	for (int i = 1; i < HEIGHT - 1; ++i) {
		field[i][game_field_width - 2] = vertical_plank;
	}

	// inside
	for (int i = 1; i < HEIGHT - 1; ++i) {
		for (int j = 1; j < game_field_width - 2; ++j) {
			field[i][j] = empty_field;
		}
	}

	// right menu
	//make border
	// fill with empty space

	int menuLength = WIDTH - 4;




	field[0][game_field_width] = left_top_board_angle;
	field[0][menuLength + 1] = right_top_board_angle;
	field[HEIGHT - 1][menuLength + 1] = right_bottom_board_angle;
	field[HEIGHT - 1][game_field_width ] = left_bottom_board_angle;
	
	for (int i = game_field_width + 1; i < menuLength -1; ++i) {
		field[0][i] = plank;// up
	}
	for (int i = game_field_width + 2; i < menuLength; ++i)
	{
		field[HEIGHT - 1][i] = plank; // down
	}
	for (int i = 1; i < HEIGHT - 1; ++i) {
		field[i][menuLength] = vertical_plank;
	}
	for (int i = 1; i < HEIGHT - 1; ++i) {
		field[i][game_field_width + 1] = vertical_plank;
	}

	// inside

	for (int i = 1; i < HEIGHT - 1; ++i) {
		for (int j = game_field_width + 2; j < menuLength; ++j) {
			field[i][j] = ' ';
		}
	}
}

void Draw()
{
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			std::cout << field[i][j];
		}
		std::cout << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(30));
}

int main()
{
	int x, y;
	x = 0;
	y = 0;
	while (1)
	{
		system("cls");
		Field_Init();
		Input(x, y);
		DrawSnake(x, y);
		DrawFruit();
		Draw();

	}
	return 0;
}