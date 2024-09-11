#include <REGX51.H>
#include "LCD.h"

sbit coin=P1^0;
sbit relay=P1^1;
int i;
void main()
{
	relay = 0;
	lcd_init();
	lcd_cmd(0x80);lcd_string("ATM battery charger");
	lcd_cmd(0xc0);lcd_string("charger With coin ");
	delay(2000);
	lcd_cmd(0x01);
	
	while(1)
	{
			lcd_cmd(0x80);lcd_string("Insert Rs:2 Coin...");
			
			if(coin == 0)
			{
				lcd_cmd(0x01);
				relay = 1;
				lcd_cmd(0x80);lcd_string("Charger On");
				lcd_cmd(0xc0);
				for(i = 0;i<16;i++)
				{
					lcd_data('*');
					delay(500);
				}
				relay = 0;
				lcd_cmd(0x01);lcd_string("Charger Off");delay(2000);
			}
	}
}
	