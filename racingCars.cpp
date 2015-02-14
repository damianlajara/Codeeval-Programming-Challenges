//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//using namespace std;
//int main(int argc, const char* argv[]) {
//	ifstream file("input.txt");
//	stringstream ss;
//	string line, input;
//	//char checkpoint = 'C';
//	//char gate = '_';
//	string checkpoint = "C";
//	string gate = "_";
//	string obstacle = "#";
//	size_t position;
//
//	if (file.is_open()) {
//		getline(file, line);
//		size_t found = line.find_first_not_of(obstacle);
//		if (found != string::npos) {
//			position = found;
//			line.at(found) = '|';
//			cout << line << endl;
//			
//		}
//		while (getline(file, line)) {
//			size_t foundC = line.find_first_of(checkpoint);
//			if (foundC != string::npos) {
//				//cout << "Position: " << position << endl;
//				//cout << "foundC: " << foundC << endl;
//
//				//move left
//				if (foundC < position) {
//					cout << "Entered move left C" << endl;
//					line.at(foundC) = '/';
//					position = foundC;
//				}
//				//move straight
//				else if (foundC == position) {
//					cout << "Entered move straight C" << endl;
//					line.at(foundC) = '|';
//					position = foundC;
//				}
//				//move right
//				else {
//					cout << "Entered move right C" << endl;
//					line.at(foundC) = '\\';
//					position = foundC;
//				}
//			} else if (size_t foundG = line.find_first_of(gate) != string::npos) {
//				//move left
//				if (foundG < position) {
//					cout << "Entered move left G" << endl;
//					line.at(foundG) = '/';
//					position = foundG;
//				}
//				//move straight
//				else if (foundG == position) {
//					cout << "Entered move straight G" << endl;
//					line.at(foundG) = '|';
//					position = foundG;
//				}
//				//move right
//				else {
//					cout << "Entered move right G" << endl;
//					line.at(foundG) = '\\';
//					position = foundG;
//				}
//			} else cout << "Did not find a checkpoint nor a gate!" << endl;
//			cout << line << endl;
//		}
//		system("PAUSE");
//	}
//	return 0;
//}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
// https://www.codeeval.com/open_challenges/136/
int main(int argc, const char* argv[]) {
	ifstream file("input.txt");
	stringstream ss;
	string line, input;
	//char checkpoint = 'C';
	//char gate = '_';
	string checkpoint = "C";
	string gate = "_";
	string obstacle = "#";
	size_t position;

	if (file.is_open()) {
		getline(file, line);
		size_t found = line.find_first_not_of(obstacle);
		if (found != string::npos) {
			position = found;
			line.at(found) = '|';
			cout << line << endl;

		}
		while (getline(file, line)) {
			size_t foundC = line.find_first_of(checkpoint);
			if (foundC != string::npos) {
				//cout << "Position: " << position << endl;
				//cout << "foundC: " << foundC << endl;

				//move left
				if (foundC < position) {
					cout << "Entered move left C" << endl;
					line.at(foundC) = '/';
					position = foundC;
				}
				//move straight
				else if (foundC == position) {
					cout << "Entered move straight C" << endl;
					line.at(foundC) = '|';
					position = foundC;
				}
				//move right
				else {
					cout << "Entered move right C" << endl;
					line.at(foundC) = '\\';
					position = foundC;
				}
			}
			else if (size_t foundG = line.find_first_of(gate) != string::npos) {
				//move left
				if (foundG < position) {
					cout << "Entered move left G" << endl;
					line.at(foundG) = '/';
					position = foundG;
				}
				//move straight
				else if (foundG == position) {
					cout << "Entered move straight G" << endl;
					line.at(foundG) = '|';
					position = foundG;
				}
				//move right
				else {
					cout << "Entered move right G" << endl;
					line.at(foundG) = '\\';
					position = foundG;
				}
			}
			else cout << "Did not find a checkpoint nor a gate!" << endl;
			cout << line << endl;
		}
		system("PAUSE");
	}
	return 0;
}