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

	b.post(0, 0, Direction::Horizontal, "This");
	b.post(0, 0, Direction::Vertical, "This");
	b.post(2, 2, Direction::Horizontal, "is");
	b.post(2, 2, Direction::Vertical, "is");
	b.post(4, 4, Direction::Horizontal, "Adi");
	b.post(4, 4, Direction::Vertical, "Adi");
	b.post(6, 6, Direction::Horizontal, "Dahari's");
	b.post(6, 6, Direction::Vertical, "Dahari's");
	b.post(8, 8, Direction::Horizontal, "MessageBoard");
	b.post(8, 8, Direction::Vertical, "MessageBoard");
	b.post(3, 30, Direction::Vertical, "W E L C O M E !!!");
	b.post(18, 28, Direction::Horizontal, "! ! !");
	// b.post(10, 6, Direction::Horizontal, "(C++ Assignment No.2)");

	b.show();
	return 0;
}
