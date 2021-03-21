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
        void post_horizontal(unsigned int r, unsigned int c, string msg);
        void post_vertical(unsigned int r, unsigned int c, string msg);
        string read_horizontal(unsigned int r, unsigned int c, unsigned int length);
        string read_vertical(unsigned int r, unsigned int c, unsigned int length);
        void rebuild_board();

    public:
        Board()
        {
            b = vector<vector<char>>(3, vector<char>(3));
            letters = map<unsigned int, map<unsigned int, char>>();
            MIN_ROW = MIN_COL = INF;
            MAX_ROW = MAX_COL = 0;
        }
        ~Board(){};

        void post(unsigned int r, unsigned int c, Direction d, string msg);
        string read(unsigned int r, unsigned int c, Direction d, unsigned int length);
        void show();
    };
}