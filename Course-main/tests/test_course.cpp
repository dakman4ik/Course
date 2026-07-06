#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctect.h"
#include "course.hpp"

TEST_CASE("push_back добавляет элемент в конец") {
	Course c;
	c.push_back(10);
	CHECK(c.get_size() == 1);
	c.push_back(20);
	CHECK(c.get_size() == 2);
	CHECK(c[0] == 10 && c[1] == 20);
}
TEST_CASE("pop_back удаляет элемент с конца") {
	Course c;
	for (int i = 0; i < 5; ++i) {
		c.push_back(i * 10);
	}
	CHECK(c.get_size == 5 && c[c.get_size()] == 40);
	c.pop_back();
	CHECK(c.get_size == 4 && c[c.get_size()] == 30);
}