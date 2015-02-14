#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
//https://www.codeeval.com/open_challenges/116/
//http://www.networkingprogramming.com/1024x768/cproject12.html
/*
	MORSE CODE
	CHALLENGE DESCRIPTION:


	You have received a text encoded with Morse code and want to decode it.

	INPUT SAMPLE:

	Your program should accept as its first argument a path to a filename. Input example is the following:

	.- ...- ..--- .-- .... .. . -.-. -..-  ....- .....
	-... .... ...--
	Each letter is separated by space char, each word is separated by 2 space chars.

	OUTPUT SAMPLE:

	Print out decoded words. E.g.

	AV2WHIECX 45
	BH3
	You program has to support letters and digits only.

	SUB
*/
int main(int argc, const char** argv) {

	map<string, char> mymap;
	mymap.insert(pair<string, char>(".-", 'A'));
	mymap.insert(pair<string, char>("-...", 'B'));
	mymap.insert(pair<string, char>("-.-.", 'C'));
	mymap.insert(pair<string, char>("-..", 'D'));
	mymap.insert(pair<string, char>(".", 'E'));
	mymap.insert(pair<string, char>("..-.", 'F'));
	mymap.insert(pair<string, char>("--.", 'G'));
	mymap.insert(pair<string, char>("....", 'H'));
	mymap.insert(pair<string, char>("..", 'I'));
	mymap.insert(pair<string, char>(".---", 'J'));
	mymap.insert(pair<string, char>("-.-", 'K'));
	mymap.insert(pair<string, char>(".-..", 'L'));
	mymap.insert(pair<string, char>("--", 'M'));
	mymap.insert(pair<string, char>("-.", 'N'));
	mymap.insert(pair<string, char>("---", 'O'));
	mymap.insert(pair<string, char>(".--.", 'P'));
	mymap.insert(pair<string, char>("--.-", 'Q'));
	mymap.insert(pair<string, char>(".-.", 'R'));
	mymap.insert(pair<string, char>("...", 'S'));
	mymap.insert(pair<string, char>("-", 'T'));
	mymap.insert(pair<string, char>("..-", 'U'));
	mymap.insert(pair<string, char>("...-", 'V'));
	mymap.insert(pair<string, char>(".--", 'W'));
	mymap.insert(pair<string, char>("-..-", 'X'));
	mymap.insert(pair<string, char>("-.--", 'Y'));
	mymap.insert(pair<string, char>("--..", 'Z'));
	mymap.insert(pair<string, char>("-----", '0'));
	mymap.insert(pair<string, char>(".----", '1'));
	mymap.insert(pair<string, char>("..---", '2'));
	mymap.insert(pair<string, char>("...--", '3'));
	mymap.insert(pair<string, char>("....-", '4'));
	mymap.insert(pair<string, char>(".....", '5'));
	mymap.insert(pair<string, char>("-....", '6'));
	mymap.insert(pair<string, char>("--...", '7'));
	mymap.insert(pair<string, char>("---..", '8'));
	mymap.insert(pair<string, char>("----.", '9'));

	map<string, char>::iterator it = mymap.begin();
	ifstream file("input.txt");
	string line,code;
	stringstream ss;
	if(file.is_open()) {
		while(getline(file, line)) {
			//Ignore empty lines
			if (line.empty()) {
				continue;
			}
			//input line to the stream
			ss << line;
			//seperate the line by the spaces
			while(getline(ss, code, ' ')) {
				//since words are seperated by two spaces, the getline will break at one space, 
				//and then read another space, making that specific input empty, so if it's empty, then we know its a word not a character
				if (code.empty()) {
					cout << " ";//Print out a space to seperate the words
				}
				//use the morse code as the key to find it's respective value or letter in this case
				else if ((it = mymap.find(code)) != mymap.end()) {
					cout << it->second;
				}
			}
			//reset for next line
			cout << endl;
			ss << "";
			ss.clear();
		}
	}
	file.close();
}