#ifndef MYVECTOR_H_
#define MYVECTOR_H_
#include<iostream>

template <typename T>
class MyVector {

	public:
		// Costruttore di default
		MyVector(size_t s = 0);

		// Costruttore con initializer list
		MyVector(std::initializer_list<T> lst);

		// Costruttore di copia
		MyVector(const MyVector& other);

		// Costruttore di spostamento
		MyVector(MyVector&& other) noexcept;

		~MyVector();

		size_t getSize() const;

		T& operator[] (const size_t index);
		T& operator[] (const size_t index) const;
		MyVector& operator=(MyVector&&);

		void push_back(const T value);
		void pop_back();
		T at(const size_t index) const;

	private :
		size_t size;
		size_t capacity;
		T *data;

		static const size_t INITIAL_CAPACITY = 100;

		void reserve(size_t new_capacity);

	};

#include"MyVector.hpp"

#endif /* MYVECTOR_H_ */
