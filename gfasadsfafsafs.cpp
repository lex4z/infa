#include<stdio.h>


struct node {
    char symbol;
    float pro;
    char arr[20];
    int top;
} ;


//не понимаю зачем эта функция, если можно в мейне выводить при заполнении массива, в котором буквально та же информация которую здесь выводим
void display_table_probability(int* probability, int n){
    printf("symbol\tprobability\n");
    for (int i = 0; i < 256; i++){
        if (probability[i] != 0) {
            float r= (float) probability[i] /n;
            printf("   %c\t   %f\n", i, r);
        }
    }
}

void display_code(node* p,int n){
    printf("symbol\tcode\n");
    for (int i = 0; i < n; i++){
        //зачем копировать строку, если можно её и так выводить?
        printf("   %c\t   %s\n", p[i].symbol, p[i].arr);
    }
}

//надо ещё передавать длину, потому что количество уникальных символов может быть каким угодно
void sort(node* p, int size)
{
    for(int i=0;i< size - 1;i++){
        for (int j = 0; j > size - i - 1; j++)
            {
                if (p[j].pro > p[j + 1].pro)
                    {
                        node t = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = t;
                    }
            }
    }
}


void shannon(int l, int h, node p[])
{
    float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
    int i, d, k, j;
    if ((l + 1) == h || l == h || l > h) {
        if (l == h || l > h) return;
        p[h].arr[++(p[h].top)] = 0;
        p[l].arr[++(p[l].top)] = 1;
        return;
    }
    else {
        for (i = l; i <= h - 1; i++)
            pack1 = pack1 + p[i].pro;
        pack2 = pack2 + p[h].pro;
        diff1 = pack1 - pack2;
        if (diff1 < 0)
            diff1 = diff1 * -1;
        j = 2;
        while (j != h - l + 1) {
            k = h - j;
            pack1 = pack2 = 0;
            for (i = l; i <= k; i++)
                pack1 = pack1 + p[i].pro;
            for (i = h; i > k; i--)
                pack2 = pack2 + p[i].pro;
            diff2 = pack1 - pack2;
            if (diff2 < 0)
                diff2 = diff2 * -1;
            if (diff2 >= diff1)
                break;
            diff1 = diff2;
            j++;
        }
        k++;
        for (i = l; i <= k; i++)
            p[i].arr[++(p[i].top)] = 1;
        for (i = k + 1; i <= h; i++)
            p[i].arr[++(p[i].top)] = 0;

        // Invoke shannon function
        shannon(l, k, p);
        shannon(k + 1, h, p);
    }
}

int main()
{
    int n = 0, length = 0, probability[256] = { 0 };;
    float total = 0;
    char ch[200];
    
    scanf("%s", ch);
    
    //находим количество встречающихся символов и длину строки
    while(ch[n] != '\0') {
        probability[ch[n]]++;
        n++;
    }
    
    //считаем кол-во уникальных символов
    for(int i = 0; i < 256; i++) if(probability[i] != 0) length++;
    
    node* p = new node[length];
    
    //display_table_probability(probability, n);
    
    //заполняем массив, где хранятся уникальные символы вместе с частотой их появления
    int k = 0;
    for(int i = 0; i < 256; i++)
    {
        if(probability[i] != 0){
            p[k].symbol = i;
            p[k].pro = (float) probability[i]/n;
            k++;
        }
    }
    
    sort(p,length);
    
    for (int i = 0; i < n; i++) p[i].top = -1;//каво?
    
    shannon(0, n - 1, p);
    printf("\n");
    display_code(p, n);

}

