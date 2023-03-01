#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int base,module;
	printf("insert value: ");
	scanf("%d",&base);
	printf("insert module: ");
	scanf("%d",&module);
	int q[10],r[10],n,i;
	//scomposition in q and r, euclide
	r[0]=base;
	q[1]=module/base;
	printf("q[1] = %d\t",q[1]);
	r[1]=module%base;
	printf("r[1] = %d\n",r[1]);
	for(i=1;r[i]!=0;i++){
		q[i+1]=r[i-1]/r[i];
		printf("q[%d] = %d\t",i+1,q[i+1]);
		r[i+1]=r[i-1]%r[i];
		printf("r[%d] = %d\n",i+1,r[i+1]);
	}
	//compose x based on the q calculated, extended euclide
	n=i;
	int x[10];
	x[0]=0;
	printf("x[0] = %d\n",x[0]);
	x[1]=1;
	printf("x[1] = %d\n",x[1]);
	for(i=2;i<=n;i++){
		x[i]=-(q[i-1]*x[i-1])+x[i-2];
		printf("-%d*%d+%d\n",q[i-1], x[i-1],x[i-2]);
		printf("x[%d] = %d\n",i,x[i]);
	}
	if(x[n]<0){
		x[n]=x[n]+module;
	}
	printf("%d^-1 mod %d = %d",base,module,x[n]);
	return 0;
}
