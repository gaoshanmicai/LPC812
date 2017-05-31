#include "LPC11xx.h"
#define LED1_ON  LPC_GPIO1->DATA &= ~(1<<1)
#define LED1_OFF LPC_GPIO1->DATA |= (1<<1)
#define LED2_ON  LPC_GPIO1->DATA &= ~(1<<2)
#define LED2_OFF LPC_GPIO1->DATA |= (1<<2)
#define LED3_ON  LPC_GPIO1->DATA &= ~(1<<6)
#define LED3_OFF LPC_GPIO1->DATA |= (1<<6)
#define LED4_ON  LPC_GPIO1->DATA &= ~(1<<7)
#define LED4_OFF LPC_GPIO1->DATA |= (1<<7)

void LED_ON(uint8_t val);

/***********************************/
/* �������ƣ���ʱ����              */
/***********************************/
void delay()
{
	uint16_t i,j;
	
	for(i=0;i<100;i++)
		for(j=0;j<20000;j++);
}

/***********************************/
/* �������ƣ�LED�Ƴ�ʼ��           */
/***********************************/
void led_init()
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // ʹ��IOCONʱ�� 

	LPC_IOCON->R_PIO1_1 &= ~0x07;	
	LPC_IOCON->R_PIO1_1 |= 0x01; //��P1.1������ΪGPIO
	LPC_IOCON->R_PIO1_2   &=  ~0x07; 
	LPC_IOCON->R_PIO1_2   |=  0x01; 
	LPC_IOCON->PIO1_6   &=  ~0x07; 
	LPC_IOCON->PIO1_6   |=  0x00; 
	LPC_IOCON->PIO1_7   &=  ~0x07; 
	LPC_IOCON->PIO1_7   |=  0x00; 
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); // ����IOCONʱ��
	

	LPC_GPIO1->DIR |= (1<<1); // ��P1.1����Ϊ�������
	LPC_GPIO1->DATA |= (1<<1); // ��P1.1����Ϊ�ߵ�ƽ
	LPC_GPIO1->DIR |= (1<<2); // ��P1.1����Ϊ�������
	LPC_GPIO1->DATA |= (1<<2); // ��P1.1����Ϊ�ߵ�ƽ
	LPC_GPIO1->DIR |= (1<<6); // ��P1.1����Ϊ�������
	LPC_GPIO1->DATA |= (1<<6); // ��P1.1����Ϊ�ߵ�ƽ
	LPC_GPIO1->DIR |= (1<<7); // ��P1.1����Ϊ�������
	LPC_GPIO1->DATA |= (1<<7); // ��P1.1����Ϊ�ߵ�ƽ
}
int main()
{
	//LED_Initialize();
	 uint8_t i;
	led_init();
	
	while(1)
	{
		delay();
		LED1_ON;
		LED2_OFF;
//		LED3_ON;
//		LED4_OFF ;
		delay();
		LED1_OFF;
		LED2_ON;
//		LED3_OFF;
//		LED4_ON;

	}
	return 0;
}
void LED_ON(uint8_t val)
{
  uint8_t value;
  if(value/1 !=0)
   LPC_GPIO1->DATA &= ~(1<<1);
  else
    LPC_GPIO1->DATA |= (1<<1);
   value>>1;
   if(value/1 !=0)
   LPC_GPIO1->DATA &= ~(1<<2);
  else
    LPC_GPIO1->DATA |= (1<<2);
	value>>1;
	  if(value/1 !=0)
   LPC_GPIO1->DATA &= ~(1<<6);
  else
    LPC_GPIO1->DATA |= (1<<6);
		value>>1;
	  if(value/1 !=0)
   LPC_GPIO1->DATA &= ~(1<<7);
  else
    LPC_GPIO1->DATA |= (1<<7);
}
