/*Дан массив натуральных чисел A[0..n), n не превосходит 10^8. Так же задан размер некотрого окна

(последовательно расположенных элементов массива) в этом массиве k, k <= n.Требуется для

каждого положения окна(от 0 и до n - k) вывести значение максимума в окне.*/
#include<iostream>
#include<vector>
using namespace std;
template <class T>
class heap
{   
	vector<long long> index;
	vector<T> arr;
	void heap_make(long long n);

public:
	void heap_insert(long long n, T x,long long i_index);
	T heap_pop(long long n);
	heap();
	~heap();
};
template<class T>
heap<T>::heap()
{

}
template<class T>
heap<T>::~heap()
{
}
template <class T>
T heap<T>::heap_pop(long long n) {
	swap(arr[n-1], arr[0]);
	swap(index[n - 1], index[0]);
	for (long long i = 0; i<=n/2+1;) {
		if (2 * i + 1 >= n) break;
		long long k = 2 * i + 1;
		if (k + 2 < n && arr[k] < arr[k + 1]) {
			k++;
		}
		if (arr[i] < arr[k]) {
			swap(arr[i], arr[k]);
			swap(index[i], index[k]);
			i = k;
		}
		else break;
	}
	return arr[n-1];
}
template <class T>
void heap<T>::heap_insert(long long n, T x,long long i_index)
{
	if (arr.size() > n) {
		arr[n] = x;
		index[n] = i_index;
	}
	else {
		arr.push_back(x);
		index.push_back(i_index);
	}
	for (int i = n; i > 0;) {
		if (arr[i] > arr[(i-1) / 2]) {
			swap(arr[i], arr[(i-1)/ 2]);
			swap(index[i],index[(i-1)/2]);
			i = (i-1) / 2;
		}
		else {
			break;
		}
	}
}
template<class T>
void  heap<T>::heap_make(long long n) {
	for (long long i = n / 2 + 1; i >= 0; --i) {
		for (long long j = i; j <= n / 2 + 1;) {
			if (2 * j + 1 >= n) break;
			int k = 2*j+1;
			if ((k + 1 < n)&&(arr[k] < arr[k + 1])) {
				k++;
			}
			if (arr[j] < arr[k]) {
				swap(arr[k], arr[j]);
				swap(index[k], index[j]);
				j = k;
	
			}
			else {
				break;
			}
		}
	}
}
template<class T>
void max_window(T* arr,T n,T k)
{
	heap<T> window;
	for (long long i = 0; i < k; i++){
		window.arr.push_back(arr[i]);
		window.index.push_back(i);
	}
	window.heap_make(k);
	bool flag = false;
	long long size = k;
	arr[0] = window.arr[0];
	for (long long i = k; i < n; i++){
		window.heap_insert(size++, arr[i],i);
		while (i - k+1>window.index[0]){
			window.heap_pop(size--);
		}
		arr[i - k+1] = window.arr[0];
	}
}
int main()
{
	long long n=0;
	cin >> n;
	heap<long long> h;
	for (long long i = 0; i < n; i++){
		long long a = 0;
		cin >> a;
		h.arr.push_back(a);
	}
	long long k = 0;
	cin >> k;
	max_window(h.arr.data(),n,k);
	for (long long i = 0; i <= n - k; i++){
		cout << h.arr[i] << " ";
	}
	system("pause");
	return 0;
}