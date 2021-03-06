#include<iostream>
#include <cstdio> 
#include <vector> 
#include <utility> 
#include <functional> 
#include <stdint.h> 
#include <ctime> 
#include<stack>
using namespace std;
typedef uint32_t data_t;

class BlackInt {
public:
	explicit BlackInt() : value(0) {}
	explicit BlackInt(const uint32_t &_value) : value(_value) {}
	BlackInt(BlackInt &rhs) {
		++swap_counter;
		value = rhs.value;
	}
	explicit BlackInt(const BlackInt &rhs) {
		++swap_counter;
		value = rhs.value;
	}

	inline bool operator == (const BlackInt &rhs) const {
		++cmp_counter;
		return value == rhs.value;
	}
	inline bool operator != (const BlackInt &rhs) const {
		++cmp_counter;
		return value != rhs.value;
	}

	inline bool operator < (const BlackInt &rhs) const {
		++cmp_counter;
		return value < rhs.value;
	}
	inline bool operator >(const BlackInt &rhs) const {
		++cmp_counter;
		return value > rhs.value;
	}
	inline bool operator >= (const BlackInt &rhs) const {
		++cmp_counter;
		return value >= rhs.value;
	}
	inline bool operator <= (const BlackInt &rhs) const {
		++cmp_counter;
		return value <= rhs.value;
	}

	BlackInt& operator=(const BlackInt &rhs) {
		++swap_counter;
		value = rhs.value;
		return *this;
	}

	void swap(BlackInt &rhs) {
		++swap_counter;
		std::swap(value, rhs.value);
	}

	static size_t get_cmp_counter() {
		return cmp_counter;
	}
	static size_t get_swap_counter() {
		return swap_counter;
	}

private:
	data_t value;
	static size_t cmp_counter;
	static size_t swap_counter;
};

size_t BlackInt::cmp_counter = 0;
size_t BlackInt::swap_counter = 0;

namespace std {
	void swap(BlackInt &lhs, BlackInt &rhs) {
		lhs.swap(rhs);
	}
}

bool check_order(const std::vector<data_t> &data) {
	for (size_t pos = 1; pos < data.size(); ++pos) {
		if (data[pos] < data[pos - 1]) {
			return false;
		}
	}
	return true;
}

data_t calc_hash(const std::vector<data_t> &data) {
	data_t value = 16481;
	data_t base = 59359;
	data_t factor = 59357;
	for (size_t pos = 0; pos < data.size(); ++pos) {
		value = ((value * factor) % base + (data[pos] % base)) % base;
	}
	return value;
}

void sort(BlackInt *begin, BlackInt *end);

int main() {
	std::vector<data_t> data;
	data_t value = 0;
	while (scanf("%u", &value) == 1) {
		data.push_back(value);
	}


	clock_t start_s = clock();
	sort(reinterpret_cast<BlackInt*>(&data[0]), reinterpret_cast<BlackInt*>(&data[data.size()]));
	clock_t stop_s = clock();
	size_t delta_clocks = stop_s - start_s;

	printf("%d %d %zd %zd %f\n", calc_hash(data), check_order(data) ? 1 : 0, BlackInt::get_cmp_counter(), BlackInt::get_swap_counter(), delta_clocks / double(CLOCKS_PER_SEC));
	return 0;
}
void insert_sort(BlackInt* arr, BlackInt begin, BlackInt end)
{
	for (BlackInt i = begin; i < end; i++) {
		BlackInt current = arr[i];
		BlackInt j = 0;
		for (j = i - 1; ((j >= 0) && (arr[j]>current)); j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = current;
	}
}
BlackInt max1(BlackInt a, BlackInt b)
{
	if (a > b) return a;
	return b;
}
BlackInt min1(BlackInt a, BlackInt b)
{
	if (a < b) return a;
	return b;
}
int Partition(BlackInt *arr, BlackInt begin, BlackInt end)
{
	BlackInt index = 0;
	if ((arr[begin] >= min1(arr[end - 1], arr[(end + begin) / 2])) && (arr[begin] <= max1(arr[end - 1], arr[(end + begin) / 2]))) index = begin;
	if ((arr[end - 1] >= min1(arr[begin], arr[(end + begin) / 2])) && (arr[end - 1] <= max1(arr[begin], arr[(end + begin) / 2]))) index = end - 1;
	if ((arr[(end + begin) / 2] >= min1(arr[end - 1], arr[begin])) && (arr[(end + begin) / 2] <= max1(arr[end - 1], arr[begin]))) index = (end + begin) / 2;
	BlackInt i = begin;
	BlackInt j = begin;
	swap(arr[index], arr[end - 1]);
	for (; j < end - 1;){
		if (arr[j]>arr[end - 1]){
			j++;
		}
		else{
			swap(arr[i], arr[j]);
			j++;
			i++;
		}
	}
	swap(arr[i], arr[end - 1]);
	return i;
}
void quick_sort(BlackInt *arr, BlackInt begin, BlackInt end)
{
	stack<BlackInt> s_begin;
	stack<BlackInt> s_end;
	s_begin.push(begin);
	s_end.push(end);
	while (!s_begin.empty()){
		begin = s_begin.top();
		s_begin.pop();
		end = s_end.top();
		s_end.pop();
		if (begin >= end) continue;
		if (end - begin <= 100) insert_sort(arr, begin, end);
		BlackInt q = Partition(arr, begin, end);
		if (q> end - q){ //������� ������� �����
			s_begin.push(begin);
			s_end.push(q);
			s_begin.push(q + 1);
			s_end.push(end);
		}
		else{
			s_begin.push(q + 1);
			s_end.push(end);
			s_begin.push(begin);
			s_end.push(q);
		}
	}
}
void sort(BlackInt *begin, BlackInt *end)
{
	BlackInt size = end - begin;
	quick_sort(begin, 0, size);
}