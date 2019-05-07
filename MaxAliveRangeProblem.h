#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EventYear
{
    public:
	char symbol;
	int year;
};

vector<EventYear> years;

bool compareEventYear(EventYear& eventYear1, EventYear& eventYear2) {
	return eventYear1.year < eventYear2.year;
}

int main()
{
	int arr[][2] =
	{
		{
			2000, 2010
		},
		{
			1975, 2005
		},
		{
			1975, 2003
		},
		{
			1803, 1809
		},
		{
			1750, 1869
		},
		{
			1840, 1935
		},
		{
			1803, 1921
		},
		{
			1894, 1921
		}
	};

	for (int i = 0; i < ((sizeof(arr) / 2) / sizeof(int)); i++) {
		for (int j = 0; j < 2; j++) {
			EventYear eventYear;
			eventYear.symbol = (j == 0) ? '(' : ')';
			eventYear.year = arr[i][j];
			years.push_back(eventYear);
		}
	}

	sort(years.begin(), years.end(), compareEventYear);

	int maxAlivePeople = 0;
	int currentAlivePeople = 0;
	int maxAlivePeopleYear = 0;

	for (int i = 0 ; i <  years.size(); i++)
	{
		currentAlivePeople += (years.at(i).symbol == '(') ? 1 : -1;
		if (maxAlivePeople <= currentAlivePeople)
		{
			maxAlivePeople = currentAlivePeople;
			maxAlivePeopleYear = years.at(i).year;
		}
	}

	cout << "In " << maxAlivePeopleYear << ", number of alive people was at maximum: " << maxAlivePeople << " People.\n";
}

