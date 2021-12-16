#include "AdventOfCode2021.h"

using std::abs;
using std::cin;
using std::cout;
using std::endl;
using std::equal_to;
using std::getline;
using std::hash;
using std::max;
using std::min;
using std::size_t;
using std::sscanf;
using std::string;
using std::unordered_set;

struct point
{
	int x, y;	
};

template <>
struct hash<point>
{
	size_t operator()(const point& p) const
	{
		return hash<decltype(p.x)>{}(p.x) ^ (hash<decltype(p.y)>{}(p.y) << 1);
	}
};

template <>
struct equal_to<point>
{
	constexpr bool operator()(const point& lhs, const point& rhs) const
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
};

int cmp(int l, int r) {
	return l < r ? 1 : (l > r ? -1 : 0);
}

int main()
{
	unordered_set<point> single;
	unordered_set<point> duplicate;

	string line;
	while (getline(cin, line))
	{
		int x1{}, y1{}, x2{}, y2{};
		static_cast<void>(sscanf(line.c_str(), "%i,%i -> %i,%i", &x1, &y1, &x2, &y2));

		bool is_vertical = x1 == x2;
		bool is_horizontal = y1 == y2;
		bool is_diagonal = abs(x1 - x2) == abs(y1 - y2);
		if (is_vertical || is_horizontal || is_diagonal)
		{
			auto dx = cmp(x1, x2);
			auto dy = cmp(y1, y2);
			for (auto x{x1}, y{y1}; x != x2 + dx || y != y2 + dy; x += dx, y += dy)
			{
				const point p{x, y};
				if (single.contains(p))
				{
					duplicate.insert(p);
				}
				else
				{
					single.insert(p);
				}
			}
		}
	}

	cout << duplicate.size() << endl;

	return 0;
}
