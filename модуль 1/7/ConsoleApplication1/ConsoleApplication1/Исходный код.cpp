#include <iostream>
using namespace std;
struct meeting{
	long long begin = 0;
	long long end = 0;
	long long duration = 0;

	
};
void sort_bubble(meeting *meet, int n)
{
	int flag = 1;
	for (int i = 0; (i < n - 1) && (flag == 1); i++)
	{
		flag = 0;
		for (int j = 1; j < n - i; j++)
		{
			if (meet[j].end < meet[j-1].end)
			{
				flag = 1;
				swap(meet[j], meet[j - 1]);
			}
			if ((meet[j].end == meet[j - 1].end) && (meet[j].duration < meet[j - 1].duration)){
				swap(meet[j], meet[j - 1]);
				flag = 1;
			}

		}
	}
}

void buffer_up(meeting *&meet,int n)
{
	meeting *new_meet = new meeting[2 * n];
	for (int i = 0; i < n; i++){
		new_meet[i] = meet[i];
	}
	delete[] meet;
//	for (int i = 0; i < n; i++) cout << new_meet[i].begin << ' ' << new_meet[i].end << ' ' << new_meet[i].duration << endl;
//	cout << endl;
	meet = new_meet;
//	for (int i = 0; i < 2 * n; i++) cout << meet[i].end << " ";
// cout << endl;
}
int hoare_split(meeting *arr, int a, int b)
{
	int x = arr[a].end;
	int i = a - 1;
	int j = b + 1;
	while (true)
	{
		while (true)
		{
			j = j - 1;
			if ((arr[j].end <= x) || (j == a)) break;
		}
		while (true)
		{
			i = i + 1;
			if ((arr[i].end >= x) || (i == b)) break;
		}
		if (i < j) swap(arr[i], arr[j]);
		else
			return j;
	}
}
void quick_sort(meeting *arr, int a, int b)
{
	/////////////hoare
	if (a < b){
	int q = hoare_split(arr, a, b);
	quick_sort(arr, a, q);
	quick_sort(arr, q + 1, b);
	}
}
int appoint_meeting(meeting *meet, int size, int max_count, int number_max)
{
	int begin_0 = meet[number_max].begin;
	int end_0 = meet[number_max].end;
	quick_sort(meet, 0, size);//первый 0 0 встреча с максимальным end пропадает
	meet[0].begin = begin_0;
	meet[0].end = end_0;
	int result = 0;
	int min = 0;
	for (int i = 1; i < size; i++){
		if (meet[i].begin >= min){
			result++;
			min = meet[i].end;
		}
	}
	if (meet[0].begin >= min) result++;
	return result;
}
//int prev_min = 0;
//	for (int i = 0; i < size; i++)
//	{
//	for (int i = 0; i < n;i++) cout << meet[i].end << " ";
/*	bool flag = true;
for (int j = 0; j < n; j++)
{
if (flag == true){
if (meet[j].end != -1){
min = meet[j].end;
current_meet = j;
flag = false;
}
}
else{
if ((meet[j].end < min) && (meet[j].end != -1)){
min = meet[j].end;
current_meet = j;
}
}
if (j == (n - 1)){//все элементы прошли
if (meet[current_meet].begin >= prev_min){
result++;
prev_min = min;
}
meet[current_meet].end = -1;
}
}
}*/
//}
int main()
{
	long long size = 0;
	long long  n = 3;//размер буфера
	long long a = 0;
	long long b = 0;
	int number_max = 0;
	long long max_count = -1;
	meeting *meet=new meeting[n];
	for (; cin >> a >> b;size++){
	if (size == n){
			buffer_up(meet, n);
			n = 2 * n;
		}
		//cout << "n=" << n << endl;
		//cout << "size=" << size << endl;
		meet[size].begin = a;
		meet[size].end = b;
		meet[size].duration = b - a;
		if (max_count < meet[size].end){
			number_max = size;
			max_count = meet[size].end;
		}
	}
//	cout << size << endl;
//	for (int i = 0; i < size; i++){
//		cout << meet[i].begin << " " << meet[i].end << endl;
//	}
//	cout << "------------------"<<endl;
//	sort_bubble(meet, size);//сортируем по end
//	for (int i = 0; i < size; i++){
//		cout << meet[i].begin << " " << meet[i].end<<endl;
//	}
	/*for (int i = 0; i < size; i++){
				cout << meet[i].begin << " " << meet[i].end<<endl;
			}*/
	//отсортирован но максимальный элемент на нулевом месте
	cout <<appoint_meeting(meet,size,max_count,number_max);
	system("pause");
	return 0;
}