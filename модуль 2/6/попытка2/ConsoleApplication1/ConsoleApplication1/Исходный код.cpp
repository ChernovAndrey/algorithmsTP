#include<iostream>
#include<vector>
#include<string>
using namespace std;
char get_char(string& s,long long j)
{
	/*cout << "size=" << s.size() << endl;
	cout << "j="<<j<<endl;*/
	if (s.size() < j+1) return '\0';
	return s[j];
}
template<class T>
void count_sort(T* data, long long size,long long j) {
	long long *count = new long long[257];
	string *aux = new string[size];
	for (long long i = 0; i < 257; ++i) {
		count[i] = 0;
	}
	for (long long i = 0; i < size; ++i) {
		++count[static_cast<long long>(get_char(data[i],j)) + 1];
	}
	for (long long i = 1; i < 257; ++i) {
		count[i] += count[i - 1];
	}
	for (long long i = 0; i < size; ++i) {
	aux[count[static_cast<long long>(get_char(data[i],j))]++] = data[i];
	}
	for (long long i = 0; i < size; i++) {
		data[i] = aux[i];
	}
	delete[] aux;
	delete[] count;
}
template<class T>
void MSD_sort(vector<T>& arr,long long begin,long long end,long long j=0)
{
		count_sort(arr.data()+begin, end-begin, j);//j-разряд
		long long i = begin;
		long long loc_begin = i;
		for (; i < end-1; i++){
			char a1 = get_char(arr[i], j);
			char a2 = get_char(arr[i + 1], j);
			if ((i == end - 2) && (a1 == a2)){
				if (get_char(arr[i], j) != '\0'){
					MSD_sort(arr,loc_begin,i+2,++j);
				}
				loc_begin = i+2;
				continue;
			}
			if (a1!=a2) {
				if ((i - loc_begin>=1) && (get_char(arr[i], j) != '\0')){
					MSD_sort(arr, loc_begin, i + 1,++j);
				}
				loc_begin = i + 1;
			}
		}
}
int main()
{
	vector<string> arr;
	string str;
	while (getline(cin, str)){
		arr.push_back(str);
	}
	MSD_sort(arr,0,arr.size());
	for (long long i = 0; i < arr.size(); i++){
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}