//#pragma once

#ifndef _test_suite_
#define _test_suite_


#include <ctime>
#include "myMain.h"

template <class TypeOut, class TypeIn>
class TS
{
public:
	//delete constructor
	TS(TypeOut(*newFuncIn) (TypeIn)):
		newFunc(newFuncIn)
	{

	}

	void FuncToCompareAgainst(TypeOut(*originalFuncIn) (TypeIn))
	{
		originalFunc = originalFuncIn;
	}
/*
	static void PrintResult(float testResult, float answerIn);
	static void PrintResult(float testResult, float answerIn, float marginOfError);*/


	void CompareFunctions( BArray<TypeIn> testCases)
	{
		printf("-----------------RUNNING Problem 1 ------------------------------------\n");

		BArray<TypeOut> originalResults (testCases.Size());
		BArray<TypeOut> newResults (testCases.Size());

		double originalTime	= TimeFunction(originalResults, originalFunc,	testCases);
		double newTime		= TimeFunction(newResults,		newFunc,		testCases);

		double difference = (originalTime / newTime);

		printf("OriginalTime = %f\n", originalTime);
		printf("NewTime = %f\n", newTime); 
		if (difference < 1)
		{
			printf("slower = %f\n", difference);
		}
		else
		{
			printf("faster = %f\n", difference);
		}

	}

	double TimeFunction(BArray<TypeOut> &results, TypeOut(*funcToCompare) (TypeIn), BArray<TypeIn> testCases)
	{
		clock_t  c1 = clock();
		for (int ii = 0; ii < COUNT; ii += results.Size())
		{
			for (int i = 0; i < results.Size(); i++)
			{
				results.Set(i, funcToCompare(testCases[i]));
			}
		}
		clock_t c2 = clock();

		return c2 - c1;
	}

	

private:
	TypeOut(*newFunc) (TypeIn);
	TypeOut(*originalFunc) (TypeIn);
	static const int COUNT = 1000;
	static const char testFail[16];
	static const char testPass[16];
	static const char *answers[2];

	
};


#endif // !_test_suite_




