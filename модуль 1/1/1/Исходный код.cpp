/*насколько нулей  закачивается n!, где n от нуля до тысячи*/
#include<iostream>
#include<cassert>
using namespace std;
int zero_count(int n)
{
	int count = 0;
	assert(n > 0 && n <= 1000);
	for (int i = 1; i < n+1; i++){
		int number = i;
		while (number % 5 == 0) { //считаем сколько раз число делится на 5
			count++;
			number = number / 5;
		}
	}
	return count;
}
int main()
{
	int n = 0;
	cin >> n;
	cout << zero_count(n);
	cin.get();
	cin.get();
	return 0;
}