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
	b.post(3 + i, 30 + i, Direction::Vertical, "W E L C O M E !!!");
	b.post(18 + i, 28 + i, Direction::Horizontal, "! ! !");
	b.post(10 + i, 6 + i, Direction::Horizontal, "(C++ Assignment No.2)");
	b.show();
	return 0;
}
