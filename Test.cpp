#include <iostream>
#include <vector>
#include <map>
#include <random>
//Max size, no more 20
constexpr auto MAX = 20;

void output(const std::vector <int> vector);
void output(const std::map <int, int> map);
bool chek(const int item, const std::map <int, int> map);
bool chek(const int item, const std::vector <int> vector);
	
int main() {

	std::vector <int> vector;
	std::map <int,int> map;
	//gen random 
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> uid(1, 9);
	//step 1- pull random numbers vector and map
	for (int i = 0; i < MAX; i++) {
		vector.push_back(uid(gen));
		map[i] = uid(gen);
	}

	output(vector);
	output(map);

	//step 2- delete random numbes elements
	std::uniform_int_distribution<int> number_delete(1, 15);
	const int number = number_delete(gen);
	std::cout <<"Delete random numbes elements= " << number<<std::endl;
	for (int i = 0; i < number; i++) {
		std::uniform_int_distribution<int> elemenst_delete(1, MAX -1 - i);
		vector.erase(vector.begin() + elemenst_delete(gen));
		map.erase(std::next(map.begin(), elemenst_delete(gen)));
	}

	output(vector);
	output(map);
	
	//step 3- synchronization
	for (int i = 0; i < vector.size();i++ ) {
		if (chek(vector[i], map) == true) 
			vector.erase(vector.begin() + i);
	}

	for (auto  it = map.begin(); it != map.end(); ){
		if (chek(it->second, vector) == true) {
			map.erase( it++);
		}
		else
			++it;
	}

	output(vector);
	output(map);

	system("pause");

	return 0;
}

void output(const std::vector <int> vector) {
	//output consol
	std::cout << "Vector:" << std::endl;
	for (auto it : vector) {
		std::cout << it << " ";
	}
	std::cout << std::endl;
}
void output(const std::map <int, int> map) {
	//output consol
	std::cout << "Map:" << std::endl;
	for (auto& it : map) {
		std::cout << it.second << " ";
	}
	std::cout << std::endl;
}
bool chek(const int item,const std::map <int, int> map) {
	for (auto it : map) {
		if (item == it.second)
			return false;
	}
	return true;
}
bool chek(const int item,const std::vector <int> vector) {
	for (auto it : vector) {
		if (item == it)
			return false;
	}
	std::cout << "Delete item= " << item << std::endl;
	return true;
}