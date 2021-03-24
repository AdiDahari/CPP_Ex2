/**
 * The header file of the messageboard.
 * this file contains the structural implementation of the board.
 * each board created contains:
 * 1. vector<vector<char>>: a vector of vectors of char, the board itself in a way. each index of the outer vector represents a row number,
 *    each index of the inner vector represents a column number.
 * 2. map<uint, map<uint, char>>: a map of maps of chars. contains the posted chars.
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
// using namespace std;

const uint INF = std::numeric_limits<uint>::max();
namespace ariel
{
    class Board
    {
    private:
        std::vector<std::vector<char>> b;
        std::map<uint, std::map<uint, char>> letters;
        uint MIN_ROW, MIN_COL, MAX_ROW, MAX_COL;
        void post_horizontal(uint r, uint c, std::string const &msg);
        void post_vertical(uint r, uint c, std::string const &msg);
        std::string read_horizontal(uint r, uint c, uint length);
        std::string read_vertical(uint r, uint c, uint length);
        void rebuild_board();

    public:
        Board() // an empty constructor for creating a new board. vector and map initialization.
        {
            b = std::vector<std::vector<char>>(1, std::vector<char>(0));
            letters = std::map<uint, std::map<uint, char>>();
            MIN_ROW = MIN_COL = INF; // minimum row and col are set initially to maximum value of uint.
            MAX_ROW = MAX_COL = 0;   // maximum row and col are set initially to 0.
        }
        ~Board() {} // automatic destruction for the board created as it comes out of context.

        void post(uint r, uint c, Direction d, std::string const &msg);
        std::string read(uint r, uint c, Direction d, uint length);
        void show();
    };
}