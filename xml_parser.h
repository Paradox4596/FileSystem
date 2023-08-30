#pragma once
#include <string>
#include <vector>
#include <regex>
#include <fstream>

class Sprite
{
public:
	std::string n;
	int x;
	int y;
	int w;
	int h;
};

void LoadXML(const char* filename, std::vector<Sprite>& sprites)
{
	sprites.clear();

	std::ifstream file(filename, std::ifstream::binary);
	std::string line;
	std::regex pattern("\"([^\"]*)\"");
}

void XMLTest()
{
	std::vector<Sprite> sprites;

	LoadXML("Data/mydata.xml", sprites);
}