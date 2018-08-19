#include <iostream>
using namespace std;
class meeting
{
public:
	//int size = 0;//общее кол-во втсреч
	int number=0;//номер в массиве
	int begin=0;//начало встречи
	int end=0;//конец
	int count_conflict=0;//кол-во конфликтов
	bool *conflict;//с кем конфликт
	meeting(){};
	~meeting(){};
};
//void sort_bubble(meeting *meet, int n)
//{
//	int flag = 1;
//	for (int i = 0; (i < n - 1) && (flag == 1); i++)
//	{
//		flag = 0;
//		for (int j = 1; j < n - i; j++)
//		{
//			if (meet[j].count_conflict< meet[j-1].count_conflict)
//			{
//				flag = 1;
//				swap(arr[j][2], arr[j - 1][2]);
//				swap(arr[j][1], arr[j - 1][1]);
//				swap(arr[j][0], arr[j - 1][0]);
//			}
//
//		}
//	}
//}
int appoint_meeting(int size,meeting *meet){
	int result = 0;
	bool *flag_appoint = new bool[size];//кому встреча назначена
	for (int i = 0; i < size; i++) flag_appoint[i] = false;
	int max_count_conflict = -1;
	for (int i = 0; i < size; i++){
		if (meet[i].count_conflict>max_count_conflict) max_count_conflict = meet[i].count_conflict;
	}
	for (int current_conflict = 0; current_conflict <= max_count_conflict; current_conflict++){
		for (int i = 0; i < size; i++){
			if (meet[i].count_conflict == current_conflict){
				if (meet[i].count_conflict == 0){
					if (flag_appoint[i] == false){
						result++;
						flag_appoint[i] = true;
						continue;
					}
				}
				bool flag = true;//будем ли назначать встречу
				for (int j = 0; j < size; j++){
					bool flag = true;//будем ли назначать встречу
					if (meet[i].conflict[j] == true){
						if (flag_appoint[j] = true){
							bool flag = false;
						}
					}
					if ((j == (size - 1)) && (flag == true) && (flag_appoint[i] == false)){
						result++;
						flag_appoint[i] = true;
					}
				}
			}
		}
	}
	return result;
}
int main()
{
	int n = 100000;
	meeting *meet = new meeting[n];
	int i = 0;
	for (; cin >> meet[i].begin >> meet[i].end; i++){
		meet[i].number = i;
	}
	int size = i;
	for (int i = 0; i < size; i++){
		meet[i].conflict = new bool[size];// с кем у него конфликт
		for (int j = 0; j < size; j++){
			meet[i].conflict[j] =false;
		}
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (j == i) continue;
			if ((meet[i].begin < meet[j].begin) && (meet[i].end == meet[j].begin)) continue;
			if ((meet[i].begin == meet[j].end) && (meet[i].end > meet[j].end)) continue;
			if ((meet[i].begin < meet[j].begin) && (meet[i].end > meet[j].end)){
				meet[i].conflict[j] = true;
				meet[i].count_conflict++;
				continue;
			}
			if ((meet[i].begin == meet[j].begin) && (meet[i].end == meet[j].end)){
				meet[i].conflict[j] = true;
				meet[i].count_conflict++;
				continue;
			}
			if ((meet[i].begin >= meet[j].begin) && (meet[i].begin <= meet[j].end)){
				meet[i].conflict[j] = true;
				meet[i].count_conflict++;
				continue;
			}
			if ((meet[i].begin<=meet[j].begin) && (meet[i].end>meet[j].end)){
				meet[i].conflict[j] = true;
				meet[i].count_conflict++;
				continue;
			}

		}
		cout << "count=" << meet[i].count_conflict << endl;
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (j == i) continue;
			cout << meet[i].conflict[j] << " ";
		}
		cout << endl;
	}
//	sort_bubble(meet, size);
	cout <<appoint_meeting(size, meet);
	system("pause");
	return 0;
}