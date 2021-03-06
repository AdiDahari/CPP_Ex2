#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Good read and post code")
{
    Board b;
    CHECK_NOTHROW(b.post(10, 5, Direction::Horizontal, "Hello"));
    CHECK_NOTHROW(b.post(9, 9, Direction::Vertical, "WORLD"));
    CHECK(b.read(10, 5, Direction::Horizontal, 5) == "HellO");
    CHECK_NOTHROW(b.post(0, 0, Direction::Horizontal, "hi"));
    CHECK_NOTHROW(b.post(0, 0, Direction::Vertical, "HI"));
}
TEST_CASE("Overwriting letters")
{
    Board b;
    CHECK_NOTHROW(b.post(0, 0, Direction::Horizontal, "First Check"));
    CHECK_NOTHROW(b.post(10, 5, Direction::Horizontal, "Adi"));
    CHECK_NOTHROW(b.post(10, 6, Direction::Horizontal, "Dahari"));
    CHECK(b.read(10, 5, Direction::Horizontal, 7) == "ADahari");
    CHECK_NOTHROW(b.post(10, 7, Direction::Vertical, "Adi"));
    CHECK(b.read(11, 6, Direction::Horizontal, 3) == "_d_");
    CHECK_NOTHROW(b.post(11, 6, Direction::Horizontal, "ADI"));
    CHECK(b.read(11, 6, Direction::Horizontal, 3) == "ADI");
    CHECK(b.read(10, 7, Direction::Vertical, 3) == "ADi");
}
TEST_CASE("Big sized board")
{
    Board b;
    CHECK_NOTHROW(b.post(0, 0, Direction::Horizontal, "One"));
    CHECK_NOTHROW(b.post(0, 0, Direction::Vertical, "One"));
    CHECK_NOTHROW(b.post(500, 500, Direction::Horizontal, "Two"));
    CHECK_NOTHROW(b.post(500, 500, Direction::Vertical, "Two"));
    CHECK_NOTHROW(b.post(1000, 1000, Direction::Horizontal, "Three"));
    CHECK_NOTHROW(b.post(1000, 1000, Direction::Vertical, "Three"));
    CHECK(b.read(1000, 1000, Direction::Horizontal, 5) == "Three");
    CHECK(b.read(1000, 1000, Direction::Vertical, 5) == "Three");
    CHECK(b.read(500, 500, Direction::Horizontal, 5) == "Two__");
    CHECK(b.read(500, 500, Direction::Vertical, 3) == "Two");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) == "One__");
    CHECK(b.read(0, 0, Direction::Vertical, 3) == "One");
}

TEST_CASE("Pretty printing (center the text area)")
{
    Board b;
    CHECK_NOTHROW(b.post(50, 50, Direction::Vertical, "|||"));
    CHECK_NOTHROW(b.post(50, 51, Direction::Horizontal, "----"));
    CHECK_NOTHROW(b.post(51, 51, Direction::Horizontal, "----"));
    CHECK_NOTHROW(b.post(52, 51, Direction::Horizontal, "----"));
    CHECK_NOTHROW(b.post(50, 55, Direction::Vertical, "|||"));
    CHECK_NOTHROW(b.post(49, 50, Direction::Horizontal, "\\..../"));
    CHECK_NOTHROW(b.post(53, 50, Direction::Horizontal, "/....\\"));
    CHECK_NOTHROW(b.post(48, 50, Direction::Horizontal, "/    \\"));
    CHECK_NOTHROW(b.post(54, 50, Direction::Horizontal, "\\    /"));
    CHECK_NOTHROW(b.post(47, 50, Direction::Horizontal, " /  \\"));
    CHECK_NOTHROW(b.post(55, 50, Direction::Horizontal, " \\  /"));
    CHECK_NOTHROW(b.post(46, 50, Direction::Horizontal, "  /\\"));
    CHECK_NOTHROW(b.post(56, 50, Direction::Horizontal, "  \\/"));
}
TEST_CASE("Empty board reading")
{
    Board b;
    for (int i = 0; i < 10; i++)
    {
        CHECK(b.read((uint)rand(), (uint)rand(), Direction::Horizontal, 10) == "__________");
        CHECK(b.read((uint)rand(), (uint)rand(), Direction::Vertical, 10) == "__________");
    }
}
TEST_CASE("Random posting")
{
    Board b;
    for (int i = 0; i < 100; i++)
    {
        CHECK_NOTHROW(b.post((uint)(rand() / 10), (uint)(rand() / 10), Direction::Horizontal, "CHECK " + to_string(i + 1)));
        CHECK_NOTHROW(b.post((uint)(rand() / 10), (uint)(rand() / 10), Direction::Vertical, "CHECK " + to_string(i + 1)));
    }
}
