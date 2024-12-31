#include "STDtypes.h"
#include "MEMMAP.h"
#include  "UTILS.h"
#include "SPI_inter.h"

void spi_init(void)
{
   SET_BIT(SPCR,SPE);
   #if Mode==Master
   SET_BIT(SPCR,MSTR);
   #else
   CLR_BIT (SPCR,MSTR);
 
}

u8 spi_sendreceive(u8 data)
{
	
  SPDR=data;
  while (!GET_BIT(SPSR,SPIF));
  return SPDR;
 
}

void spi_sendnoblock(u8 data)
{
	SPDR=data;	
}

u8 spi_receiveperiodic (u8*pdata)
{
	if (GET_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1
	}
	else
	{
		return 0;

	}
}