#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int father = -1;
	vector <int> son;
};

int height(vector <Point> &p, int start_point)
{
	if (start_point == -1)
		return 0;
	int result = 1;
	int n = p[start_point].son.size();
	for (int i = 0; i < n; i++)
	{
		int n_result = 1 + height(p, p[start_point].son[i]);
		if (n_result > result)
			result = n_result;
	}
	return result;
}

int main()
{
	int start_point = -1;
	int n;
	cin >> n;
	vector <Point> p(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		p[i].father = temp;
		if (temp != -1)
			p[temp].son.push_back(i);
		else
			start_point = i;
	}

	cout << height(p, start_point);
}