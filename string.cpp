#include <stdio.h>

class String {
private:
	char* str;
	int Length;
public:
	
	String(){
		str = new char[1];
		Length = 0;
	}
	
	String(int length) {
		str = new char[length + 1];
		Length = length;
	}
	
	String(char c) {
		str = new char[2];
		str[0] = c;
		Length = 1;
	}

	String(const char* s) {
		int n = 0;
		while (s[n] != '\0') n++;
		str = new char[n + 1];
		Length = n;
		for (int i = 0; i < n + 1; i++) str[i] = s[i];
	}

	String(char* s) {
		int n = 0;
		while (s[n] != '\0') n++;
		str = new char[n + 1];
		Length = n;
		for (int i = 0; i < n + 1; i++) str[i] = s[i];
	}
	
	//destructior
	~String() {
		
	}
	
	//finding subString in main string, returns first index of subString in main string
	int find(String subString){
		for(int i = 0; i < Length - subString.Length + 1; i++) {
			String temp = "";
			for(int j =0; j < subString.Length; j ++)temp = temp + (*this)[j+i];
			if(temp == subString) return i;
		}
		return -1;
	}
	
	int toInt() {
		int ans = 0;
		for(int i = 0; i < Length; i++) {
			if((*this).str[i]<'0' || (*this).str[i] >'9') throw "the string is not integer number!";
			ans = ans * 10 + (*this).str[i] - 48;
		}
		return ans;
	}

	int count(String subString){
		int n = 0;
		for(int i = 0; i < Length - subString.Length + 1; i++) {
			String temp = "";
			for(int j =0; j < subString.Length; j ++)temp = temp + (*this)[j+i];
			if(temp == subString){
				i+=subString.Length-1;
				n++;
			} 
		}
		return n;
	}
	
	String operator[] (int i) {
		if (i < Length)  return String(str[i]);
		else throw "index is out of bounds";
	}
	
	String operator+(String s2) {
		String temp = String(Length + s2.Length);
		for (int i = 0; i < Length; i++) temp.str[i] = str[i];
		for (int i = 0; i < s2.Length; i++) temp.str[Length + i] = s2.str[i];
		return temp;
	}
	
	String operator*(int n) {
		String temp = String("");
		for (int i = 0; i < n; i++)temp = temp + *this;
		return temp;
	}
	
	bool operator==(String s2){
		int n = 0;
		while (str[n] + s2.str[n] != 0 && str[n] == s2.str[n]) n++;
		return n == Length && n == s2.Length;
	}
	
	int getLength(){
		return Length;
	}
	
	char* getText(){
		return str;
	}
};

int main() {
	String s1 = "123455555";
	String s2(45);
	//printf("%s\n", s1.getText());
	printf("%s\n%d\n", s2.getText(),s2.getLength());
	String s3 = s1 * 3;
	//printf("%s\n", s3.getText());
	
	
	//printf("%d\n", s1.count('5'));

	return 0;
}