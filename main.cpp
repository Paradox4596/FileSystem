#include <iostream>
#include <fstream>
#include <vector>

class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;

public:
	Monster(std::string name, int level, int hp, int mp) : mName{ name }, mLevel{ level }, mHP{ hp }, mMP{ mp }
	{
	}

	friend std::ostream& operator << (std::ostream& os, Monster m)
	{
		os << m.mName << " : " << m.mLevel << ", " << m.mHP << ", " << m.mMP;
		return os;
	}
};



bool LoadFile(const std::string& filename, std::vector<Monster>& monsters)
{
	// file stream
	std::ifstream ifs;
	//if (!ifs.good())
	//{
	//	std::cerr << filename << " not found!!" << std::endl;
	//}
	ifs.exceptions(std::ifstream::badbit);

	//file operation
	try
	{
		ifs.open(filename);
		
		char ch;

		while (ifs.get(ch))
		{
			/*std::cout << ch;*/
		}

		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << std::endl << e.code() << " - " << e.what() << std::endl;
		ifs.close();
		return false;
	}


	return true;



	/*while (ifs >> ch)
	{
		std::cout << ch;
	}*/

	//while (true)
	//{
	//	ifs.get(ch);

	//	if (ifs.eof())
	//	{
	//		std::cerr << "end of file!!" << std::endl;
	//		break;
	//	}

	//	if (ifs.fail())
	//	{
	//		std::cerr << "logical error!" << std::endl;
	//	}

	//	if (ifs.bad())
	//	{
	//		std::cerr << "fatal error!" << std::endl;
	//	}
	//}

	//char buffer[1024];
	//while (ifs.getline(buffer, 1024))
	//{
	//	std::cout << buffer << std::endl;
	//}

	// close file
	ifs.close();
	return true;
}

int main()
{
	std::vector<Monster> monsters;
	
	// path ( directory or folder, file )
	//LoadFile("E:/Downloadlink2/0VisualStudio/0814/FileSystem/Data/SimpleData.txt");
	//LoadFile("./Data/SimpleData.txt");
	LoadFile("Data/SimpleData.txt", monsters);

	for (const auto& e : monsters)
	{
		std::cout << e << std::endl;
	}
}