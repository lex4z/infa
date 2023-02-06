#include <stdio.h>

class String {
private:
	char* str;
public:
	int Length;

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
		str[n] = '\0';
	}

	String(char* s) {
		int n = 0;
		while (s[n] != '\0') n++;
		str = new char[n + 1];
		Length = n;
		for (int i = 0; i < n + 1; i++) str[i] = s[i];
		str[n] = '\0';
	}


	~String() {
		
	}

	void Print() {
		for (int i = 0; i < Length; i++) printf("%c", str[i]);
		printf("\n");
	}


	char operator[] (int i) {
		if (i < Length)  return str[i];
		else throw "index is out of bounds";
	}

	String operator+(String s2) {
		String temp = String(Length + s2.Length);
		for (int i = 0; i < Length; i++) temp.str[i] = str[i];
		for (int i = 0; i < s2.Length; i++) temp.str[Length + i] = s2[i];
		return temp;
	}

	String operator*(int n) {
		String temp = String("");
		for (int i = 0; i < n; i++)temp = temp + *this;
		return temp;
	}
};

int main() {
	String s1 = "12345";
	String s2 = "55555";
	s1.Print();
	s2.Print();
	String s3 = s1 * 3;
	s3.Print();

	printf("%c", s1[4]);

	return 0;
}