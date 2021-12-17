#include "AdventOfCode2021.h"

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;
using std::reduce;
using std::rotate;
using std::size_t;
using std::stoi;
using std::string;
using value_t = std::uint64_t;

const size_t days = 256;

int main()
{
	array<value_t, 9> lanternfish{};

	string line;
	getline(cin, line);
	istringstream stream{line};
	while (getline(stream, line, ','))
	{
		size_t i = stoi(line);
		lanternfish[i]++;
	}

	for (size_t day = 1; day <= days; day++)
	{
		value_t new_count = lanternfish[0];
		rotate(lanternfish.begin(), lanternfish.begin() + 1, lanternfish.end());
		lanternfish[6] += new_count;
	}

	cout << reduce(lanternfish.cbegin(), lanternfish.cend(), 0ull) << endl;

	return 0;
}
