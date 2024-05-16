#ifndef trajectory
#define trajectory
#define arrayGlopal  (* char)logFormatted
	
void UART2_Tx(char Data);
char UART2_Rx(void);
void UART0_Tx(char Data);
char UART0_Rx(void);
void UART0_Tx_int(int Data);
void UART2_Tx_int(int Data);
float start_walking(float* trajectory_points);
void GPS_Read();


#endif
