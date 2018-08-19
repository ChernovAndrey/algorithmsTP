#include <iostream>
using namespace std;
//15-27
//50-3658
//300-114872472064
long long  f_rec(long long n) {
	long long result = 0;
	if (n <= 2) return 1;
	for (long long i = 0; i <= n/2; i++) {
		//cout << i << endl;
		result += f_rec(i);
		if (2 * i == n) {
			//cout << "i=" << i << endl;
			result--;
		}
	}
	return result;
}
int main()
{
	long long n = 0;
	cin >> n;
	cout << f_rec(n);
	system("pause");
	return 0;
}