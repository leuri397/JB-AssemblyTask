#include <iostream>
extern "C" int lineFinder ( char* array, int width, int height);
int main() {
	char field[][6] = {
		{2, 0, 0, 0, 0, 4},
		{8, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 6},
		{4, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 2},
		{1, 1, 1, 1, 1, 1}
	};
	int width = sizeof(field[0]), height = sizeof(field)/sizeof(field[0]);
	std::cout << lineFinder((char*)field, width, height - 2) << std::endl;
	std::cout << width << " " << height << std::endl;
}