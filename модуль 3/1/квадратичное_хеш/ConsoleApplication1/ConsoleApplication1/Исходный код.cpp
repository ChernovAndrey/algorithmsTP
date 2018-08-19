#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;
const int DefaultTableSize = 8;
const double MaxOccupancy = 0.75;
const int GrowFactor = 2;
string un_string = "park.mail.ru/blog/show/153/tp-test1.tech-mail.ru:5000/contest/81/1/wefdhkjhsdxfgjkoijh";
int un_int = 57480045;
bool Compare(string a)
{
	if (a == un_string) return true;
	return false;
}
bool Compare(int a)
{
	if (a == un_int) return true;
	return false;
}
void assigned(string &a)
{
	a = un_string;
}
void assigned(int &a)
{
	a = un_int;
}
bool empty(int a)
{
	if (a == 0) return true;
	return false;
}
bool empty(string a)
{
	if (a == "") return true;
	return false;
}
int Hash(const string& data, int tableSize)
{
	int hash = 0;
	for (unsigned int i = 0; i < data.size(); i++) {
		hash = (hash * 127 + data[i]) % tableSize;
	}
	return hash;
}
int Hash(const int& data, int tableSize)
{
	int hash = 0;
	int ndata = data;
	for (unsigned int i = 0; ndata>0; i++) {
		hash = (hash * 127 + ndata%10) % tableSize;
		ndata = ndata / 10;
	}
	return hash;
}
template<class T>
class HashTable 
{
public:
	HashTable();
	~HashTable(){};

	bool Add(const T& data);
	bool Delete(const T& data);
	bool Search(const T& data);
	int tablesize;
	unsigned int keysCount;
	vector<T> table;
private:

	void growTable();
};
template <class T>
HashTable<T>::HashTable() : tablesize(DefaultTableSize), keysCount(0)
{
	table.resize(DefaultTableSize);
}
template<class T>
void HashTable<T>::growTable()
{
	vector<T> newTable(table.size() * GrowFactor);
	tablesize = newTable.size();
	for (unsigned int i = 0; i < table.size(); i++) {
		if (Compare(table[i])) continue;
		int hash = Hash(table[i], tablesize);
		int j = 1;
		while (!empty(newTable[hash])){  //не равен
			hash = (hash + j) % tablesize;
			j++;
		} 
		newTable[hash] = table[i];
}
	table = newTable;
}
template <class T>
bool HashTable<T>::Add(const T& data)
{
	if ((keysCount + 1) > MaxOccupancy*tablesize) growTable();
	int hash = Hash(data, tablesize);
	if (empty(table[hash])) { //равен
		keysCount++;
		table[hash] = data;
		return true;
	}
	if (!empty(table[hash])){ 
		int index = hash;
		int i = 1;
		int mark_index = -1;
		for (;((i < tablesize) && (!empty(table[index])));i++){
			if (data == table[index]) return false;
			if (Compare(table[index])){
				mark_index = index;
			}
			index = (index + i) % tablesize;
		}
		if ((i == tablesize)&&(mark_index==-1)) return false;
		if (empty(table[index])){
			table[index] = data;
			keysCount++;
			return true;
		}
		if (mark_index!=-1){
			if (i == tablesize){
				keysCount++;
				table[mark_index] = data;
				return true;
			}
		}
	}
}
template <class T>
bool HashTable<T>::Delete(const T& data)
{
	int hash = Hash(data, tablesize);
	if (empty(table[hash])) return false;
	if (table[hash] == data) {
		keysCount--;
		assigned(table[hash]);
		return true;
	}
	int i = 1;
	int index = hash;
	for (;((table[index]!=data)&&(i<tablesize));){
		if (empty(table[index])) return false;
		index = (index + i)%tablesize;
		i++;
	}
	if (table[index] == data){
		keysCount--;
		assigned(table[index]);
		return true;
	}
	if (i == tablesize){
		return false;
	}
}
template <class T>
bool HashTable<T>::Search(const T& data)
{
	int hash = Hash(data,tablesize);
	int index = hash;
	for (int i = 1; i <= tablesize; i++){
		if (table[index] == data) return true;
		if (empty(table[index])) return false;
		index = (index + i) % tablesize;
	}
	return false;
}
int main()
{
	HashTable<int> table;
	char operation;
	int word;
	while (cin >> operation >> word) {
		switch (operation) {
		case '+':
			cout << (table.Add(word) ? "OK\n" : "FAIL\n");
			break;
		case '-':
			cout << (table.Delete(word) ? "OK\n" : "FAIL\n");
			break;
		case '?':
			cout << (table.Search(word) ? "OK\n" : "FAIL\n");
			break;
		default:
			assert(false);
		}
	}
	return 0;
}