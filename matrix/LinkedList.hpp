#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.hpp"

template <typename T>
class LinkedList : public List<T>
{
private:
	template <typename T>
	class Node
	{
	public:
		Node* Next;
		T value;
		Node(T value = T(), Node* Next = nullptr) : value(value), Next(Next) {}
	};

	Node<T>* First;
	int Size;

public:
	T& operator[](const int pos)
	{
		Node<T>* Current = this->First;
		for (int i = 0; Current != nullptr; i++)
		{
			if (i == pos)
			{
				return Current->value;
			}
			Current = Current->Next;
		}
	}

	LinkedList() : Size(0), First(nullptr) {}

	~LinkedList()
	{
		while (First != nullptr)
		{
			Node<T>* temp = First;
			First = First->Next;
			delete temp;
		}
	}

	void push_back(T value) override
	{
		if (First == nullptr)
		{
			First = new Node<T>(value);
		}
		else
		{
			Node<T>* Current = First;
			while (Current->Next != nullptr)
			{
				Current = Current->Next;
			}
			Current->Next = new Node<T>(value);
		}
		Size++;
	}

	void insert(T value, int pos) override
	{
		if (pos == 0)
		{
			First = new Node<T>(value, First);
			Size++;
		}
		else if (pos >= 1)
		{
			Node<T>* Prev = this->First;

			for (int i = 0; i < pos - 1; i++)
			{
				Prev = Prev->Next;
			}

			Node<T>* newNode = new Node<T>(value, Prev->Next);
			Prev->Next = newNode;
			Size++;
		}
	}

	void erase(int pos) override
	{
		if (pos == 0)
		{
			Node<T>* temp = First;
			First = First->Next;
			delete temp;
			Size--;
		}
		else if (pos >= 1)
		{
			Node<T>* Prev = First;

			for (int i = 0; i < pos - 1; i++)
			{
				Prev = Prev->Next;
			}

			Node<T>* Del = Prev->Next;
			Prev->Next = Del->Next;
			delete Del;
			Size--;
		}
	}

	int size() override { return Size; }
};

#endif