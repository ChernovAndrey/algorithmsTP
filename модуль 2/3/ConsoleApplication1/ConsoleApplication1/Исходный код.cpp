/*В супермаркете решили оптимизировать показ рекламы. Известно расписание прихода и ухода

покупателей (два целых числа). Каждому покупателю необходимо показать минимум 2 рекламы.

Рекламу можно транслировать только в целочисленные моменты времени. Покупатель может видеть

рекламу от момента прихода до момента ухода из магазина.

В каждый момент времени может показываться только одна реклама. Считается, что реклама

показывается мгновенно. Если реклама показывается в момент ухода или прихода, то считается, что

посетитель успел её посмотреть. Требуется определить минимальное число показов рекламы.*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct visit
{
	long long begin=0;
	long long end=0;
	visit(long long x, long long y) : begin(x), end(y) {};
};
bool operator<(const visit& first, const visit& second)
{
	if (first.end < second.end) return true;
	if ((first.end == second.end) && (first.begin < second.begin)) return true;
	return false;
}
bool Compare_visit(const visit& first, const visit& second)
{
	return first < second;
}
//template <class T>
void heap_make(visit * arr,long long begin,long long end,bool(*Compare)(const visit&,const visit&))
{
	long long size = end-begin;
	for (long long i = size / 2 + 1; i >= begin; i--){
		for (long long j = i; j <= size / 2 + 1;){
			if ((2 * j + 1) >= end)  break;
			int k = 2 * j + 1;
			if ((2 * j + 2 < end) && (Compare(arr[2 * j + 1], arr[2 * j + 2]))) k = 2 * j + 2;
			if (Compare(arr[j], arr[k])) {
				swap(arr[j], arr[k]);
				j = k;
			}
			else break;
		}
	}
}
template <class T>
void heap_pop(T* arr,int begin,int end, bool(*Compare)(const T&,const T&))
//void heap_pop(visit* arr, long long begin, long long end, bool(*Compare)(const visit&, const visit&))
{

	swap(arr[begin], arr[end]);
	for (long long i = begin; i <= end / 2 + 1;){
		if (2*i+1>=end) break;
 		long long k = 2*i + 1;
		if ((Compare(arr[2*i + 1],arr[2*i + 2])) && (2*i + 2 < end)) k = 2*i + 2;
		if (Compare(arr[i],arr[k])){
			swap(arr[i], arr[k]);
			i = k;
		}
		else break;
	}
}
template <class T>
void heap_sort(T* arr,int begin, int end,bool (*Compare)(const T& ,const T&))
//void heap_sort(visit * arr, long long begin, long long end, bool(*Compare)(const visit&, const visit&))
{
	heap_make(arr,begin,end,Compare);
	for (long long i = begin; i < end; i++){
		heap_pop(arr,0,end-i-1,Compare);
	}
}
template<class T>
int show_advertising(vector<T>& arr)
//long long show_advertising(vector<visit>& arr)
{
	long long n = arr.size();
	long long result = 2;
	//long long first = arr[0].end;//первая реклама
	//long long second = arr[0].end - 1;//вторая
	vector<long long> adv(2);
	adv[0] =arr[0].end;
	adv[1] = arr[0].end-1;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < 2; j++){
			if (adv[j] < arr[i].begin){
				if (adv[!j] != arr[i].end)
					adv[j] = arr[i].end;
				else adv[j] = arr[i].end - 1;
				result++;
			}
		}
	}
	return result;
	//long long current_end = 0;
	//long long prev_end = -1;//не всегда нужен
	//for (long long i = 0; i < n; i++){
	//	assert(arr[i].end >= current_end);
	//	assert(current_end>=prev_end);
	//	if ((arr[i].end<current_end) && (prev_end == -1)) continue;
	//	if (arr[i].begin>current_end) {
	//		result += 2;
	//		prev_end = -1;
	//		current_end = arr[i].end;
	//		continue;
	//	}
	//	if (arr[i].begin == current_end) {
	//		result++;
	//		prev_end = current_end;
	//		current_end = arr[i].end;
	//		continue;  
	//	}
	//	//сложные случаи
	//	if (prev_end != -1){
	//		//больше текущего уже рассмотрено
	//		//if (arr[i].begin <= prev_end) continue;
	//		if ((arr[i].begin > prev_end) && (arr[i].begin < current_end)){ //второе условие необязательно)
	//			result++;
	//			prev_end = current_end;
	//			current_end = arr[i].end;
	//		}
	//	}
	//}
	//return result;
}
int main()
{
	long long n = 0;
	cin >> n;
	vector <visit> buyers;
	for (long long i = 0; i < n; i++){
		long long x, y;
		cin >> x >> y;
		buyers.push_back(visit(x,y));
	}
	heap_sort(buyers.data(),0,buyers.size(),Compare_visit);
	cout <<show_advertising(buyers);
	system("pause");
	return 0;
}