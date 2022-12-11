#include <stdio.h>
#include <time.h>
#include <random>
/*
char* bin(unsigned char x) {
int n = 0;
char* str = new char[9];
for (int i = 0; i < 8; i += 1) {
str[7-i] = x % 2 + 48;
x /= 2;
}
str[8] = '\0';
return str;
}

char* deleteSpaces(char* str){
int n = 0, len = 1;
while(str[n]!='\0') {
len+=1;
n+=1;
}
n=0;
for(int i = 0; i < len; i+=1){
if(str[i]!=' ') n+=1;
}
char* a = new char[n+1];
n = 0;
for(int i = 0; i < len; i+=1){
if(str[i]!=' ') {
a[n] = str[i];
n+=1;
}

}
return a;
}

char* addF(char* str, char c){
int n = 0, len = 0;
while(str[n]!='\0') {
len+=1;
n+=1;
}
char* a = new char[len+1];
a[0]=c;
for(int i = 0; i < len; i+=1){
a[i+1]=str[i];
}
return a;
}
char* addE(char* str, char c){
int n = 0, len = 0;
while(str[n]!='\0') {
len+=1;
n+=1;
}
char* a = new char[len+1];
a[len]=c;
for(int i = 0; i < len; i+=1){
a[i]=str[i];
}
return a;
}


void addF(char *&str, char c){
char* t = str;
int len= 0;
while(str[len]!='\0') len+=1;
str = new char[len+1];
str[0] = c;
for(int i = 0; i < len; i+=1){
str[i+1]=t[i];
}
delete t;
}

void addB(char *&str, char c){
char* t = str;
int len= 0;
while(str[len]!='\0')len+=1;
str = new char[len+1];
str[len] = c;
for(int i = 0; i < len; i+=1){
str[i]=t[i];
}
delete t;
}

void deleteSpaces(char *&str){
char* t = str;
int l= 0, n = 0;
while(str[n]!='\0'){
if(str[n]!=' ') l+=1;
n+=1;
}
str = new char[l+1];
l=0;
for(int i = 0; i < n; i+=1){
if(t[i]!=' ') {
str[l]=t[i];
l+=1;
}
}
delete t;
}
*/
int main()
{
    int a[10], max = -228, nmax = 0, numbers[10] = { 0 };
    srand(time(0));
    for (int i = 0; i < 10; i += 1) {
        a[i] = rand() % 10;
        numbers[a[i]] += 1;
        printf("%d ", a[i]);
    }
    printf("\n");
    
    
    /*
    for(int j = 0; j < 3; j+=1){
        for (int i = 0; i < 10; i += 1) {
            if(numbers[i]>max){
                max = numbers[i];
                nmax = i;
            }
        }
        numbers[nmax]=0;
        printf("%d: %d\n",nmax,max);
        max = -412;
    }
    */
    return 0;
}