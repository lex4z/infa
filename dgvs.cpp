#include <stdio.h>
#include <random>
#include <time.h>

int main() {
	unsigned char x, res, y, z, j = 0;
	int ch, n = 0, t;
	srand(time(0));
	
	do {
		printf("press 1 - to check <<\n");
		printf("press 2 - to check >>\n");
		printf("press 3 - to check |\n");
		printf("press 4 - to check &\n");
		printf("press 5 - bit in 0\n");
		printf("press 6 - bit in 1 <<\n");
		printf("press 8 - exit\n");
		scanf("%d",&ch);
		j = j|(1<<(ch-1));
		x = rand()%10;
		y = rand()%10;
		if(ch < 5) printf("%d ",x);
		switch (ch) {
			case 1:
				res = x << 1;
				printf(" << 1 = ");
				break;
			case 2:
				res = x >> 1;
				printf(" >> 1 = ");
				break;
			case 3:
				res = x | y;
				printf(" | %d = ", y);
				break;
			case 4:
				res = x & y;
				printf(" & %d = ", y);
				break;
			case 5:
				x = rand()%8;
				res = y|(1<<x);
				printf("%d №%d in 1 = ",y,x);
				break;
			case 6:
				x = rand()%8;
				res = y&~(1<<x);
				printf("%d №%d in 0 = ",y,x);
				break;
			case 7:
				break;
		}
		if(ch!=8) scanf("%d",&t);
		//printf("%d\n",j);
		if(res == t){
			printf("da\n");
		}
		
		if(ch==8 && j!=255) {
			char k = 0;
			while(k!=7){
				if(((1<<k)&j) == 0) printf("%d\n",k+1);
				k++;
			}
			
			ch--;
			
		}
	} while (ch!=8);
	
	
	return 0;
}