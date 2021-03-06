#include <iostream>
extern "C" int lineFinder ( char* array, int width, int height);
int main() {
	int width, height;
	std::cout << "Enter array dimensions: ";
	std::cin >> width >> height;
	char* field = new char[width*height];
	for (int i = 0; i < height; i++)
	{
		std::cout << "Enter array line: ";
		for (int j = 0; j < width; j++)
		{
			char buffer;
			std::cin >> buffer;
			field[i*width + j] = buffer - '0';
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << (int)field[i*width + j] << " ";
		}
		std::cout << std::endl;
	}
	int result = lineFinder((char *)field, width, height);
	if (result <= 1)
	{
		std::cout << "There is no vertical lines in array!" << std::endl;
	}
	else
	{
		std::cout << "Maximal line length in aray: " << result << std::endl;
	}
	delete[] field;
}