#include "AdventOfCode2021.h"

using std::accumulate;
using std::adjacent_difference;
using std::back_inserter;
using std::cbegin;
using std::cend;
using std::cin;
using std::copy;
using std::count_if;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::transform;
using std::vector;

int main()
{
	vector<int> depths;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(depths));

	const int window_size = 3;
	vector<int> sums;
	for (auto it = cbegin(depths); it != cend(depths) - window_size + 1; ++it)
	{
		int sum = accumulate(it, it + window_size, 0);
		sums.push_back(sum);
	}

	vector<int> differences;
	adjacent_difference(cbegin(sums), cend(sums), back_inserter(differences));

	auto count = count_if(cbegin(differences) + 1, cend(differences), [](int difference) { return difference > 0; });
	cout << count << endl;

	return 0;
}
