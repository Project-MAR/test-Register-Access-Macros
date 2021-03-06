#include <stdio.h>
#include <stdlib.h>

#define U32 unsigned long

typedef struct WDT_REGS_TAG
{
	volatile U32 CR;
	volatile U32 MR;
	volatile U32 SR;
}WDT_REGS;

// pointer to physical address
#define NAND_ADDR    *((volatile U32 *)(&WDT_REGISTER[3]))

// struct that is place in the same address with the target memory
#define WDT          ((volatile WDT_REGS *) (&WDT_REGISTER))

// Target memory
volatile U32 WDT_REGISTER[4] = {0x000001FF, 0xFFFFFFFF, 0x00001003, 0xF0F0F0F0};


int main(void)
{
/*
	  NAND_ADDR     *((volatile U32 *)(&WDT_REGISTER[3]))
	  is similar to *(&WDT_REGISTER[3]) in which it point to the address of WDT_REGISTER[3]
	  *((volatile U32 *)(&WDT_REGISTER[3])) is same as *(&WDT_REGISTER[3])
	  but include type casting (volatile U32 *)
*/

	NAND_ADDR = 0x0000000F;
	printf("pointer to register      = 0x%08x\n",NAND_ADDR);

	*(&WDT_REGISTER[3]) = 0x000000FF;
	printf("Value in WDT_REGISTER[3] = 0x%08x\n",*(&WDT_REGISTER[3]));

	printf("\n");

	int i;
	for (i=0; i<4; i++)
		printf("Value in U32 WDT_REGISTER[%d] = 0x%08x, Address = 0x%08x\n",i ,WDT_REGISTER[i], &WDT_REGISTER[i]);

	printf("CR: 0x%08x\n", WDT->CR);
	printf("MR: 0x%08x\n", WDT->MR);
	printf("SR: 0x%08x\n\n", WDT->SR);

	WDT->CR = 0xA5000FF0;
	WDT->MR = 0xFFF000FF;
	WDT->SR = 0xF0000FFF;
	printf("WDT->CR = 0xA5000FF0\n");
	printf("WDT->MR = 0xFFF000FF\n");
	printf("WDT->SR = 0xF0000FFF\n");

	printf("\nValue: 0x%08x Address: 0x%08x\n",WDT_REGISTER[0], &WDT_REGISTER[0]);
	printf("CR: 0x%08x\n", WDT->CR);
	printf("MR: 0x%08x\n", WDT->MR);
	printf("SR: 0x%08x\n", WDT->SR);

	printf("\nValue: 0x%08x Address: 0x%08x\n",WDT_REGISTER, &WDT_REGISTER);

	return EXIT_SUCCESS;
}
