#include "Editor.h"
#include <iostream>
#include <string>
#include <fstream>

int selection {0};
std::string fileName;
std::string line;
std::string clone;

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

	std::cin >> selection;


	switch (selection)  // Logic
	{
	case 1:
		Editor::fileCreation();
		break;
	case 2:
		Editor::fileOpen();
		break;
	case 3:
		Editor::fileWrite();
		break;
	case 4:
		Editor::fileDelete();
		break;
	case 5:
		Editor::fileCopy();
		break;
	case 6:
		Editor::exitProgram();
		break;
	default:
		std::cout << "You really be trolling with that option, ayyy.";
		break;
	}
}

void Editor::fileCreation()
{
	std::cout << "Enter name of file: ";
	std::cin.ignore();
	std::getline(std::cin, fileName);
	std::ofstream myfile((fileName + ".txt").c_str());
	myfile.close();

	Editor::consoleMenu();
	std::cin >> selection;
}

void Editor::fileOpen()
{
	std::cout << "Enter name of the file you would like opened: ";
	std::cin >> fileName;

	std::fstream myfile;
	myfile.open((fileName + ".txt").c_str());

	
	while (std::getline(myfile, fileName))
	{
		std::cout << fileName << "\n";
	}
	myfile.close();

	std::cout << "\nEnd of file.\n Would you like to search the file or return to main menu? ";
	std::cin >> selection;
	
	if (selection==1)
	{
		Editor::fileSearchMenu();
	}
	else
	{
		Editor::consoleMenu();
	}
}

void Editor::fileSearchMenu()
{
	std::cout << "1. Search by string \n";
	std::cout << "2. Search by composition \n";
	std::cout << "3. Return to main menu \n";

	std::cin >> selection;
}

void Editor::fileSearchByString()
{
}

void Editor::fileSearchByChar()
{
}

void Editor::fileWrite()
{
	std::cout << "Enter name of file: ";
	std::cin >> fileName;

	std::cout << "Enter text to write: (Type END to finish)" << std::endl;
	std::ofstream myfile;
	myfile.open((fileName + ".txt").c_str(), std::ios::app);
	std::cin.ignore(); // Ignores the buffer

	while (std::getline(std::cin, line))
	{
		if (line.size() >= 3)
		{
			if (line.substr(line.size() - 3) == "END")
			{
				fileName += line.substr(0, line.size() - 3);
				break;
			}
			else
			{
				fileName += line + "\n";
			}
		}
		else
		{
			fileName += line + "\n";
		}
	}

	myfile << fileName;
	myfile.close();

	Editor::consoleMenu();
	std::cin >> selection;
}

void Editor::fileDelete()
{
	std::cout << "Enter name of the file: ";
	std::cin >> fileName;

	if (remove((fileName + ".txt").c_str()) == 0)
	{
		std::cout << "\n Great success!" << std::endl;
	}
	else
		std::cout << "\n You ain't deleting shit." << std::endl;

	Editor::consoleMenu();
	std::cin >> selection;
}

void Editor::fileCopy()
{
	std::cout << "You gotta copy something: ";
	std::cin.ignore();
	std::getline(std::cin, fileName);
	std::fstream myfile((fileName + ".txt").c_str());
	while (std::getline(myfile, line))
	{
		fileName += line + "\n";
	}
	myfile.close();
	std::cout << "You gotta copy it somewhere: ";
	std::getline(std::cin, clone);
	std::ofstream myfile2;
	myfile2.open((clone + ".txt").c_str(), std::ios::app);
	myfile2 << fileName;
	myfile2.close();

	Editor::consoleMenu();
	std::cin >> selection;
}

void Editor::exitProgram()
{
	exit(EXIT_SUCCESS);
}

