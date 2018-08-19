#include<iostream>
#include "cstack.h"
#include<cassert>
using namespace std;
void cstack::bufferup()/*исправленная функция*/
{
	char *new_arr = new char[2 * size];
	for (int i = 0; i < size; i++){
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
}
cstack::cstack(int n) :size(n), end(0), current_size(0)
{
	arr = new char[n];
}
void cstack::push(char symbol)
{
	if (current_size == size - 1){
		bufferup();
		size = 2 * size;
	}
	assert(end < size);
	arr[end++] = symbol;
	current_size++;
}
char cstack::pop()
{
	
	assert(end>0);
	return arr[--end];
}
char cstack::show()
{
	assert(end > 0);
	return arr[end-1];
}
cstack::~cstack()
{
	delete[] arr;
}
