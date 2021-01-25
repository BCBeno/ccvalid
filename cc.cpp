#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <regex>

using namespace std;


int main() {
	int n;
	cin >> n;
	string card;
	regex in2("[4-6][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]");
	regex in("[4-6][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]");
	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		cin >> card;
		for (int j = 0; j < card.length()-1; j++)
		{
			if (card[j + 1] == '-')
			{
				if (card[j] == card[j + 2])
					k++;
				j+=2;
			}
			if (card[j] == card[j + 1])
				k++;
			else
				k = 0;
			if (k >=3)
			{
				cout << "invalid\n";
				break;
			}
		}
		if (k >=3)
			continue;
		if(regex_match(card,in) || regex_match(card, in2))
			cout<<"valid\n";
		else
			cout<<"invalid\n";
	}
}