#include "myMain.h"



float a0 = 0;
float a1 = 1;
float a2 = 2;
float a3 = 3;
float a4 = a0;
float a5 = a1;

//std::string PS7 = "";
//std::string PS2 = " ";
//std::string PS3 = "acb";
//std::string PS4 = "a b c";
//std::string PS5 = "a aaa bb ";
//std::string PS6 = "The quick brown fox jumps over the lazy dog";


void Time1();
float newFunc(float intIn);
float originalFunc(float intIn);

int main()
{
	printf("Starting Main...\n");

	//do tests here
	Time1();

	//wait to view results
	printf("Main Finished\n");
	char readIn[256];
	scanf_s(readIn, 256);

}

void Time1()
{
	TS<float, float> tester(newFunc);
	tester.FuncToCompareAgainst(originalFunc);
	BArray <float> testCases(5, 10.0f, 0.0f, 5.15f, 3.0f, 2.0f);

	tester.CompareFunctions(testCases);

}

float newFunc(float intIn)
{
	float returnValue = std::sqrt( intIn);
	for (int i = 0; i < 1000; i++)
	{
		returnValue = std::sqrt(returnValue);
	}
	return returnValue;
}

float originalFunc(float intIn)
{
	float returnValue = std::sqrt(intIn);
	for (int i = 0; i < 10000; i++)
	{
		returnValue = std::sqrt(returnValue);
	}
	return returnValue;
}



