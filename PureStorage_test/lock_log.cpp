#include <iostream>
#include <string>
#include <string.h>
#include <unordered_set>
#include <stack>
#include <list>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;

int check_log_history(list<string> locks)
{
	unordered_set<string> set;
	stack<string> stack;
	char* copy = (char*)malloc(20);

	for(list<string>::iterator itr = locks.begin(); itr != locks.end(); itr++)
	{
		strcpy(copy, (*itr).c_str());
		vector<string> result;
		boost::split(result, copy, boost::is_any_of(" "));
		strcpy(copy, result[0].c_str());

		if(!strcmp(copy, "ACQUIRE"))
		{
			unordered_set<string>::iterator got = set.find(result[1]);
			if(got == set.end())
			{
				set.insert(result[1]);
				stack.push(result[1]);
			}
			else 
			{
				return -2;
			}
		}
		else
		{
			unordered_set<string>::iterator got = set.find(result[1]);
			if(got != set.end())
			{
				if(result[1] != stack.top())
				{
					return -1;
				}
				else
				{
					stack.pop();
					set.erase(result[1]);
				}
			}
			else 
			{
				return -3;
			}
		}
	}

	if(!set.empty())
	{
		return -4;
	}

	return 0;
}

int main() 
{
	list<string> locks;
	locks.push_back("ACQUIRE 123");
	locks.push_back("ACQUIRE 456");
	locks.push_back("ACQUIRE 789");
	locks.push_back("RELEASE 789");
	locks.push_back("RELEASE 456");
	locks.push_back("RELEASE 123");

	int retVal = check_log_history(locks);
	cout << "Function returned " << retVal << endl;
	return 0;
}
