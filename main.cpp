#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "Editor.h"

int main()
{
	Editor::consoleMenu();

	int selection {0};
	std::cin >> selection;

	if (selection==1)
	{
		Editor::fileCreation();
	}
	

	return 0;
}