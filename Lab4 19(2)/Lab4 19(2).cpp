#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct AP {
	string name, code, group, avMark;
};

void printAP(AP*, int);
void printAPID(AP*, int, int);
void searchCode(AP*, int, string);
void sortAP(AP*, int);
AP* inputAP();
void binaryOut(AP*, int);
AP* binaryIn(int);
int sizeAP();

int main()
{
	int sizeap;
	sizeap = sizeAP();
	AP* mass;
	AP* mass1;
	mass = inputAP();
	cout << "From normal file: " << endl;
	printAP(mass, sizeap);
	searchCode(mass, sizeap, "18I0831");
	binaryOut(mass, sizeap);
	mass1 = binaryIn(sizeap);
	cout << "From Binary file: " << endl;
	printAP(mass1, sizeap);
}

void printAP(AP* obj, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Name: " << obj[i].name << ", Code: " << obj[i].code << ", Group: " << obj[i].group << ", avMark: " << obj[i].avMark << endl;
	}
	cout << endl;
}

void printAPID(AP* obj, int size, int id) {
	if ((id <= size - 1) && (id >= 0)) {
		cout << "Name: " << obj[id].name << ", Code: " << obj[id].code << ", Group: " << obj[id].group << ", avMark: " << obj[id].avMark << endl;
	}
	cout << endl;
}

void searchCode(AP* obj, int size, string key) {
	bool flag = false;
	int l = 0;
	int r = size-1; 
	int mid;

	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2;
		if (obj[mid].code == key) flag = true;
		if (obj[mid].code > key) r = mid - 1;
		else l = mid + 1;
	}
	if (flag) {
		cout << "There is person with code "<<key <<": " << endl;
		printAPID(obj, size, mid);
	}
	else {
		cout << "There is no person with code "<< key<<"." << endl << endl;
	}
}

void sortAP(AP* obj, int size) {
	AP tempAP;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (obj[j].code > obj[j + 1].code) {
				tempAP = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = tempAP;
			}
		}
	}
}

int sizeAP() {
	ifstream inS("Input.txt", ios_base::in);
	if (inS.is_open()) {
		char tempCh1[10];
		inS.getline(tempCh1, 10, '\n');
		int tempI = atoi(tempCh1);
		return tempI;
	}
	inS.close();
	return NULL;
}

AP* inputAP()
{
	ifstream inS("Input.txt", ios_base::in);
	if (inS.is_open()) {
		vector<string> tempV;
		char tempCh1[10];
		inS.getline(tempCh1, 10, '\n');
		AP* tempAP = new AP[atoi(tempCh1)];
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
			tempAP[tempI].name = tempV[0];
			tempAP[tempI].code = tempV[1];
			tempAP[tempI].group = tempV[2];
			tempAP[tempI].avMark = tempV[3];
			tempI++;
			tempV.clear();
		}
		return tempAP;
	}
	inS.close();
	return NULL;
}

void binaryOut(AP* obj, int size) {
	ofstream outS("Binary.txt",ios_base::out | ios_base::binary);
	if (outS.is_open()) {
		for (int i = 0; i < size; i++) {
			outS.write((char*)&obj[i], sizeof(AP));
		}
	}
	outS.close();
}

AP* binaryIn(int size) {
	ifstream inS("Binary.txt", ios_base::in | ios_base::binary);
	if (inS.is_open()) {
		AP* obj = new AP[size];
		for (int i = 0; i < size; i++){
			inS.read((char*)&obj[i], sizeof(AP));
		}
		return obj;
	}
}