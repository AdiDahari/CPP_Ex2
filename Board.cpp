/**
 * The main implementation of the messageboard.
 * main public methods:
 * 1. post: posting a string type method on the board, by given coordinates, direction and the string to post.
 * 2. read: reading the board by given coordinates, direction and length to read.
 * 3. show: prints the whole board to the screen, each empty cell marked with "_".
 * 
 * private methods:
 * 1. post_horizontal: posting a message on the board horizontally.
 * 2. post_vertical: psoting a message on the board vertically.
 * 3. read_horizontal: reading a message from the board horizontally.
 * 4. read_vertical: reading a message from the board vertically.
 * 5. rebuild_board: a method for handling the size of the board. if needed, the number of rows/coloumns on the board grows.
 * 
 * Author: Adi Dahari 
 * */

#include <iostream>
#include "Board.hpp"
#include "Direction.hpp"
using namespace std;

namespace ariel
{
    /**
     * The post method has 2 private methods for inserting horizontally or vertically.
     * the message argument is checked for emptiness.
     * */
    void Board::post(uint r, uint c, Direction d, string const &msg)
    {
        if (msg.length() >= 1) // checking for empty string input.
        {
            bool flag = (d == Direction::Horizontal); // marking the direction using a boolean flag for easy redirection
            flag ? post_horizontal(r, c, msg) : post_vertical(r, c, msg);
        }
    }

    /**
     * The read method has 2 private methods for reading horizontally or vertically.
     * r (row) argument and c (column) check for catching a "Out of border" if given values not in Board's borders.
     * (if the desired coordinates does not exist on board, an exception is thrown).
     * */
    string Board::read(uint r, uint c, Direction d, uint length)
    {
        string msg;
        if (length == 0)
        {
            return msg;
        }
        else
        {
            bool flag = (d == Direction::Horizontal);
            for (uint i = 0; i < length; i++)
            {
                msg.push_back(board[r][c].letter);
                flag ? c++ : r++;
            }
            return msg;
        }
    }

    /**
     * The show message converts the map-type board to an output on screen including row numbers on the left side of the board itself.
     * */
    void Board::show()
    {
        for (uint i = MIN_ROW; i < MAX_ROW; i++)
        {
            cout << to_string(i) + ":\t";
            for (uint j = MIN_COL; j < MAX_COL; j++)
            {
                cout << board[i][j].letter;
            }
            cout << endl;
        }
    }

    void Board::post_horizontal(uint r, uint c, string const &msg)
    {
        if (r == 0)
        {
            MIN_ROW = 0;
        }
        if (c == 0)
        {
            MIN_COL = 0;
        }
        if (r - 1 >= 0 && r - 1 < MIN_ROW)
        {
            MIN_ROW = r - 1;
        }

        if (r + 2 > MAX_ROW)
        {
            MAX_ROW = r + 2;
        }
        if (c - 2 >= 0 && c - 2 < MIN_COL)
        {
            MIN_COL = c - 2;
        }
        if (c + 2 + msg.length() > MAX_COL)
        {
            MAX_COL = c + 2 + msg.length();
        }
        for (uint i = 0; i < msg.length(); i++)
        {
            if (msg.at(i) != ' ' && msg.at(i) != '\t')
            {
                board[r][c + i].letter = msg.at(i);
            }
        }
    }

    void Board::post_vertical(uint r, uint c, string const &msg)
    {
        if (r == 0)
        {
            MIN_ROW = 0;
        }
        if (c == 0)
        {
            MIN_COL = 0;
        }
        if (r - 1 >= 0 && r - 1 < MIN_ROW)
        {
            MIN_ROW = r - 1;
        }

        if (r + msg.length() + 1 > MAX_ROW)
        {
            MAX_ROW = r + 1 + msg.length();
        }
        if (c - 2 >= 0 && c - 2 < MIN_COL)
        {
            MIN_COL = c - 2;
        }
        if (c + 3 > MAX_COL)
        {
            MAX_COL = c + 3;
        }
        for (uint i = 0; i < msg.length(); i++)
        {
            if (msg.at(i) != ' ' && msg.at(i) != '\t')
            {
                board[r + i][c].letter = msg.at(i);
            }
        }
    }
}