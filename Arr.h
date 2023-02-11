#pragma once
#include <exception>

template <typename T> class Arr 
{
private:
	T m_length = 0;
	T* m_data = 0;

public:
	Arr() = default;
	Arr(int length);
	Arr(const Arr& a);

	~Arr() 
	{
		delete[] m_data;
	}

	Arr& operator = (const Arr& a);

	void erase();

	T& operator[](int index);

	T getLength() const;

	void locate(int newLength);

	void resize(int newLength);

	void insertBefore(int value, int index);

	void remove(int index);

	void insertAtEnd(int value);
};