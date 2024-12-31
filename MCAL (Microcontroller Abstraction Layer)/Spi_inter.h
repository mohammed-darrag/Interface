 
 #ifndef SPI_INT_H_
 #define SPI_INT_H_
 
 #define Master 1
 #define slave 0
 
 #define  Mode  Master
 
 void spi_init(void);
 u8 spi_sendreceive(u8 data);
 u8 spi_receiveperiodic (u8*pdata);
 void spi_sendnoblock(u8 data);
 
 
 
 #endif