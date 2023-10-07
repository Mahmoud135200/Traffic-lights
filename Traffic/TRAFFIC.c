#include "LIB/STD_Types.h"
#include"LIB/BIT_Math.h"
#include "MCAL/DIO/DIO.h"
#include<avr/io.h>
#include<util/delay.h>

#define ZERO  0b00111111
#define ONE   0b00000110
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111

u8 numbers[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
void Seven_Segment(u8 number);
int main(){
	DIO_voidSetPortDirection(DIO_PORTA,0b11111111);
	DIO_voidSetPortDirection(DIO_PORTB,0b11111111);
	DIO_voidSetPortDirection(DIO_PORTC,0b11111111);


	while(1){
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
		 Seven_Segment(10);

		 DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
		Seven_Segment(3);

		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);
		 Seven_Segment(10);


	}



	return 0;
}


void Seven_Segment(u8 number){

	u8 num1,num2;
	num1=number%10;
	num2=number/10;
	s8 i,j;
	for(i=num2;i>=0;i--){
		for(j=num1;j>=0;j--){
		DIO_voidSetPortValue(DIO_PORTA,numbers[i]);
		DIO_voidSetPortValue(DIO_PORTB,numbers[j]);
		_delay_ms(900);
		}
		num1=9;
	}

}
