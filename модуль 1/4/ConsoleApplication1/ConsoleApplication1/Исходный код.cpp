//​Реализовать очередь с динамическим зацикленным буфером.
//pop-вытащить из начала; push-добавить в конец
#include<iostream>
#include "cqueue.h"
using namespace std;
int main()
{
	int n=0;
	int a = 0;
	int b = 0;
	bool flag =true;
	cin >> n;
	cqueue queue(4);//buffersize=n+1  потому что мы жертвуем одним элементом для определенности
	for (int i = 0; i < n; i++)	{
		cin >> a>>b;
		if (a == 2){
			if (b != queue.pop()) flag = false;
		}
		if (a == 3){
			queue.push(b);
		}
	}
	if (flag == true) cout << "YES";
	else cout << "NO";
	cin.get();
	cin.get();
	return 0;
}