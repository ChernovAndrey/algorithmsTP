/*Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n. Требуется

найти k-ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k

(0..n-1) в отсортированном массиве. Напишите нерекурсивный алгоритм.*/
#include<iostream>
#include<cassert>
using namespace std;
template<typename T>
bool operator<(const T& first, const T& second)
{
	return (first<second);
}
template<typename T>
bool operator<=(const T& first, const T& second)
{
	return (first <= second);
}
template<typename T>
bool operator>(const T& first, const T& second)
{
	return (first>second);
}
template<typename T>
bool operator>=(const T& first, const T& second)
{
	return (first >= second);
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
template<class T>
long long Partition(T *arr, int index, long long begin, long long end)
{
	int i = begin;
	int j = begin;
	swap(arr[index], arr[end - 1]);
	for (; j < end - 1;){
		assert(j >= i);
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
template<typename T>
int find_k(T *arr, long long n, long long k)
{
	long long begin = 0;
	long long end = n;
	long long i = 0;
	while (true) {
		long long index_piv = -1;
		if ((arr[begin] >= min1(arr[end - 1], arr[(end + begin) / 2])) && (arr[begin] <= max1(arr[end - 1], arr[(end + begin) / 2]))) index_piv = begin;
		if ((arr[end - 1] >= min1(arr[begin], arr[(end + begin) / 2])) && (arr[end - 1] <= max1(arr[begin], arr[(end + begin) / 2]))) index_piv = end - 1;
		if ((arr[(end + begin) / 2] >= min1(arr[end - 1], arr[begin])) && (arr[(end + begin) / 2] <= max1(arr[end - 1], arr[begin]))) index_piv = (end + begin) / 2;
		assert(index_piv != -1);
		//	cout << index_piv <<" "<<begin<<" "<<" "<<end<<" "<<i <<k <<endl;
		i = Partition(arr, index_piv, begin, end);

		if (i == k) {
			return arr[i];
		}
		assert(i != k);
		if (k < i) {
			end = i;
		}
		if (k>i) {
			begin = i + 1;
		}
	}
}
int main()
{
	long long n = 0;
	long long k = 0;
	cin >> n >> k;
	long long *arr = new long long[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << find_k(arr, n, k);
	delete[] arr;
	//system("pause");
	return 0;
}