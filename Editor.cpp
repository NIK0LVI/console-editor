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
	std::cout << "8=================D \n";
	std::cout << "1. Create New File \n";
	std::cout << "2. Open File \n";
	std::cout << "3. Really need to find that string? \n";
	std::cout << "4. Count dem characters \n";
	std::cout << "5. Write to file \n";
	std::cout << "6. Delete File \n";
	std::cout << "7. Copy File \n";
	std::cout << "8. Exit \n";
	std::cout << "Enter selection: \n";

	std::cin >> selection;


	switch (selection)  // Should be the main menu logic via a switch statement.
	{
	case 1:
		Editor::fileCreation();
		break;
	case 2:
		Editor::fileOpen();
		break;
	case 3:
		Editor::fileSearchByString();
		break;
	case 4:
		Editor::fileCharacterCounter();
		break;
	case 5:
		Editor::fileWrite();
		break;
	case 6:
		Editor::fileDelete();
		break;
	case 7:
		Editor::fileCopy();
		break;
	case 8:
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

	std::cout << "\nEnd of file.\n Insert 1 to return to main menu. ";
	std::cin >> selection;
	
	Editor::consoleMenu();
	std::cin >> selection;
}

void Editor::fileSearchByString()
{
	std::string substring;

	std::cout << "Enter name of the file you wanna search: ";
	std::cin >> fileName;

	std::cout << "Enter string you wanna search for: ";
	std::cin >> substring;

	std::fstream myfile;
	myfile.open((fileName + ".txt").c_str());

	std::string cont;
	bool ans {0};
	int line {1};

	if (myfile.is_open())       
	{
		while (getline(myfile, cont))
		{
			if (cont.find(substring, 0) != std::string::npos) {
				{
					std::cout << "Aight, it do be here at  " << line << std::endl;
					ans = 1;     
				}
				++line;
			}
			myfile.close(); 
		}
	}
	else
		std::cout << "I'd love to, but I can't open the file.";

	if (!ans)   
		std::cout << "Ayyy, it ain't here at all." << std::endl;

	Editor::consoleMenu();
	std::cin >> selection;
}

void Editor::fileCharacterCounter()
{
	std::cout << "What's the file you really need that count for? ";
	std::cin >> fileName;

	std::fstream myfile;
	myfile.open((fileName + ".txt").c_str());

	char ch;
	int i, c = 0, sp = 0;
	while (myfile)
	{
		myfile.get(ch);
		i = ch;
		if ((i > 63 && i < 91) || (i > 96 && i < 123))
			c++;
		else
			if (ch == ' ')
				sp++;
	}
	std::cout << "\n No. of Characters in a File : " << c << std::endl;
	std::cout << "\n Space between the Words     : " << sp << std::endl;

	Editor::consoleMenu();
	std::cin >> selection;
}

void Editor::fileWrite()
{
	std::cout << "Enter name of file: ";
	std::cin >> fileName;

	std::cout << "Enter text to write: (Type END to finish)" << std::endl;
	std::ofstream myfile;
	myfile.open((fileName + ".txt").c_str(), std::ios::app);
	std::cin.ignore(); // Should ignore the buffer. 

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

