#include <iostream>
#include <string>
#include <vector>
#include "Board.hpp"
#include "Direction.hpp"
using namespace std;

namespace ariel
{
    void Board::post(unsigned int r, unsigned int c, Direction d, string const &msg)
    {
        if (msg.length() < 1)
        {
            __throw_invalid_argument("Invalid Input");
        }
        else
        {

            bool flag = (d == Direction::Horizontal);
            flag ? post_horizontal(r, c, msg) : post_vertical(r, c, msg);
        }
    }

    string Board::read(unsigned int r, unsigned int c, Direction d, unsigned int length)
    {
        // cout << "ARGS: r = " + to_string(r) + " ,r + length = " + to_string(r + length) + " ,c = " + to_string(c) + " ,c + length= " + to_string(c + length) + " , MAX_ROW = " + to_string(MAX_ROW) + " , MIN_ROW = " + to_string(MIN_ROW) + " , MAX_COL = " + to_string(MAX_COL) + " , MIN_COL = " + to_string(MIN_COL) << endl;
        string msg;
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
    void Board::show()
    {
        for (unsigned int i = 0; i < b.size(); i++)
        {
            cout << to_string(i + MIN_ROW) + ":\t";
            for (unsigned int j = 0; j < b[i].size(); j++)
            {
                cout << b[i][j];
            }
            cout << endl;
        }
    }

    void Board::post_horizontal(unsigned int r, unsigned int c, string const &msg)
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
        for (unsigned int i = 0; i < msg.length(); i++)
        {
            letters[r][c + i] = msg.at(i);
        }

        rebuild_board();
    }

    void Board::post_vertical(unsigned int r, unsigned int c, string const &msg)
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
        for (unsigned int i = 0; i < msg.length(); i++)
        {
            letters[r + i][c] = msg.at(i);
        }
        rebuild_board();
    }

    string Board::read_horizontal(unsigned int r, unsigned int c, unsigned int length)
    {
        string msg;
        for (unsigned int i = 0; i < length; i++)
        {
            msg.push_back(b[r - MIN_ROW][c - MIN_COL + i]);
        }
        return msg;
    }

    string Board::read_vertical(unsigned int r, unsigned int c, unsigned int length)
    {
        string msg;
        for (unsigned int i = 0; i < length; i++)
        {
            msg.push_back(b[r - MIN_ROW + i][c - MIN_COL]);
        }

        return msg;
    }

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