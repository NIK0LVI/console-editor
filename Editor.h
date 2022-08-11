#pragma once

class Editor
{
public:  // Static binding for faster runtime.
	void static consoleMenu();
	void static fileCreation();
	void static fileOpen();
	void static fileSearchMenu();
	void static fileSearchByString();
	void static fileSearchByChar();
	void static fileWrite();
	void static fileDelete();
	void static fileCopy();
	void static exitProgram();
};

