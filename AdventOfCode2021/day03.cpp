#include "AdventOfCode2021.h"

using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::size_t;
using std::string;
using std::vector;
using std::function;
using std::ranges::count_if;
using std::ranges::remove_if;
using bit_criteria_t = function<bool(int, int)>;

const size_t N{12};

bit_criteria_t ones_more = [](int zeros, int ones) { return ones >= zeros; };
bit_criteria_t zeros_more = [](int zeros, int ones) { return zeros > ones; };

bitset<N> part1(const vector<bitset<N>>& numbers, bit_criteria_t bit_criteria)
{
	bitset<N> result;
	for (int i = N - 1; i >= 0; i--)
	{
		int ones = count_if(numbers, [i](const bitset<N>& n) { return n.test(i); });
		int zeros = count_if(numbers, [i](const bitset<N>& n) { return !n.test(i); });

		result.set(i, bit_criteria(zeros, ones));
	}
	return result;
}

int main()
{
	vector<bitset<N>> numbers;

	int result;
	string line;
	while (getline(cin, line))
	{
		numbers.emplace_back(line);
	}

	bitset<N> gamma_rate{part1(numbers, ones_more)};
	bitset<N> epsilon_rate{part1(numbers, zeros_more)};

	result = gamma_rate.to_ulong() * epsilon_rate.to_ulong();
	cout << result << endl;

	return 0;
}
