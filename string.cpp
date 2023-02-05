#include <stdio.h>
class String{
private:
	char* str;
public:
	int Length;
	
	String(int length){
		this->str = new char[length+1];
		this->Length = length;
	}
	
	String(const char* s){
		int n = 0;
		while(s[n]!='\0') n++;
		this->str = new char[n+1];
		this->Length = n;
		for(int i = 0; i < n+1; i++) this->str[i] = s[i];
		this->str[n+1] = '\0';
	}
	
	String(char* s){
		int n = 0;
		while(s[n]!='\0') n++;
		this->str = new char[n+1];
		this->Length = n;
		for(int i = 0; i < n+1; i++) str[i] = s[i];
		this->str[n+1] = '\0';
	}
	
	~String(){
		this->Length = 0;
		delete[] this->str;
	}
	
	void Print(){
		for(int i = 0; i < this->Length; i++) printf("%c", this->str[i]);
		printf("\n");
	}
	
	
	char operator[] (int i){
		if (i < this->Length)  return this->str[i];
		else throw "index is out of bounds";
	}
	
	String operator+(String s2) {
		String temp = String(this->Length+s2.Length);
		for (int i = 0; i < this->Length; i++) temp.str[i] = this->str[i];
		for (int i = 0; i < s2.Length; i++) temp.str[this->Length + i] = s2[i];
		return temp;
	}
	
	String operator*(int n){
		String temp = String(this->Length*n);
		for(int i = 0; i < n; i++)temp = temp + *this;
		return temp;
	}
} ;

int main() {
	String s1 = "12345";
	String s2 = "55555";
	s1.Print();
	s2.Print();
	String s3 = s1*3;
	s3.Print();
	
	printf("%c",s1[4]);
	
	return 0;
}