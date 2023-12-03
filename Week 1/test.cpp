#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <new>
#include <vector>
#include <numeric>

bool isntNumeric(char input)
{
	std::string str (1, input);
	std::string nums = "1234567890";
	if ((nums.find(str) != std::string::npos))
	{
		return false;
	}
	return true;
}

int main() 
{
	std::string currentLine;
	std::ifstream file("input.txt");
	std::vector <long> sums{};
	if (file.is_open())
	{
		while (getline(file, currentLine))
		{
			std::cout << currentLine << " -> ";
			currentLine = std::regex_replace(currentLine, std::regex("one"), "one1one");
			currentLine = std::regex_replace(currentLine, std::regex("two"), "two2two");
			currentLine = std::regex_replace(currentLine, std::regex("three"), "three3three");
			currentLine = std::regex_replace(currentLine, std::regex("four"), "four4four");
			currentLine = std::regex_replace(currentLine, std::regex("five"), "five5five");
			currentLine = std::regex_replace(currentLine, std::regex("six"), "six6six");
			currentLine = std::regex_replace(currentLine, std::regex("seven"), "seven7seven");
			currentLine = std::regex_replace(currentLine, std::regex("eight"), "eight8eight");
			currentLine = std::regex_replace(currentLine, std::regex("nine"), "nine9nine");
			currentLine.erase(
					std::remove_if(currentLine.begin(), currentLine.end(), &isntNumeric),
					currentLine.end()
			);
			std::string combined = "" + currentLine.substr(0,1) + currentLine.substr(currentLine.size()-1, 1);
			sums.push_back(std::stoi(combined));
			std::cout << currentLine << ": " << combined << "\n";
		}
		file.close();
	}
	std::cout << std::accumulate(sums.begin(), sums.end(), 0) << "\n";
	return 0;
}
