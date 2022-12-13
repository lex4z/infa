#include<stdio.h>


struct node {
    char symbol;
    int n;
    char arr[20];
} ;

void addBack(char* str, char c){
    int n = 0;
    while(str[n]!='\0') n++;
    str[n]=c;
    str[n+1]='\0';
}

void sort(node* p, int size)
{
    for(int i=0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
                if (p[j].n < p[j + 1].n){
                        node t = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = t;
                    }
            }
    }
}


void shannon(node* m, int first, int second){
    if(second - first < 2) return;
    int summ = 0, k = 0;
    float s = 0;
    for(int i = first; i < second; i++) summ += m[i].n;
    for(int i = first; i < second; i++){
        if(s<0.5){
            addBack(m[i].arr, '0');
            k++;
        }else{
            addBack(m[i].arr, '1');
        }
        s+= (float) m[i].n/summ;
    }
    shannon(m, first, first + k);
    shannon(m, first + k,  second);
    
    
}

int main(){
    int n = 0, length = 0, probability[256] = { 0 };
    char ch[200] = "aa bbb cccc ddddd";
    
    //scanf("%s", ch);
    
    while(ch[n] != '\0') {
        probability[ch[n]]++;
        n++;
    }
    
    for(int i = 0; i < 256; i++) if(probability[i] != 0) length++;
    
    node* p = new node[length];
    
    int k = 0;
    for(int i = 0; i < 256; i++)
    {
        if(probability[i] != 0){
            p[k].symbol = i;
            p[k].n = probability[i];
            k++;
        }
    }
    
    sort(p,length);
    shannon(p, 0, length);
    
    for(int i = 0; i < k; i++){
        printf("%c - %s\n", p[i].symbol, p[i].arr);
    }

    

}

