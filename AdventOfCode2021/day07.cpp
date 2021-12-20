#include "AdventOfCode2021.h"

using std::abs;
using std::accumulate;
using std::begin;
using std::cbegin;
using std::cend;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::function;
using std::getline;
using std::identity;
using std::iota;
using std::istringstream;
using std::min_element;
using std::minmax_element;
using std::plus;
using std::size_t;
using std::string;
using std::transform_reduce;
using std::vector;

function<int(int)> distance_to_fuel = identity{};

int main()
{
	vector<int> numbers;

	string line;
	getline(cin, line);
	istringstream stream{line};
	while (getline(stream, line, ','))
	{
		numbers.push_back(stoi(line));
	}

	vector<int> total_fuels;
	auto [min, max] = minmax_element(cbegin(numbers), cend(numbers));
	for (auto pos = *min; pos <= *max; pos++)
	{
		auto total_fuel = transform_reduce(cbegin(numbers), cend(numbers), 0, plus<>(), [pos](auto x)
		{
			auto distance = abs(x - pos);
			auto fuel = distance_to_fuel(distance);
			return fuel;
		});
		total_fuels.push_back(total_fuel);
	}

	cout << *min_element(cbegin(total_fuels), cend(total_fuels)) << endl;

	return 0;
}
