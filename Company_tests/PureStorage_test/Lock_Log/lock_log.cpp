#include <iostream>
#include <string>
#include <string.h>
#include <unordered_set>
#include <stack>
#include <list>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;

enum lock_error {SUCCESS, WRONG_RELEASE, DOUBLE_ACQUIRE, NO_ACQUIRED_LOCK, DANGLING_LOCK};

int check_log_history(vector<string> locks)
{
	lock_error error = SUCCESS;
	unordered_set<string> set;
	stack<string> stack;
	char* copy = (char*)malloc(20);
	int order=0;

	for(vector<string>::iterator itr = locks.begin(); itr != locks.end(); itr++)
	{
		order++;
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
				error = DOUBLE_ACQUIRE;
				return error;
//				return order;
			}
		}
		else
		{
			unordered_set<string>::iterator got = set.find(result[1]);
			if(got != set.end())
			{
				if(result[1] != stack.top())
				{
					error = WRONG_RELEASE;
					return error;
//					return order;
				}
				else
				{
					stack.pop();
					set.erase(result[1]);
				}
			}
			else 
			{
				error = NO_ACQUIRED_LOCK;
				return error;
//				return order;
			}
		}
	}

	if(!set.empty())
	{
		error = DANGLING_LOCK;
		return error;
//		return locks.size();
	}

	return error;
}

int main() 
{
	vector<string> locks;
	locks.push_back("ACQUIRE 123");
	locks.push_back("ACQUIRE 456");
	locks.push_back("ACQUIRE 789");
	locks.push_back("RELEASE 789");
	locks.push_back("RELEASE 456");
	locks.push_back("RELEASE 123");

	int retVal = check_log_history(locks);
	cout << "Lock log status: " << retVal << endl;
//	cout << "Error in sequence at step " << retVal << endl;
	return 0;
}
