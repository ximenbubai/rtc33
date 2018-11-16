/*******************************************************************************
*           �������Ƴ���      								                   *
*  ���ӷ�����JP10��P2�� �� JP1 ��LED�ƣ����ӣ�   							   *
*            JP11��P0�� �� JP5�������ӿڣ�����                                 *
*         ��ʼ����P1LED                                  		               *
*         ��P01 LED������һλ                                                  *
*         ��P00 LED������һλ                                         	       *
*	 ����������ťLED�᲻ͣ�����ƻ�����										   *
*******************************************************************************/
#include <reg51.h>
#include <intrins.h>
unsigned char scan_key();
void proc_key(unsigned char key_v);
void delayms(unsigned char ms);
sbit	K1 = P0^0;	//��Ӧ��ťK1
sbit	K2 = P0^1;	//��Ӧ��ťK2
main()
{
	unsigned char key_s,key_v;
	key_v = 0x03;
	P2 = 0xfe;
	while(1)
	{
		key_s = scan_key();
		if(key_s != key_v)
		{
			delayms(10);
			key_s = scan_key();
			if(key_s != key_v)
			{	
				key_v = key_s;
				proc_key(key_v);					
			}
		}
	}	
}
unsigned char scan_key()
{
	unsigned char key_s;
	key_s = 0x00;
	key_s |= K2;
	key_s <<= 1;
	key_s |= K1;
	return key_s;		
}
void proc_key(unsigned char key_v)
{
	if((key_v & 0x01) == 0)
	{
		P2 = _cror_(P2,1);
	}
	else if((key_v & 0x02) == 0)
	{
		P2 = _crol_(P2, 1);
	}
}
void delayms(unsigned char ms)		// ��ʱ�ӳ���
{						
	unsigned char i;
	while(ms--)
	{
		for(i = 0; i < 120; i++);
	}
}
