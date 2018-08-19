#pragma once
class cqueue
{
private:
	int current_size = 0;
	int *buffer;
	int buffersize=0;
	int begin = 0;
	int end = 0;//после последнего
	void bufferup();
public:
	cqueue(int n);
	void push(int b);
	int pop();
	~cqueue();
};

