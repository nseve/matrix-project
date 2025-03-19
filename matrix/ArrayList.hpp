#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.hpp"

template <typename T>
class ArrayList : public List<T>
{
private:
	T* array;
	int Size;
	int Capacity = 0;

public:
	T& operator[](const int pos)
	{
		for (int i = 0; i < Size; i++)
		{
			if (i == pos)
			{
				return array[i];
			}
		}
	}

	ArrayList() : array(new T[1]), Size(0) {}
	~ArrayList()
	{
		delete[] array;
	}

	void push_back(T value) override
	{
		if (Size >= Capacity)
		{
			T* newArray = new T[Size + 10];
			for (int i = 0; i < Size; i++)
			{
				newArray[i] = array[i];
			}
			newArray[Size] = value;
			Size++;
			delete[] array;
			array = newArray;
			Capacity += 10;
		}
		else
		{
			array[Size] = value;
			Size++;
		}
	}

	void insert(T value, int pos) override
	{
		if (Size >= Capacity)
		{
			T* newArray = new T[Size + 10];
			int j = 0;
			for (int i = 0; i <= Size; i++)
			{
				if (i == pos)
				{
					newArray[i] = value;
				}
				else
				{
					newArray[i] = array[j];
					j++;
				}
			}
			Size++;
			delete[] array;
			array = newArray;
			Capacity += 10;
		}
		else
		{
			for (int i = Size; i > pos; i--)
			{
				array[i] = array[i - 1];
			}
			array[pos] = value;
			Size++;
		}
	}

	void erase(int pos) override
	{
		if (pos < Size)
		{
			for (int i = pos; i < Size - 1; i++)
			{
				array[i] = array[i + 1];
			}
			Size--;
		}
	}
	
	bool empty() { return Size == 0; }
	int size() override { return Size; }
};

#endif