#include<stdio.h>
#include<stdlib.h>
double noise(double x,double e){
	return x+0.001*(rand()%2000-1000)*e;
}
void a506(){
	double a[15],b[15],r[5],sum=0,offset;
	int i,seed;
	puts("ţ�ٻ�ʵ����������\n��ȷ��ʵ����m=10,��=569.3nm");
	printf("������������ӣ�");
	scanf("%d",&seed);
	srand(seed);
	offset=noise(0,7);
	for (i=0;i<15;i++){
		a[i]=offset+noise(32.5903-0.0918370*(i+1),0.02);
		b[i]=offset+noise(18.388774+0.08724*(i+1),0.02);
	}
	for (i=0;i<5;i++){
		r[i]=(a[i]-a[i+10])*(a[i]-b[i+10])/10/0.0005693;
	}
	puts(" k      Ak      Bk");
	for (i=0;i<5;i++){
		printf("%2d %7.3lf %7.3lf\n",40-i,a[i],b[i]);
	}
	for (i=0;i<5;i++){
		printf("%2d %7.3lf %7.3lf\n",30-i,a[i+10],b[i+10]);
	}
	puts("������£�");
	for (i=0;i<5;i++){
		sum+=r[i];
		printf("R_%d=%7.2lf\n",5-i,r[i]);
	}
	printf("Rƽ��=%7.2lf\n",sum/5);
}

void a507(){
    int i,seed;
    double theta[8];
    puts("�ֹ��ʵ����������");
	printf("������������ӣ�");
	scanf("%d",&seed);
	srand(seed);
    for(i=0;i<4;i++){
        theta[i]=noise(60,40);
        theta[i+4]=theta[i]+noise(38.66666666,0.4);
    }
    puts("���      ��1      ��2     ��1'     ��2'");
    for(i=0;i<4;i++){
        printf("%4d %3d��%2d' %3d��%2d' %3d��%2d' %3d��%2d'\n",i+1,
               (int)theta[i],
               (int)((theta[i]-(int)theta[i])*60),
               (int)theta[i]+180,
               (int)((theta[i]-(int)theta[i])*60),
               (int)theta[i+4],
               (int)((theta[i+4]-(int)theta[i+4])*60),
               (int)theta[i+4]+180,
               (int)((theta[i+4]-(int)theta[i+4])*60));
    }
}
main(){
    int sel;
    while(1){
        puts("\
====================\n\
6.A506ţ�ٻ�ʵ��\n\
7.A507�ֹ��ʵ��");
        printf("��ѡ��");
        scanf("%d",&sel);
        if(sel==6) a506();
        if(sel==7) a507();
    }
}
