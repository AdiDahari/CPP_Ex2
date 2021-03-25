/**
 * Demo program for message-board exercise.
 * 
 * Author: Adi Dahari
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	ariel::Board b;
	uint i = (uint)(rand() / 10);
	b.post(0 + i, 0 + i, Direction::Horizontal, "this");
	b.post(0 + i, 0 + i, Direction::Vertical, "This");
	b.post(2 + i, 2 + i, Direction::Horizontal, "is");
	b.post(2 + i, 2 + i, Direction::Vertical, "Is");
	b.post(4 + i, 4 + i, Direction::Horizontal, "adi");
	b.post(4 + i, 4 + i, Direction::Vertical, "Adi");
	b.post(6 + i, 6 + i, Direction::Horizontal, "dahari's");
	b.post(6 + i, 6 + i, Direction::Vertical, "Dahari's");
	b.post(8 + i, 8 + i, Direction::Horizontal, "messageBoard");
	b.post(8 + i, 8 + i, Direction::Vertical, "MessageBoard");
	b.post(0 + i, 29 + i, Direction::Vertical, "|||||||||||||");
	b.post(0 + i, 30 + i, Direction::Vertical, "W E L C O M E");
	b.post(0 + i, 31 + i, Direction::Vertical, "|||||||||||||");

	b.post(13 + i, 10 + i, Direction::Horizontal, "       __      ");
	b.post(14 + i, 10 + i, Direction::Horizontal, "      /  \\    ");
	b.post(15 + i, 10 + i, Direction::Horizontal, "     /    \\   ");
	b.post(16 + i, 10 + i, Direction::Horizontal, "    /  /\\  \\  ");
	b.post(17 + i, 10 + i, Direction::Horizontal, "   /  /__\\  \\ ");
	b.post(18 + i, 10 + i, Direction::Horizontal, "  /  ______  \\");
	b.post(19 + i, 10 + i, Direction::Horizontal, " /__/      \\__\\");
	b.post(13 + i, 24 + i, Direction::Horizontal, " ________    ");
	b.post(14 + i, 24 + i, Direction::Horizontal, "|        \\   ");
	b.post(15 + i, 24 + i, Direction::Horizontal, "|   ___   \\  ");
	b.post(16 + i, 24 + i, Direction::Horizontal, "|  |   \\   \\ ");
	b.post(17 + i, 24 + i, Direction::Horizontal, "|  |___/   / ");
	b.post(18 + i, 24 + i, Direction::Horizontal, "|         /  ");
	b.post(19 + i, 24 + i, Direction::Horizontal, "|________/   ");

	b.show();
	cout << endl
		 << b.read(0 + i, 0 + i, Direction::Horizontal, 4) + " ";
	cout << b.read(2 + i, 2 + i, Direction::Horizontal, 2) + " ";
	cout << b.read(4 + i, 4 + i, Direction::Horizontal, 3) + " ";
	cout << b.read(6 + i, 6 + i, Direction::Horizontal, 8) + " ";
	cout << b.read(8 + i, 8 + i, Direction::Horizontal, 12) << endl;
	return 0;
}
