/**
 * The header file of the messageboard.
 * this file contains the structural implementation of the board.
 * each board created contains:
 * 1. vector<vector<char>>: a vector of vectors of char, the board itself in a way. each index of the outer vector represents a row number,
 *    each index of the inner vector represents a column number.
 * 2. map<unsigned int, map<unsigned int, char>>: a map of maps of chars. contains the posted chars.
 *    as it seems useless, it comes handy when the board extends to the left/upwards for keeping the exact coordinates of each letter on the board.
 * 3. [MIN, MAX]_[ROW, COL]: for marking the borders of the whole board and keeping it as small and pretty as possible.
 * 
 * Author: Adi Dahari
 * */
#pragma once
#include "Direction.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
using namespace std;

const unsigned int INF = numeric_limits<unsigned int>::max();
namespace ariel
{
    class Board
    {
    private:
        vector<vector<char>> b;
        map<unsigned int, map<unsigned int, char>> letters;
        unsigned int MIN_ROW, MIN_COL, MAX_ROW, MAX_COL;
        void post_horizontal(unsigned int r, unsigned int c, string const &msg);
        void post_vertical(unsigned int r, unsigned int c, string const &msg);
        string read_horizontal(unsigned int r, unsigned int c, unsigned int length);
        string read_vertical(unsigned int r, unsigned int c, unsigned int length);
        void rebuild_board();

    public:
        Board() // an empty constructor for creating a new board. vector and map initialization.
        {
            b = vector<vector<char>>(1, vector<char>(0));
            letters = map<unsigned int, map<unsigned int, char>>();
            MIN_ROW = MIN_COL = INF; // minimum row and col are set initially to maximum value of unsigned int.
            MAX_ROW = MAX_COL = 0;   // maximum row and col are set initially to 0.
        }
        ~Board() {} // automatic destruction for the board created as it comes out of context.

        void post(unsigned int r, unsigned int c, Direction d, string const &msg);
        string read(unsigned int r, unsigned int c, Direction d, unsigned int length);
        void show();
    };
}