#include <iostream>
using namespace std;
int max_count_step(int n)
{
	int sum = 0;
	int result = 1;
	while (sum<n){
		sum += result;
		result++;
	}
	return --result;
}
void print_matr(int n,int max_count)
{
	for (int i = 0; i < max_count; i++){
		for (int j = 1; j <= n; j++){
			cout << j << " ";
		}
		cout << endl;
	}
}
int count_pyramid(int n, int max_count, int current)
{
	int result = 0;
	//if (?==max_count) return
	for (int i = current; i < n; i++){
		for (int j = i + 1; j < n;j++)
		count_pyramid(n,max_count,j);//?
	}
	return result;
}
int pyramid(int n)
{
	int result = 0;
	int max_count=max_count_step(n);
	print_matr(n, max_count);
	return count_pyramid(n,max_count,1);
}
int main()
{
	int n = 0;
	cin >> n;
	cout << pyramid(n);
	system("pause");
	return 0;
}