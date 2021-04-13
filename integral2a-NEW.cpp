#include<stdio.h> 
#include<math.h>
#define eps 1.0E-6

double FX1(double x){
	return (1/sqrt(x*x*x*x+1));
}
double TrapMethod(double a,double b,int n,double(*p)(double)){
	
	double I=0;
	double h=(b-a)/n;
	for(int i=0;i<=n;i++)
	   I+=((*p)(a+i*h)*h);
	
	return I;
}

int main(){
	
	double I1,I2;
	int n=pow(2,15);
	double a,b;
    do{
       printf("please enter a,b:\n");
       scanf("%lf%lf",&a,&b);
	}while(a>b);
	
	do{
	   I1=TrapMethod(a,b,n,FX1);
	   n*=2;
	   I2=TrapMethod(a,b,n,FX1);
	}while(fabs(I1-I2)>eps);
	
	printf("Integral by TrapMethod=:%lf\n",I2);
	
	return 0;
}

