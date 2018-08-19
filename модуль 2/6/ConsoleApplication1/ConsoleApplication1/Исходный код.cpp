#include <iostream>
#include<string>
#include<vector>
#include<cassert>
using namespace std;
template<class T>
T* by_letter(T*arr,int begin,int end,int j=0)
{
	for (int i = begin; i < end; i++){
		if (arr[i].size() == j) {
			swap(arr[i], arr[begin++]);//последний элемент
		}
	}
	//int *WT = new int[end - begin];
	//vector<int> WT(end - begin);
	vector<int> WT(end);
//	int LT[257];
	vector<int> LT(257,-1);
		/*	for (int i = 0; i < 257; i++){
		LT[i] = -1;
	}*/
	for (int i = begin; i < end; i++){
		WT[i] = LT[static_cast<int> (arr[i][j])];
		LT[static_cast<int> (arr[i][j])] = i;
	}
	int k_end = begin;
	vector<T> new_arr(end);
	for (int i = begin; (i < end); i++){
		new_arr[i] = arr[i];
	}
		for (int i = 0; i < 257; i++){
		if (LT[i] != -1){
			assert(k_end<end);
			assert(LT[i] < end);
			int index_wt = LT[i];
			int k_begin = k_end;
			while (index_wt != -1){//сюда идут все строки
				arr[k_end++] = new_arr[index_wt];
				index_wt = WT[index_wt];
			}
			if (k_end>(k_begin + 1)){
				j++;
				by_letter(arr, k_begin, k_end, j);
				j--;
			}
		}
	}
//	delete[] new_arr;
//	delete[] WT;
	return arr;
}
template<class T>
void MSD_sort(T *arr, int begin, int end)
{
	T*new_arr = by_letter(arr,begin,end,0);//по нулевому символу


	//delete[] arr; ??????????????????
	for (int i = begin; ((i < end)); i++){	
		arr[i] = new_arr[i];
	}
}
//они печатают нулевой символ в консоли как a??????
int main()
{
	vector<string> arr;
	string str;
	while (getline(cin, str)){
		arr.push_back(str);
	}
	MSD_sort(arr.data(), 0, arr.size());
	for (int i = 0; i < arr.size(); i++){
	cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}