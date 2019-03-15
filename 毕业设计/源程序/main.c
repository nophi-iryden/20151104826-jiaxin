#include "reg52.h"

//�궨��
#define uchar unsigned char
#define uint  unsigned int

//��������
sbit KEY1= P2^0;
sbit KEY2= P2^1;
sbit KEY3= P2^2;

//��δ���������
sbit YD= P2^3;

//����ܶ���
sbit LED1= P0^0;
sbit LED2= P0^3;

//�̵�������
sbit JDQ1= P0^1;
sbit JDQ2= P0^2;

//��ʱ����
void delay_ms(uint z)			  
{
  uint a,b;
  for(a=z;a>0;a--)
   for(b=100;b>0;b--);
}


 //������
void main(void)
{
	uchar flag=0;
	LED1=1;
	LED2=0;
	while(1)
	{
		//�л�ģʽ
		if(KEY1==0)
		{
			delay_ms(20);
			if(KEY1==0)
			{
				flag=!flag;
			}	
			while(!KEY1);
		}
		//�Զ�ģʽ
		if(flag==0)
		{
			//�Զ����ֶ�ָʾ��
			LED1=1;
			LED2=0;
			if(YD==0)
			{
				JDQ1=0;
				JDQ2=1;	
				delay_ms(1000);
				JDQ1=1;
				JDQ2=0;	
				delay_ms(1000);
			}
			else
			{
				JDQ1=1;
				JDQ2=1;			
			}
		}
		//�ֶ�ģʽ
		else if(flag==1)
		{
			//�Զ����ֶ�ָʾ��
			LED1=0;
			LED2=1;
			//һ��
			if(KEY2==0&&KEY3==1)
			{
				JDQ1=0;
				JDQ2=1;	
				delay_ms(1000);
				JDQ1=1;
				JDQ2=0;	
				delay_ms(1000);
				JDQ1=1;
				JDQ2=1;
				delay_ms(1000);
			}
			//����
			if(KEY2==0&&KEY3==0)
			{
				JDQ1=0;
				JDQ2=1;	
				delay_ms(1000);
				JDQ1=1;
				JDQ2=0;	
				delay_ms(1000);			
			}
			//�ֶ��ر�ģ��
			if (KEY2==1&&KEY3==1)
			{
				JDQ1=1;
				JDQ2=1;
			}
			if (KEY2==1&&KEY3==0)
			{
				JDQ1=1;
				JDQ2=1;
			}
		}
	}
}