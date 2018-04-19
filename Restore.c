
#include <stdio.h>
#include <stdlib.h>

void RecordAppearedDigits(int n,int a[]);
int IfRepetition(int FourDigitsNum);
void BubbleSort(int* FourDigits);
void RestoreUprightFormula(int* FourDigits,int* p);

int main()
{
	int i=0,x,j,n,FourDigitsNum,flag,k=0,temp,m=0;
	int *FourDigits,*Appeared,*p;
	p=&m;
	Appeared=(int*)malloc(sizeof(int)*5000);
	FourDigits=(int*)malloc(sizeof(int)*4);
	for(FourDigitsNum=1023;FourDigitsNum<=9876;FourDigitsNum++)
	{
		flag=IfRepetition(FourDigitsNum);
		if(flag)
		{
			x=1;
			k=0;
			temp=FourDigitsNum;
			do{
				FourDigits[k]=temp%10;
				temp=temp/10;
				k++;
			}while(temp);
			BubbleSort(FourDigits);
			n=FourDigits[3]*1000+FourDigits[2]*100+FourDigits[1]*10+FourDigits[0];
			for(j=0;j<=i;j++){
				if(Appeared[j]==n) x=0;
			}
			if(x){
				RestoreUprightFormula(FourDigits,p);
				Appeared[i]=n;
				i++;
			}			
		}
	}
	printf("%d\n", m);
	return 0;
}

void RestoreUprightFormula(int* FourDigits,int* p)
{
		int i,j,SumAppearedDigits,RecordDigits[10];
		int ThreeDigitsMAX,ThreeDiditsMIN,TwoDigitsMAX,TwoDigitsMIN;
		int ThreeDigitsNum,TwoDigitsNum,Product1,Product2,Product;
		if(FourDigits[0]==0){
			ThreeDiditsMIN=FourDigits[1]*100;
			TwoDigitsMIN=FourDigits[1]*10;
		}
		else{
			ThreeDiditsMIN=FourDigits[0]*100+FourDigits[0]*10+FourDigits[0];
			TwoDigitsMIN=FourDigits[0]*10+FourDigits[0];
		} 
		TwoDigitsMAX=FourDigits[3]*10+FourDigits[3];
		ThreeDigitsMAX=FourDigits[3]*100+TwoDigitsMAX;
		for(ThreeDigitsNum=ThreeDiditsMIN;ThreeDigitsNum<=ThreeDigitsMAX;ThreeDigitsNum++)
		{
			for(TwoDigitsNum=TwoDigitsMIN;TwoDigitsNum<=TwoDigitsMAX;TwoDigitsNum++)
			{
				for(i=0;i<10;i++) RecordDigits[i]=0;
				RecordAppearedDigits(ThreeDigitsNum,RecordDigits);
				RecordAppearedDigits(TwoDigitsNum,RecordDigits);
				Product1=ThreeDigitsNum*(TwoDigitsNum%10);
				RecordAppearedDigits(Product1,RecordDigits);
				Product2=ThreeDigitsNum*(TwoDigitsNum/10);
				RecordAppearedDigits(Product2,RecordDigits);
				Product=ThreeDigitsNum*TwoDigitsNum;
				RecordAppearedDigits(Product,RecordDigits);
				SumAppearedDigits=0;
				for(j=0;j<4;j++){
					if(RecordDigits[FourDigits[j]]==0){
						SumAppearedDigits=0;
						j=4;
					}
					SumAppearedDigits=SumAppearedDigits+RecordDigits[FourDigits[j]];
				}
				if(SumAppearedDigits==18)
				{
					(*p)++;
					for(j=0;j<4;j++) printf("%d ",FourDigits[j]);
					printf(":%d*%d=%d(%d %d)\n",ThreeDigitsNum,TwoDigitsNum,Product,Product1,Product2);
				}
			}
		}
}

void BubbleSort(int* FourDigits)
{
	int t,i,j,temp;
	for(t=1;t<=4;t++){
		for(i=0,j=1;j<4;i++,j++)
		{
			if(FourDigits[i]>FourDigits[j])
			{
				temp=FourDigits[i];
				FourDigits[i]=FourDigits[j];
				FourDigits[j]=temp;
			}
		}
	}
}

int IfRepetition(int FourDigitsNum)
{
	int j,digit,b[10],flag=1;
	for(j=0;j<10;j++) b[j]=0;
	while(FourDigitsNum&&flag)
	{
		digit=FourDigitsNum%10;
		if(b[digit]) flag=0;
		else{
			b[digit]=1;
			FourDigitsNum=FourDigitsNum/10;
		}

	}
	return flag;
}

void RecordAppearedDigits(int n,int a[])
{
	while(n)
	{
		(*(a+n%10))++;
		n=n/10;
	}

}