#pragma once

class Editor
{
public:  // Static binding because internet says it runs faster at runtime.
	void static consoleMenu();
	void static fileCreation();
	void static fileOpen();
	void static fileSearchByString();
	void static fileCharacterCounter();
	void static fileWrite();
	void static fileDelete();
	void static fileCopy();
	void static exitProgram();
};

