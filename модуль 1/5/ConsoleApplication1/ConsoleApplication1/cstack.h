#pragma once
class cstack
{
private:
	int current_size = 0;
	char *arr;
	int size=0;
	int end=0;//������ ���������� ����� ���������� ��������
public:
	char pop();
	void push(char symbol);
	void bufferup();
	char show();
	cstack(int n);
	~cstack();
};

