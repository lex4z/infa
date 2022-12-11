#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int lecha = 7;
	int sava = lecha;
	
	string s = "213 123 123 444 123 44444";
	string p = "44444";
	int n = 0, k = 0;
	for(int i = 0; i < s.length();i++){
		if(s[i]==p[k])k++;
		else k = 0;
		if(k == p.length()) {
			n++;
			k = 0;
		}
	}
	cout << n << endl;
	//cout << s.find(p) << endl;
	
	
	
	return 0;
}