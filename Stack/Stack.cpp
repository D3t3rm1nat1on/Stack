#include "pch.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int error_check(string str)
{
	int n = str.size();
	stack <char> st;
	stack <int> r_st;
	for (int i = 0; i < n; i++)
	{
		char temp = str[i];

		if (temp != '}' && temp != '(' && temp != ']' &&
			temp != '{' && temp != ')' && temp != '[')
			continue;

		if (temp == '}')
		{
			if (st.empty() || st.top() != '{')
				return i + 1;
			st.pop();
			r_st.pop();
			continue;
		}
		if (temp == ')')
		{
			if (st.empty() || st.top() != '(')
				return i + 1;
			st.pop();
			r_st.pop();
			continue;
		}
		if (temp == ']')
		{
			if (st.empty() || st.top() != '[')
				return i + 1;
			st.pop();
			r_st.pop();
			continue;
		}
		st.push(temp);
		r_st.push(i + 1);
	}
	if (st.empty())
		return 0;
	return r_st.top();
}

int main()
{
	string str;
	cin >> str;
	int res = error_check(str);
	if (res)
		cout << res;
	else
		cout << "Success";
}