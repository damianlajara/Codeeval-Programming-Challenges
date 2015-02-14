//https://www.codeeval.com/open_challenges/173/
#include <iostream>
#include <fstream>
using namespace std;

void removeRepeats(string& line) {
	//Loop over the whole string
	for(int i = 1; i < line.length(); i++) {
		//if the previous letter is equal to the current one
		if(line[i] == line[i-1]) {
			//delete the previous letter
			line.erase(i-1,1);
			//shift the counter down by one, since the order was altered due to the erasure of the element
			i--;
		}
	}
}

int main(int argc, const char** argv) {
	ifstream file(argv[1]);
	string line;
	if(file.is_open()) {
		while(getline(file, line)) {
			if(line.empty()) continue;
			removeRepeats(line);
			cout << line << endl;
		}
	}
	return 0;
}