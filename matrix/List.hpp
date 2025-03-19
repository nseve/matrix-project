#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
public:
	virtual void push_back(T value) = 0;
	virtual void insert(T value, int pos) = 0;
	virtual void erase(int pos) = 0;
	virtual int size() = 0;
};

#endif