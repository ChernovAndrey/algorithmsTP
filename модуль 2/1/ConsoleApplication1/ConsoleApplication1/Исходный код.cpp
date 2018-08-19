/*На склад привезли много пустых ящиков. Все ящики пронумерованы по порядку поступления от 0.

Известно, что их все можно сложить один в один (то есть так, что каждый следующий помещается в

предыдущий). Один ящик можно вложить в другой, если его можно перевернуть так, что размеры

одного ящика по всем осям станут строго меньше размеров другого ящика по соответствующим

осям. Требуется определить, в какой последовательности они будут вложены друг в друга. Вывести

номера ящиков.*/
#include<iostream>
#include<vector>
using namespace std;
struct box
{
	int x = 0;
	int y = 0;
	int z = 0;
	int begin_place = 0;
	box(int x1, int y1,int z1,int i) : x(x1), y(y1),z(z1),begin_place(i) {}
};
bool operator>(const box& first, const box& second)
{
	return ((first.x>second.x) && (first.y>second.y) && (first.z>second.z));
}
bool Compare_box(const box& first, const box& second)
{
	return first > second;
}
template<class T>
bool Compare_xyz(const T& first, const T& second)
{
	return first > second;
}
template<class T>
void insert_sort(T* arr,int begin,int end,bool (*Compare)(const T& , const T&)) 
{
	//int size = end-begin;
	for (int i = begin; i < end; i++) { 
		T current = arr[i];
		int j = 0;
		for (j = i - 1; j >= 0 && Compare(arr[j],current); j--)
			arr[j + 1] = arr[j];  
		arr[j + 1] = current;
	}
}
int main()
{
	vector<box> arr_box;
	int n = 0;
	cin >> n;
	int arr_xyz[3];
	for (int i = 0; i < n; i++){
		cin >> arr_xyz[0] >> arr_xyz[1] >> arr_xyz[2];
		insert_sort(arr_xyz, 0, 3, Compare_xyz);
		arr_box.push_back(box(arr_xyz[0],arr_xyz[1] ,arr_xyz[2],i));
		//cout << arr_box[i].x << arr_box[i].y << arr_box[i].z<< i << endl;
	}
	insert_sort(arr_box.data(),0,arr_box.size(),Compare_box);
	for (int i = 0; i < n; i++){
		cout << arr_box[i].begin_place << " ";
	}
//	system("pause");
	return 0;
}