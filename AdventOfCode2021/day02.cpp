#include "AdventOfCode2021.h"

using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::getline;
using std::istringstream;
using std::string;
using std::string_view;
using std::unordered_map;

int distance = 0;
int depth = 0;
int aim = 0;

const unordered_map<string_view, function<void(int)>> command_map
{
	{ "forward", [](int amount) { distance += amount; depth += aim * amount; } },
	{ "up", [](int amount) { aim -= amount; } },
	{ "down", [](int amount) { aim += amount; } },
};

int main()
{
	string line;
	while (getline(cin, line))
	{
		istringstream stream(line);
		string key;
		int amount;
		stream >> key >> amount;
		auto& command = command_map.at(key);
		command(amount);
	}

	int result = distance * depth;
	cout << result << endl;

	return 0;
}
