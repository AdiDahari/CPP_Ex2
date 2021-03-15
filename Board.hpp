#pragma once

namespace ariel
{
    class Board
    {
    public:
        void post(int row, int column, Direction d, string msg);
        string read(int row, int column, Direction d, int length);
        void show();
    };
}