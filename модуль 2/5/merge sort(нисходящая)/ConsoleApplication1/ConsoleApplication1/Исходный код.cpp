#include<iostream>
#include<vector>
using namespace std;
template<class T>
void merge(T*arr,int begin,int middle,int end)
{
	T* help_arr = new T[end-begin];
	int i = 0;
	int j = 0;
	for (; (begin+i < middle) && (middle+j < end);){
		if (arr[begin+i] < arr[j+middle]){
			help_arr[i + j] = arr[begin+i];
			i++;
		}
		else{
			help_arr[i + j] = arr[j+middle];
			j++;
		}
	}
	for (; i+begin < middle; i++) help_arr[i + j] = arr[i+begin];
	for (; j+middle < end; j++) help_arr[i + j] = arr[j+middle];
	for (int i = 0; i < end-begin; i++) arr[begin+i] = help_arr[i];
}
template<class T>
void merge_sort(T *arr,int begin,int end)
{
	if (end - begin < 2) return;
	int middle = (begin + end) / 2;
	merge_sort(arr,begin,middle);
	merge_sort(arr,middle,end);
	merge(arr,begin,middle,end);
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	merge_sort(arr.data(),0,n);
	for (int i = 0; i < n; i++){
		cout << arr[i]<<" ";
	}
	system("pause");
	return 0;
}