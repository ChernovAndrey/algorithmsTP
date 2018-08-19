/*3_1.​Дан отсортированный массив целых чисел A[0..n­1] и массив целых чисел B[0..m­1].Для каждого
элемента массива B[i] найдите минимальный индекс k минимального элемента массива A, равного или
превосходящего B[i]: A[k] >= B[i].Если такого элемента нет, выведите n.Время работы поиска k для каждого элемента B[i] log*/
#include <iostream>
using namespace std;
int binary_search(int key,int *A, int n)
{
	if (key <= A[0]) return 0;
	if (key > A[n - 1]) return n;
	int begin = 0;
	int end = n;
	int k = 1;

	while (key>A[k]){
		k *= 2;
		if (k >= n) k = n - 1;
	}
	begin = k/2;
	end =k;
		while (begin!=end){
			if (key <= A[(begin + end)/2]) end = (begin + end) / 2;
			else begin = (begin + end) / 2 +1;
		}
		return begin;
}
void init_arrays(int *A, int *B, int n, int m)
{
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
}
int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int *A = new int[n];
	int *B = new int[m];
	init_arrays(A, B, n, m);
	for (int i = 0; i < m; i++){
		cout << binary_search(B[i],A,n)<<" ";
	}
	delete[] A;
	delete[] B;
	cin.get();
	cin.get();
	return 0;
}