#include "Arr.h"
#include "error.h"

template <typename T> Arr<T>::Arr(int length) : m_length(length) 
{
	if (length <= 0) 
	{
		throw error_range();
	}
	else 
	{
		m_data = new int[length];
	}
}
template <typename T> Arr<T>::Arr(const Arr& a) 
{
	locate(a.getLength());

	for (int index = 0; index < m_length; ++index) 
	{
		m_data[index] = a.m_data[index];
	}
}

template <typename T> Arr<T>& Arr<T>::operator = (const Arr& a)
{
	if (&a == this) 
	{
		return *this;
	}

	locate(a.getLength());

	for (int index = 0; index < m_length; ++index) 
	{
		m_data[index] = a.m_data[index];
	}

	return *this;
}

template <typename T> void Arr<T>::erase() 
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

template <typename T> T& Arr<T>::operator[](int index) 
{
	if (index >= 0 && index < m_length) 
	{
		return m_data[index];
	}
}

template <typename T> T Arr<T>::getLength() const
{
	return m_length;
}

template <typename T> void Arr<T>::locate(int newLength) 
{
	erase();

	if (newLength <= 0) 
	{
		return;
	}

	m_data = new int[newLength];
	m_length = newLength;
}

template <typename T> void Arr<T>::resize(int newLength)
{
	if (newLength == m_length) 
	{
		return;
	}

	if (newLength <= 0) 
	{
		erase();
		return;
	}

	int* data = new int[newLength];

	if (m_length > 0) 
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;

		for (int index = 0; index < elementsToCopy; ++index) 
		{
			data[index] = m_data[index];
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}
}

template <typename T> void Arr<T>::insertBefore(int value, int index) {
	if (index <= 0 && index >= m_length) {
		throw error_length();
	};

	int* data = new int[m_length + 1];

	for (int before = 0; before < index; ++before) 
	{
		data[before] = m_data[before];
	}

	data[index] = value;

	for (int after = index; after < m_length; ++after) 
	{
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_length;
}

template <typename T> void Arr<T>::remove(int index)
{
	if (index <= 0 && index >= m_length) 
	{
		throw error_length();
	};

	if (m_length == 1) 
	{
		erase();
		return;
	}

	int* data = new int[m_length - 1];

	for (int before = 0; before < index; ++before) 
	{
		data[before] = m_data[before];
	}

	for (int after = index + 1; after < m_length; ++after) 
	{
		data[after - 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	--m_length;
}


template <typename T> void Arr<T>::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}