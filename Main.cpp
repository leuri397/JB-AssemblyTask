#include <iostream>
extern "C" int lineFinder ( char* array, int width, int height);
int main() {
	char field[][5] = {
		{4, 1, 5, 1, 1},
		{1, 2, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 0, 1},
		{1, 1, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 3, 1, 1},
		{1, 0, 1, 5, 1},
		{1, 0, 1, 5, 1},
		{1, 0, 2, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 1}
	};
	int width = sizeof(field[0]), height = sizeof(field)/sizeof(field[0]);
	std::cout << lineFinder((char*)field, width, height) << std::endl;
}