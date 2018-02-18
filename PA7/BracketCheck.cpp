#include "BracketCheck.h"


BracketCheck::BracketCheck(std::string expression)
{
	doThing(expression);
}

bool BracketCheck::doThing(std::string expression)
{

	enum BT { curly, smooth, square };

	std::deque<BT> BStack;

	for (int i = 0; expression[i]; i++)
	{
		if (expression[i] == '{')
		{
			BStack.push_back(BT::curly);
		}
		else if (expression[i] == '(')
		{
			BStack.push_back(BT::smooth);
		}
		else if (expression[i] == '[')
		{
			BStack.push_back(BT::square);
		}
		else if (expression[i] == '}')
		{
			if (BStack.size() <= 0)
			{
				return false;
			}
			if (BStack.back() != BT::curly)
			{
				return false;
			}
			BStack.pop_back();
		}
		else if (expression[i] == ')')
		{
			if (BStack.size() <= 0)
			{
				return false;
			}
			if (BStack.back() != BT::smooth)
			{
				return false;
			}
			BStack.pop_back();
		}
		else if (expression[i] == ']')
		{
			if (BStack.size() <= 0)
			{
				return false;
			}
			if (BStack.back() != BT::square)
			{
				return false;
			}
			BStack.pop_back();
		}
	}
	if (BStack.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}


