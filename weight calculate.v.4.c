/* weight calculate.V.5 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	struct data
	{
		char ds[4];
		char c1;
		char de[5];		/* ds=date start,de=date end */		
	} r,*ptr;       	/* r=record */
	
	FILE *fptr;
	char str[5];			
	double aw,aw1,w,d=1.,t=0.;  /* w=weight,d=days,t=total,aw=average weight */
	
	printf("請輸入開始日期:");
	gets(r.ds);
	printf("請輸入結束日期:");
	gets(r.de);
	printf("輸入體重,欲停止請輸入0\n\n");
	r.c1='~';
	
	while(1)
	{
		printf("請輸入第%.0f天的體重:",d);
		scanf("%lf",&w);
		if(w==0)
			break;
		t+=w;
		d++;
	}
	aw=t/(d-1);
	aw1=aw;
	gcvt(aw,4,str);
	ptr=&r;
	
	fptr=fopen("C:\\Dev C++\\weight calculate\\weight record.txt","a");
	if(fptr!=NULL)
	{
		fwrite(ptr,sizeof(r),1,fptr);
		fwrite(str,sizeof(str),1,fptr);	
		putc('\n',fptr);
	}
	fclose(fptr);
	
	printf("\n%.0lf天的平均體重:%.2lf\n",d-1,aw1);
	system("pause");
	return 0;
}
