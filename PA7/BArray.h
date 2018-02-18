#pragma once
#include <stdarg.h>

template<class T>
class BArray
{
public:
	BArray() : size(0), arrayPtr(0) {};


	BArray(int itemCount) :
		size(itemCount)
	{
		arrayPtr = new T[itemCount];
	}
	BArray(T t1): 
		arrayPtr(new T(t1)),
		size (1)
	{

	}

	BArray(int itemCount, T t1, ...):
		size(itemCount)
	{
		va_list list;

		va_start(list, itemCount);

		arrayPtr = (T*) malloc((size_t) (itemCount * t1));
		memcpy(arrayPtr, list, (size_t) (itemCount * t1));

	}

	void Set(int location, T newValue)
	{
		*(arrayPtr + location) = newValue;
	}

	T operator[] (int location)
	{
		return *(arrayPtr + location);
	}

	int Size()
	{
		return size;
	}

private:
	int size;
	T *arrayPtr;
};

