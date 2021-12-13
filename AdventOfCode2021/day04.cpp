#include "AdventOfCode2021.h"

using std::any_of;
using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::for_each;
using std::getline;
using std::istream_iterator;
using std::istringstream;
using std::make_tuple;
using std::optional;
using std::plus;
using std::reduce;
using std::remove_if;
using std::size_t;
using std::stoi;
using std::string;
using std::transform_reduce;
using std::tuple;
using std::unordered_set;
using std::vector;

constexpr size_t N = 5;
using value_t = int;

struct board_t
{
	using line_t = unordered_set<value_t>;
	using container_t = vector<line_t>;

	container_t rows;
	container_t cols;

	void mark(value_t value)
	{
		auto remove_value = [value](line_t& line) { line.erase(value); };
		for_each(rows.begin(), rows.end(), remove_value);
		for_each(cols.begin(), cols.end(), remove_value);
	}

	bool is_bingo() const
	{
		auto is_empty = [](const line_t& line) { return line.empty(); };
		return any_of(rows.cbegin(), rows.cend(), is_empty)
			|| any_of(cols.cbegin(), cols.cend(), is_empty);
	}

	value_t sum() const
	{
		auto sum_line = [](const line_t& line) { return reduce(line.cbegin(), line.cend()); };
		return transform_reduce(rows.cbegin(), rows.cend(), 0, plus<>(), sum_line);
	}
};

vector<value_t> read_numbers()
{
	vector<value_t> numbers;
	string line;
	getline(cin, line);
	istringstream stream{line};
	string next;

	while (getline(stream, next, ','))
	{
		numbers.push_back(stoi(next));
	}

	return numbers;
}

vector<board_t> read_boards()
{
	vector<board_t> boards;

	while (true)
	{
		string line;
		getline(cin, line); // empty line
		if (cin.eof())
		{
			break;
		}

		board_t::container_t rows;
		board_t::container_t cols;
		rows.resize(N);
		cols.resize(N);

		for (size_t j = 0; j < N; j++)
		{
			auto& row = rows[j];
			getline(cin, line);
			istringstream stream{line};
			for (size_t i = 0; i < N; i++)
			{
				auto& col = cols[i];

				value_t number;
				stream >> number;

				row.insert(number);
				col.insert(number);
			}
		}

		boards.emplace_back(rows, cols);
	}
	return boards;
}

optional<tuple<board_t, value_t>> part1(const vector<value_t>& numbers, vector<board_t> boards)
{
	for (value_t number : numbers)
	{
		for (board_t& board : boards)
		{
			board.mark(number);

			if (board.is_bingo())
			{
				return make_tuple(board, number);
			}
		}
	}
	return std::nullopt;
}

optional<tuple<board_t, value_t>> part2(const vector<value_t>& numbers, vector<board_t> boards)
{
	optional<tuple<board_t, value_t>> result = std::nullopt;
	for (value_t number : numbers)
	{
		for (board_t& board : boards)
		{
			board.mark(number);
		}

		auto is_bingo = [](const board_t& board) { return board.is_bingo(); };
		if (auto it = find_if(boards.rbegin(), boards.rend(), is_bingo); it != boards.rend())
		{
			result = make_tuple(*it, number);
			boards.erase(remove_if(boards.begin(), boards.end(), is_bingo), boards.end());
		}
	}
	return result;
}

void write_result(const optional<tuple<board_t, value_t>>& result)
{
	if (result.has_value())
	{
		auto&& [board, number] = result.value();
		cout << board.sum() * number << endl;
	}
}

int main()
{
	vector<value_t> numbers = read_numbers();
	vector<board_t> boards = read_boards();

	auto result1 = part1(numbers, boards);
	write_result(result1);

	auto result2 = part2(numbers, boards);
	write_result(result2);

	return 0;
}
