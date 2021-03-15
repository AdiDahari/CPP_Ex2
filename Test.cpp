#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

ariel::Board b;

TEST_CASE("Good read and post code")
{
    b.post(0, 0, Direction::Horizontal, "Hello");
    b.post(1, 0, Direction::Vertical, "World");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) + " " + b.read(2, 1, Direction::Vertical, 5) == "Hello World");
    CHECK(b.read(0, 0, Direction::Horizontal, 4) == "Hell");
    CHECK(b.read(1, 0, Direction::Vertical, 3) + b.read(6, 1, Direction::Vertical, 1) == "Word");
    CHECK(b.read(1, 1, Direction::Horizontal, 3) == "___");
    b.post(1, 1, Direction::Horizontal, "Hi");
    CHECK(b.read(1, 1, Direction::Horizontal, 3) == "Hi_");
    CHECK(b.read(2, 1, Direction::Horizontal, 3) == "___");
}
TEST_CASE("Bad read and post code")
{
    ariel::Board b;
    CHECK_THROWS(b.read(10, 20, Direction::Horizontal, 1));
    b.post(1, 1, Direction::Horizontal, "123456789");
    CHECK_THROWS(b.read(10, 20, Direction::Horizontal, 1));
    CHECK_THROWS(b.post(-11, -1, Direction::Vertical, "123456789"));
}
