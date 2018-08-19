#include<iostream>
#include <algorithm>
#include <stack>
using namespace std;
void insert_sort(int* arr, int begin, int end)
{
	//int size = end-begin;
	for (int i = begin; i < end; i++) {
		int current = arr[i];
		int j = 0;
		for (j = i - 1; ((j >= 0) && (arr[j]>current)); j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = current;
	}
}
int max1(long long a, long long b)
{
	if (a > b) return a;
	return b;
}
int min1(long long a, long long b)
{
	if (a < b) return a;
	return b;
}
int Partition(int *arr,int begin, int end)
{
	int index = 0;
	if ((arr[begin] >= min1(arr[end - 1], arr[(end + begin) / 2])) && (arr[begin] <= max1(arr[end - 1], arr[(end + begin) / 2]))) index = begin;
	if ((arr[end - 1] >= min1(arr[begin], arr[(end + begin) / 2])) && (arr[end - 1] <= max1(arr[begin], arr[(end + begin) / 2]))) index  = end - 1;
	if ((arr[(end + begin) / 2] >= min1(arr[end - 1], arr[begin])) && (arr[(end + begin) / 2] <= max1(arr[end - 1], arr[begin]))) index = (end + begin) / 2;
	int i = begin;
	int j = begin;
	swap(arr[index], arr[end - 1]);
	for (; j < end - 1;){
		if (arr[j]>arr[end - 1]){
			j++;
		}
		else{
			swap(arr[i], arr[j]);
			j++;
			i++;
		}
	}
	swap(arr[i], arr[end - 1]);
	return i;
}
void quick_sort(int *arr,int begin,int end)
{
	stack<int> s_begin;
	stack<int> s_end;
	s_begin.push(begin);
	s_end.push(end);
	while (!s_begin.empty()){
		begin = s_begin.top();
		s_begin.pop();
		end = s_end.top();
		s_end.pop();
		if (begin >= end) continue;
		if (end - begin <= 100) insert_sort(arr, begin, end);
		int q = Partition(arr, begin, end);
		if (q> end - q){ //сначала большую часть
			s_begin.push(begin);
			s_end.push(q);
			s_begin.push(q+1);
			s_end.push(end);
		}
		else{
			s_begin.push(q+1);
			s_end.push(end);
			s_begin.push(begin);
			s_end.push(q);
		}
	}
}
void sort(int *begin,int *end)
{
	int size = end - begin;
	quick_sort(begin, 0, size);
}
int main()
{
	int *arr = new int[5];
	for (int i = 0; i < 5; i++){
		cin >> arr[i];
	}
	sort(arr,arr+5);
	for (int i = 0; i < 5; i++){
		cout << arr[i];
	}
	system("pause");
	return 0;
}