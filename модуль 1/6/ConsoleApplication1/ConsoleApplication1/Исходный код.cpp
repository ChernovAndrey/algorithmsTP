//сколькоими способами можно составить пирамиду, в которой любой верхний уровень меньше предыдущего, используя ровно n кубиков
//закомментированный код нужен для удобства понимания
#include<iostream>
using namespace std;
int main()
{
	long long n = 0;
	cin >> n;
	if ((n == 1) || (n == 2)){
		cout << 1;
		return 0;
	}
	long long max_count = 0;
	long long sum = 0;
	for (max_count = 0;;){
		sum += max_count+1;
		if (sum<= n) max_count++;
		else break;
		}
	cout << sum << endl;
	cout << max_count << endl;
	int **arr = new int*[max_count];
	for (int i = 0; i < max_count; i++){
		arr[i] = new int[n];
		for (int j = 0; j < n; j++){
			arr[i][j] = j+1;
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	long long result = max_count-1;//не вошедшие в основную обработку
	sum = 0;
	for (int k = 0; k < max_count - 2; k++){//укорачиваем пирамиду
		sum = 0;
		for (int i = 0; i < max_count-k; i++){
			sum += i + 1;
		}
		cout << sum << endl;
		//cout << "sum=" << sum << endl;
		//двухступенчатые пирамиды в следующем фрагменте кода не обрабатываются
		for (int i = max_count - 2-k; i >= 0; i--){ //для последней строки только один способ
			long long local_sum = sum + max_count - i - k;
			for (int j = i + 1; j <= n; j++){//по строке
			//	cout << local_sum << endl;
			//	cout << "i=" << i << endl;
			//	cout << "j=" << j << endl;
			//	cout << "result=" << result<<endl;
				if (local_sum <= n){
					result++;
					local_sum += max_count - i-k;//идем по строке
				}
				else break;
			}
		}
	}
	
	if (n % 2 == 0) result += n / 2 - 1;
	else result += n / 2;
	cout << result;
	cin.get();
	cin.get();
	return 0;
}