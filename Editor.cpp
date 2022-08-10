#include "Editor.h"
#include <iostream>
#include <string>
#include <fstream>



void Editor::consoleMenu()
{
	std::cout << "Main Menu \n";
	std::cout << "------------- \n";
	std::cout << "1. Create New File \n";
	std::cout << "2. Open File \n";
	std::cout << "3. Write to File \n";
	std::cout << "4. Delete File \n";
	std::cout << "5. Copy File \n";
	std::cout << "6. Exit \n";
	std::cout << "Enter selection: \n";
}

void Editor::fileCreation()
{
	std::string fileName;
	
	std::cout << "Enter name of file: ";
	std::cin.ignore();
	std::getline(std::cin, fileName);
	std::ofstream myfile((fileName + ".txt").c_str());
	myfile.close();
}
