#include "reg52.h"

//宏定义
#define uchar unsigned char
#define uint  unsigned int

//按键定义
sbit KEY1= P2^0;
sbit KEY2= P2^1;
sbit KEY3= P2^2;

//雨滴传感器定义
sbit YD= P2^3;

//数码管定义
sbit LED1= P0^0;
sbit LED2= P0^3;

//继电器定义
sbit JDQ1= P0^1;
sbit JDQ2= P0^2;

//延时函数
void delay_ms(uint z)			  
{
  uint a,b;
  for(a=z;a>0;a--)
   for(b=100;b>0;b--);
}


 //主函数
void main(void)
{
	uchar flag=0;
	LED1=1;
	LED2=0;
	while(1)
	{
		//切换模式
		if(KEY1==0)
		{
			delay_ms(20);
			if(KEY1==0)
			{
				flag=!flag;
			}	
			while(!KEY1);
		}
		//自动模式
		if(flag==0)
		{
			//自动、手动指示灯
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
		//手动模式
		else if(flag==1)
		{
			//自动、手动指示灯
			LED1=0;
			LED2=1;
			//一档
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
			//二档
			if(KEY2==0&&KEY3==0)
			{
				JDQ1=0;
				JDQ2=1;	
				delay_ms(1000);
				JDQ1=1;
				JDQ2=0;	
				delay_ms(1000);			
			}
			//手动关闭模块
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