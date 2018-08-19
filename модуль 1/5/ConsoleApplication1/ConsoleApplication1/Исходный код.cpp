//push-добавить;pop-извлечь
//можно ли преоброзовать стековыми операциями  s1 в s2 
#include<iostream>
#include<string>
#include<cassert>
#include "cstack.h"
using namespace std;
bool convert(string s1,string s2){
	int i = 0;//счетчик по s1
	int j = 0;//счетчик по s2
	int stack_count = 0; //кол-во элементов в стэке

	bool flag = false;
	cstack stack(2);
	if ((s2.length() != s1.length())){
		return false;
	}
	while (true){
		flag = false;
		while (stack_count>0){
			if ((stack.show() == s2[j]) && (j<s2.length())){
				stack.pop();
				stack_count--;
				j++;
				flag = true;
				if (j == (s2.length())){
					return true;
				}
			}
			else break;
		}
		while ((s1[i] == s2[j]) && (i<s1.length()) && (j<s2.length())){
			flag = true;
			i++;
			j++;
		}
		if ((stack_count>0) && (stack.show() == s2[j])) continue;//сначала проверим стэк

		while ((s1[i] != s2[j]) && (i < s1.length()) && (j < s2.length())){
			flag = true;
			stack.push(s1[i]);
			stack_count++;
			i++;
		}
		if (i == s1.length() && (stack_count == 0) && (j < s2.length())){
			return false;
		}
		if (j == s2.length()){
			return true;
		}
		if (flag == false)
		{
			return false;
		}
	}
}
int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	bool flag=convert(s1, s2);
	if (flag == true) cout << "YES";
	else cout << "NO";
	cin.get();
	cin.get();
	return 0;
}