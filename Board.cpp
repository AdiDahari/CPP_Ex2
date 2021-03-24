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
        if (msg.length() < 1) // checking for empty string input.
        {
            return;
        }
        else
        {

            bool flag = (d == Direction::Horizontal); // marking the direction using a boolean flag for easy redirection
            flag ? post_horizontal(r, c, msg) : post_vertical(r, c, msg);
        }
    }

    /**
     * The read method has 2 private methods for reading horizontally or vertically.
     * r (row) argument and c (column) check for catching a "Out of border" try of reading 
     * (if the desired coordinates does not exist on board, an exception is thrown).
     * */
    string Board::read(uint r, uint c, Direction d, uint length)
    {
        string msg;
        if (length == 0)
        {
            return msg;
        }
        if ((d == Direction::Horizontal && (r < MIN_ROW || r > MAX_ROW || c < MIN_COL || c + length - 1 > MAX_COL)) ||
            (d == Direction::Vertical && (r < MIN_ROW || r + length - 1 > MAX_ROW || c < MIN_COL || c > MAX_COL)))
        {
            __throw_out_of_range("Out of Board's range");
        }
        else
        {
            bool flag = (d == Direction::Horizontal);
            if (flag)
            {
                msg = read_horizontal(r, c, length);
            }
            else
            {
                msg = read_vertical(r, c, length);
            }
            return msg;
        }
    }

    /**
     * The show message converts the vector-type board to an output on screen including row numbers on the left side of the board itself.
     * */
    void Board::show()
    {
        for (uint i = 0; i < b.size(); i++)
        {
            cout << to_string(i + MIN_ROW) + ":\t";
            for (uint j = 0; j < b[i].size(); j++)
            {
                cout << b[i][j];
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
            letters[r][c + i] = msg.at(i);
        }

        rebuild_board();
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
            letters[r + i][c] = msg.at(i);
        }
        rebuild_board();
    }

    string Board::read_horizontal(uint r, uint c, uint length)
    {
        string msg;
        for (uint i = 0; i < length; i++)
        {
            msg.push_back(b[r - MIN_ROW][c - MIN_COL + i]);
        }
        return msg;
    }

    string Board::read_vertical(uint r, uint c, uint length)
    {
        string msg;
        for (uint i = 0; i < length; i++)
        {
            msg.push_back(b[r - MIN_ROW + i][c - MIN_COL]);
        }

        return msg;
    }

    /**
     * The rebuild-board method handles each change may be caused by posting a new message to the board.
     * as the map structure keeps all coordinates of the chars on board, 
     * a new vector board is created and all the existing chars of the map are being copied to the vector board.
     * This method also handles any spaces or tabs by converting them to '_'.
     * */
    void Board::rebuild_board()
    {
        b = vector<vector<char>>((MAX_ROW - MIN_ROW), vector<char>(MAX_COL - MIN_COL, '_'));
        for (auto const &[k1, v1] : letters)
        {
            for (auto const &[k2, v2] : v1)
            {
                if (v2 == '\t' || v2 == ' ')
                {
                    b[k1 - MIN_ROW][k2 - MIN_COL];
                }
                else
                {
                    b[k1 - MIN_ROW][k2 - MIN_COL] = v2;
                }
            }
        }
    }
}