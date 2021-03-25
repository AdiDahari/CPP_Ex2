/**
 * The header file of the messageboard.
 * this file contains the structural implementation of the board.
 * each board created contains:
 * 1. map<uint, map<uint, Node>>: a map of maps of chars. contains the posted chars.
 * 2. [MIN, MAX]_[ROW, COL]: for marking the borders of the whole board and keeping it as small and pretty as possible.
 * 
 * Author: Adi Dahari
 * */
#pragma once
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <map>
#include <limits>

const uint INF = std::numeric_limits<uint>::max();
namespace ariel
{
    //Simple struct of a char cointaining node, for handling default values in map.
    struct Node
    {
        char letter = '_';
    };
    class Board
    {
    private:
        std::map<uint, std::map<uint, Node>> board;
        uint MIN_ROW, MIN_COL, MAX_ROW, MAX_COL;
        void post_horizontal(uint r, uint c, std::string const &msg);
        void post_vertical(uint r, uint c, std::string const &msg);

    public:
        Board() // an empty constructor for creating a new board.
        {
            MIN_ROW = MIN_COL = INF; // minimum row and col are set initially to maximum value of uint.
            MAX_ROW = MAX_COL = 0;   // maximum row and col are set initially to 0.
        }
        ~Board() {} // automatic destruction for the board created as it comes out of context.

        void post(uint r, uint c, Direction d, std::string const &msg);
        std::string read(uint r, uint c, Direction d, uint length);
        void show();
    };
}