#include<iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
	int n, i=0;
	string line, temp;

	cin >> n;
	cin.ignore();

	int *scores=new int[n];

	int temp_max=0, count_max=0;
	int temp_min=0, count_min=0;

	getline(cin,line);
	istringstream iss(line);

	while(iss >> temp){
		scores[i]=stoi(temp);
		++i;
	}

	i=0;
	for (i = 0; i < n; ++i) {
		if(i==0){
			temp_max=scores[i];
			temp_min=scores[i];
		}
		if (temp_max > scores[i]) {
			if (temp_min > scores[i]) {
				++count_min;
				temp_min = scores[i];
			}
		}
		else if (temp_max < scores[i]) {
			temp_max = scores[i];
			++count_max;
		}
	}

	cout << count_max << " " << count_min << endl;

	delete []scores;
	return 0;
}
