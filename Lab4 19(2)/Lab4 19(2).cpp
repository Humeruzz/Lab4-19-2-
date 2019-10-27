#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

AP* APinput(int);

struct AP {
	string code, fl, group, avMark;
};

int main()
{
	AP* mass;
    
}

AP* APinput(int num)
{
	ifstream inS("Input.txt", ios_base::in);
	if (inS.is_open()) {
		vector<string> tempV;
		char tempCh1[10];
		inS.getline(tempCh1, 10, '\n');
		AP* tempAP = new AP[tempCh1[1]];
		int tempI = 0;
		while (!inS.eof()) {
			for (int j = 0; j < 4; j++) {
				char tempCh[50];
				string tempS;
				inS.getline(tempCh, 50, '\n');
				tempS = tempCh;
				if (tempS.empty()) {
					tempS = "NULL";
				}
				tempV.push_back(tempS);
			}
			tempAP[tempI].code = tempV[0];
			tempAP[tempI].fl = tempV[1];
			tempAP[tempI].group = tempV[2];
			tempAP[tempI].avMark = tempV[3];
			tempI++;
		}
		return tempAP;
	}
	inS.close();
	return 0;
}