#include <iostream>
#include <stdexcept>
#include <stdlib.h>
//#include <stdio.h>
//#define DEBUG 10
//#include "debug.h"
#include <iomanip>

using namespace std;

template<class T>
class Matrix 
{
	T** mtx;
	int size;
	bool filled;
public:
	Matrix();
	Matrix(int);
	Matrix(const Matrix&);
	void set(T*, int);
	Matrix <T> operator + (const Matrix&);
	Matrix <T> operator - (const Matrix&);
	Matrix <T> operator * (const Matrix&);
	Matrix <T>& operator = (const Matrix&);
	~Matrix();	
	friend ostream& operator << (ostream& out, const Matrix& _mtx)
	{
		for (int i=0; i<_mtx.size; i++)
		{		
		  for (int j=0; j<_mtx.size; j++)
			out << setw(4) << _mtx.mtx[i][j] << " ";
		  out << endl;
		}
		return out;
	}
};

template<class T>
Matrix<T>::Matrix()
{
	size = 0;
	filled = false;
	try {
		int _size = 3;
		mtx = new T*[_size];
		for (int i=0; i<_size; i++)
			mtx[i] = new T[_size];
		size = _size;
	}
	catch(exception &e) {
		//PDEBUG(1, "exept. %s", e.what());
		cout << e.what() << endl;
	}		
}

template<class T>
Matrix<T>::Matrix(int k)
{
	size = 0;
	filled = false;
	try {
		if (k<1)
			throw k;
		int _size = k;
		mtx = new T*[_size];
		for (int i=0; i<_size; i++)
			mtx[i] = new T[_size];
		size = _size;
	}
	catch (int t) { 
		/*PDEBUG(1, "exept. negative size %d", k)*/ 
		cout << t << endl;
		throw;
	}
	catch (exception &e) { 
		/*PDEBUG(1, "exept. %s", e.what());*/ 
		cout << e.what() << endl;
		throw;
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix& matr)
{
	size = 0;
	int _size = matr.size;
	try {
		mtx = new T*[_size];
		for (int i=0; i<_size; i++)
			mtx[i] = new T[_size];
		size = _size;
		if (matr.filled)
		{
			for (int i=0; i<size; i++)
			  for (int j=0; j<size; j++)
				mtx[i][j] = matr.mtx[i][j];
			filled = true;
		}
	}
	catch (exception &e) { 
		/*PDEBUG(1, "exept. %s", e.what());*/ 
		cout << e.what() << endl;
		throw;
	}
}

template<class T>
void Matrix<T>::set(T* array, int _size)
{
	try {
		if (_size != size*size)
			throw "different sizes";
		for (int i=0; i<size; i++)
		  for (int j=0; j<size; j++)
			mtx[i][j] = array[j + i*size];
		filled = true;
	}
	catch (exception &e) {
		//PDEBUG(1, "exept. %s", e.what());
		cout << e.what() << endl;
		throw;
	}
	catch (const char* s) {
		//PDEBUG(1, "exept. %s", s);
		cout << s << endl;
		throw;
	}
}

template<class T>
Matrix <T> Matrix<T>::operator + (const Matrix& matr)
{
	try {
		if (!filled || !matr.filled)
			throw out_of_range("matrix not filled");
		if (size != matr.size)
			throw "different sizes";
		Matrix <T> newMatr(size);
		for (int i=0; i<size; i++)
		  for (int j=0; j<size; j++)
			newMatr.mtx[i][j] = mtx[i][j] + matr.mtx[i][j];
		newMatr.filled = true;
		return newMatr;
	}
	catch (exception &e) {
		//PDEBUG(1, "exept. %s", e.what());
		cout << e.what() << endl;
		throw;
	}
	catch (const char* s) {
		//PDEBUG(1, "exept. %s", s);
		cout << s << endl;
		throw;
	}
}

template<class T>
Matrix <T> Matrix<T>::operator - (const Matrix& matr)
{
	try {
		if (!filled || !matr.filled)
			throw out_of_range("matrix not filled");
		if (size != matr.size)
			throw "different sizes";
		Matrix <T> newMatr(size);
		for (int i=0; i<size; i++)
		  for (int j=0; j<size; j++)
			newMatr.mtx[i][j] = mtx[i][j] - matr.mtx[i][j];
		newMatr.filled = true;
		return newMatr;
	}
	catch (exception &e) {
		//PDEBUG(1, "exept. %s", e.what());
		cout << e.what() << endl;
		throw;
	}
	catch (const char* s) {
		//PDEBUG(1, "exept. %s", s);
		cout << s << endl;
		throw;
	}
}

template<class T>
Matrix <T> Matrix<T>::operator * (const Matrix& matr)
{
	try {
		if (!filled || !matr.filled)
			throw out_of_range("matrix not filled");
		if (size != matr.size)
			throw "different sizes";
		Matrix <T> newMatr(size);
		for (int i=0; i<size; i++)
		  for (int j=0; j<size; j++)
		  {
			newMatr.mtx[i][j] = 0;
			for (int l=0; l<size; l++)
				newMatr.mtx[i][j] += mtx[i][l] * matr.mtx[l][j];
		  }
		newMatr.filled = true;
		return newMatr;
	}
	catch (exception &e) {
		//PDEBUG(1, "exept. %s", e.what());
		cout << e.what() << endl;
		throw;
	}
	catch (const char* s) {
		//PDEBUG(1, "exept. %s", s);
		cout << s << endl;
		throw;
	}
}

template<class T>
Matrix <T>& Matrix<T>::operator = (const Matrix& matr)
{
	try {
		if (!matr.filled)
			throw out_of_range("matrix not filled");
		if (size != matr.size)
			throw "different sizes";
		for (int i=0; i<size; i++)
		  for (int j=0; j<size; j++)
			mtx[i][j] = matr.mtx[i][j];
		filled = true;
		return *this;
	}
	catch (exception &e) {
		//PDEBUG(1, "exept. %s", e.what());
		cout << e.what() << endl;
		throw;
	}
	catch (const char* s) {
		//PDEBUG(1, "exept. %s", s);
		cout << s << endl;
		throw;
	}
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i=0; i<size; i++)
	  delete mtx[i];
	delete []mtx;
}









