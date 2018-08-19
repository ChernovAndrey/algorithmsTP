#include "cqueue.h"
#include<cmath>
void cqueue::bufferup()/*������������ �������*/
{
	//�������� ��� �������� ������� � ������� ������� ������
	int*new_buffer = new int[2 * buffersize];
	int j = 0;//������� �� ������ �������
	int i = begin;//������� �� �������
	for (; i != end; i++,j++){
		if (i == buffersize - 1){//��������� �������� �� ���������� ������� � �������
			i = -1;
			new_buffer[j] = buffer[buffersize - 1];
		}
		else new_buffer[j] = buffer[i];
	}
	begin = 0;
	end = j;
	delete[]buffer;
	buffer = new_buffer;
}
cqueue::cqueue(int n) : buffersize(n), end(0), begin(0), current_size(0)
{
	buffer = new int[n];
}
void cqueue::push(int b)//��������
{
	if (current_size == buffersize-1) {
		bufferup();
		buffersize = 2 * buffersize;
		}
	if (end == (buffersize - 1)){
		end = 0;
		buffer[buffersize - 1] = b;
	}
	else buffer[end++] = b;
	current_size++;
}
int cqueue::pop()//�������
{
	if (begin == end) return -1;
	if (begin == buffersize - 1){
		begin = 0;
		return buffer[buffersize - 1];
	}
	current_size--;
	return buffer[begin++];
}
cqueue::~cqueue()
{
	delete[] buffer;
}
