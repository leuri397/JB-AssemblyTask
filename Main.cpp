#include <iostream>
extern "C" int lineFinder ( char* array, int width, int height);
int main() {
	char field[][6] = {
		{0, 0, 0, 0, 0, 0},
		{3, 1, 3, 0, 1, 1},
		{0, 1, 0, 0, 3, 2},
		{3, 3, 2, 1, 1, 4},
		{4, 2, 4, 1, 0, 2},
		{1, 3, 2, 3, 3, 0}
	};
	int width = sizeof(field[0]), height = sizeof(field)/sizeof(field[0]);
	std::cout << lineFinder((char*)field, width, height) << std::endl;
}