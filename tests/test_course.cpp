#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Course.hpp"

TEST_CASE("push_back добавляет элемент в конец") {
    Course c;
    c.push_back(10);
    c.push_back(20);
    CHECK(c.get_size() == 2);
    CHECK(c[0] == 10);
    CHECK(c[1] == 20);
}
TEST_CASE("pop_back удаляет последний элемент") {
    Course c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.pop_back();
    CHECK(c.get_size() == 2);
    CHECK(c[1] == 2);
}