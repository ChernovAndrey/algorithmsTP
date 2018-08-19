//2_3.​Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.Найти количество
//таких пар индексов(i, j), что A[i] + B[j] = k.Время работы O(n + m).
#include <iostream>
using namespace std;
void init_arr(int *A,int n)
{
	for (int i = 0; i < n; i++) cin >> A[i];

}
int count_group(int*A, int*B, int n, int m, int k)
{
	int count = 0;
	for (int i = 0, j = m - 1; (i < n) || (j > 0);){
		if (k == A[i] + B[j]){
			count++;
			i++;
			j--;
			continue;
		}
		if (k > A[i] + B[j]){
			i++;
		}
		else{
			j--;
		}
	}
	return count;
}
int main()
{
	int n = 0;
	int m = 0;
	int k = 0;
	cin >> n;
	int *A = new int[n];
	init_arr(A,n);
	cin >> m;
	int *B = new int[m];
	init_arr(B, m);
	cin>> k;
	cout << count_group(A,B,n,m,k);
	delete[] A;
	delete[] B;
	cin.get();
	cin.get();
	return 0;
}