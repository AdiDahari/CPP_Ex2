#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <map>
#include <math.h>
#include <iostream>
using namespace std;
const int INF = numeric_limits<int>::max();
namespace ariel
{
    class Board
    {
    private:
        string b;
        int MAX_ROW = 0, MAX_COL = 0, MIN_ROW = INF, MIN_COL = INF;
        map<int, map<int, char>> _board;

        void insert_horizontal(int row, int col, string msg)
        {
            if (row < MIN_ROW)
                MIN_ROW = row;
            else if (row > MAX_ROW)
                MAX_ROW = row;
            if (col + msg.length() > MAX_COL)
                MAX_COL = col + msg.length();
            else if (col < MIN_COL)
                MIN_COL = col;

            for (int i = 0; i < msg.length(); i++)
            {
                _board[row][col + i] = msg.at(i);
            }
        }
        void insert_vertical(int row, int col, string msg)
        {
            if (row < MIN_ROW)
                MIN_ROW = row;
            else if (row > MAX_ROW)
                MAX_ROW = MAX_ROW + msg.length();
            if (col + msg.length() > MAX_COL)
                MAX_COL = col;
            else if (col < MIN_COL)
                MIN_COL = col;

            for (int i = 0; i < msg.length(); i++)
            {
                _board[row + i][col] = msg.at(i);
            }
        }

    public:
        void post(int row, int column, Direction d, string msg)
        {
            if (row < 0 || column < 0 || msg == "" || (d != Direction::Horizontal && d != Direction::Vertical))
            {
                __throw_invalid_argument("One or more of the input arguments are not valid");
            }

            else
            {
                if (d == Direction::Horizontal)
                {
                    insert_horizontal(row, column, msg);
                }
                else
                {
                    insert_vertical(row, column, msg);
                }
            }
        }
        string read(int row, int column, Direction d, int length)
        {
            if (row < 0 || column < 0 || length < 1 || (d != Direction::Horizontal && d != Direction::Vertical))
            {
                __throw_invalid_argument("One or more of the input arguments are not valid");
            }

            if (row > MAX_ROW || column > MAX_COL || (d == Direction::Horizontal && MAX_COL < column + length) || (d == Direction::Vertical && MAX_ROW < row + length))
            {
                __throw_invalid_argument("Desired coordinates does not exists");
            }
        }
        void show()
        {
        }
    };
}