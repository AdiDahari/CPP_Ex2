#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Board
    {
    private:
        string b;
        int MAX_ROW = 0, MAX_COL = 0;

    public:
        void post(int row, int column, Direction d, string msg)
        {
            if (row < 0 || column < 0 || msg == "" || (d != Direction::Horizontal && d != Direction::Vertical))
            {
                __throw_invalid_argument("One or more of the input arguments are not valid");
            }
        }
        string read(int row, int column, Direction d, int length)
        {
            if (row < 0 || column < 0 || length < 1 || (d != Direction::Horizontal && d != Direction::Vertical))
            {
                __throw_invalid_argument("One or more of the input arguments are not valid");
            }

            if (row > MAX_ROW || column > MAX_COL)
            {
                __throw_invalid_argument("Desired coordinates does not exists");
            }
        }
        void show()
        {
        }
    };
}