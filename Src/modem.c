#include "modem.h"

extern UART_HandleTypeDef huart2;
static RadioEvents_t RadioEvents;
TimerEvent_t timer_DMA_RX;

uint8_t UartTxBuffer[64] = {0};

uint8_t FIFO_Buffer[BUFFER_SOCKETS][BUFFER_SIZE]={0};
uint8_t BufferSize;
uint8_t FIFO_IN = 0, FIFO_OUT = 0, FIFO_COUNT = 0;

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	if(UartHandle->Instance == huart2.Instance) {
		;
	}
}

/* Inicjalizacja transmisji oraz odpowiednich Callbacków */
void Modem_Init( void )
{
	RadioEvents.TxDone = OnTxDone;
	RadioEvents.RxDone = OnRxDone;
	RadioEvents.TxTimeout = OnTxTimeout;
	RadioEvents.RxTimeout = OnRxTimeout;
	RadioEvents.RxError = OnRxError;

	Radio.Init( &RadioEvents );
	Radio.SetChannel( RF_FREQUENCY );
	Radio.SetTxConfig( MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
	                               LORA_SPREADING_FACTOR, LORA_CODINGRATE,
	                               LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
	                               true, 1, 255, LORA_IQ_INVERSION_ON, 3000000 );
	Radio.SetRxConfig( MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
	                               LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH,
	                               LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
	                               0, true, 1, 10, LORA_IQ_INVERSION_ON, true );
	Radio.Rx(0);
}

void Modem_Send( void )
{
	if((IsFifoEmpty() == false) && (huart2.gState == HAL_UART_STATE_READY))
	{
		PushFifo(UartTxBuffer);
		HAL_UART_Transmit_IT(&huart2, UartTxBuffer, 64);

	}
}


void OnTxDone( void )
{
	Radio.Standby( );
}

void OnRxDone( uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr )
{
    BufferSize = size;
    PutFifo(payload);
}

void OnTxTimeout( void )
{
	Radio.Standby( );
}

void OnRxTimeout( void )
{
	Radio.Standby( );
}

void OnRxError( void )
{
	Radio.Standby( );
}


uint8_t IsFifoFull( void )
{
	if(FIFO_OUT == ((FIFO_IN + 1) % BUFFER_SOCKETS))
		return true;
	else
		return false;
}

uint8_t IsFifoEmpty( void )
{
	if(FIFO_IN == FIFO_OUT)
		return true;
	else
		return false;
}
void PushFifo( uint8_t* data )
{
	if(FIFO_IN != FIFO_OUT) {
		memcpy(data, FIFO_Buffer[FIFO_OUT], 64);
		FIFO_OUT = (FIFO_OUT + 1) % BUFFER_SOCKETS;
		FIFO_COUNT--;
	}
}

void PutFifo( uint8_t* data )
{
	if(FIFO_OUT != ((FIFO_IN + 1) % BUFFER_SOCKETS)) {
		memcpy(FIFO_Buffer[FIFO_IN], data, 64);
		FIFO_IN = (FIFO_IN + 1) % BUFFER_SOCKETS;
		FIFO_COUNT++;
	}
}



