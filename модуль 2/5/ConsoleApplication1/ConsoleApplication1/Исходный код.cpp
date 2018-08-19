/*Дана очень длинная последовательность целых чисел длины n. Требуется вывести в

отсортированном виде её первые k элементов. Последовательность может не помещаться в память.

Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.*/
#include<iostream>
#include<vector>
using namespace std;
bool Compare(const long long& first, const long long& second)
{
	return first < second;
}
template<class T>
void merge(T*arr, long long begin, long long middle, long long end, bool(*Compare)(const T&, const T&))
{
	T* help_arr = new T[end - begin];
	long long i = 0;
	long long j = 0;
	for (; (begin + i < middle) && (middle + j < end);){
		if (Compare(arr[begin + i],arr[j + middle])){
			help_arr[i + j] = arr[begin + i];
			i++;
		}
		else{
			help_arr[i + j] = arr[j + middle];
			j++;
		}
	}
	for (; i + begin < middle; i++) help_arr[i + j] = arr[i + begin];
	for (; j + middle < end; j++) help_arr[i + j] = arr[j + middle];
	for (long long i = 0; i < end - begin; i++) arr[begin + i] = help_arr[i];
}
template<class T>
void merge_sort(T *arr, long long begin, long long end, bool(*Compare)(const T&, const T&))
{
	if (end - begin < 2) return;
	long long middle = (begin + end) / 2;
	merge_sort(arr, begin, middle,Compare);
	merge_sort(arr, middle, end,Compare);
	merge(arr, begin, middle, end,Compare);
}
template <class T>
void merge_arr(T*arr1,T*arr2,long long k,long long k_cur)//первые k элементов из двух массивов попадают в первый
{
	T* help_arr = new T[k];
	long long i = 0, j = 0;
	for (; (((i + j) < k) && (j < k_cur));){
		if (arr1[i] < arr2[j]){
			help_arr[i + j] = arr1[i];
			i++;
		}
		else{
			help_arr[i + j] = arr2[j];
			j++;
		}
	}
		for (; (i + j) < k;i++) help_arr[i + j] = arr1[i];
		for (long long i = 0; i < k; i++) arr1[i] = help_arr[i];
		delete[] help_arr;
}
int main()
{
	long long n=0;
	long long k = 0;
	cin >> n >> k;
	vector<long long> res_arr(k), cur_arr(k);
	bool flag = false;
	while (n)
	{
		int i = 0;
		for (; (i<k) && (n>0); i++){
			cin >> cur_arr[i];
			n--;
		}
		
		int k_cur = k;
		if (i < k) k_cur = i;
		merge_sort(cur_arr.data(), 0, k_cur,Compare); 
		if (flag == false){
			for (int i = 0; i < k; i++) res_arr[i] = cur_arr[i];
			flag = true;
		}
		else{
			merge_arr(res_arr.data(), cur_arr.data(), k, k_cur);
		}
	}
	for (int i = 0; i < k; i++) cout << res_arr[i] << " ";
	system("pause");
	return 0;
}