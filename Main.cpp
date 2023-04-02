#include <iostream>
#include <string>
#include "ConsoleColours.h"
#include <Windows.h>

#ifndef NDEBUG
#define DebugReleaseValue(Debug, Release) Debug
#else
#define DebugReleaseValue(Debug, Release) Release
#endif

const int DEFAULT_TIME_BETWEEN_DOTS = DebugReleaseValue(500, 5000);

std::string logo = R"DATA(  _                           
 | |                          
 | |    _   _ _ __   __ _ ___ 
 | |   | | | | '_ \ / _` / __|
 | |___| |_| | | | | (_| \__ \
 |______\__,_|_| |_|\__, |___/
                     __/ |    
                    |___/     
)DATA";

void OpenURL(const char* url) {
	std::string command = "explorer.exe ";
	command += url;
	system(command.c_str());
}

void ClearConsole();

void PrintLogo() {
	std::cout << Color::Cyan << logo << Color::BrightWhite << std::endl;
}

void ClearConsole() {
	system("cls");
	PrintLogo();
}


void WaitForEnter(bool shouldSayPressAnyKeyToContinueOrNot) {
	if (shouldSayPressAnyKeyToContinueOrNot)
		system("pause");
	else {
		std::string clearlinethingstr;
		std::getline(std::cin, clearlinethingstr);
		std::cin.get();
	}
}

void PrintOption(int optionCount, const char* name) {
	std::cout << Color::BrightBlue << "[";
	std::cout << Color::BrightWhite << optionCount;
	std::cout << Color::BrightBlue << "] " << Color::BrightWhite << name << std::endl;
}

int main() {
	SetConsoleTitleA("Lungs");
	do {
		ClearConsole();
		PrintOption(1, "Lung");
		PrintOption(2, "Lungs Website");
		PrintOption(10, "Exit");
		std::cout << std::endl;
		int optionChosen = 0;
		std::cin >> optionChosen;

		if (std::cin.fail()) {
			//clear error
			std::cin.clear();
			//clear rest of content
			std::string clearlinethingstr;
			std::getline(std::cin, clearlinethingstr);
			std::cout << Color::Red << "Invalid choice!" << std::endl;
			std::cin.get();
			ClearConsole();
			continue;
		}

		switch (optionChosen) {
		case 1:
			std::cout << Color::BrightWhite << "Lung" << std::endl;
			WaitForEnter(true);
			return 0;
		case 2:
			OpenURL("https://lungs.tech/");
			break;
		case 10:
			return 0;
		default:
			std::cout << Color::Red << "Invalid choice!" << Color::BrightWhite << std::endl;
			std::string clearlinethingstr;
			std::getline(std::cin, clearlinethingstr);
			std::cin.get();
		}
		ClearConsole();
	} while (true);
}

