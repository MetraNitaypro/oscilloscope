#ifndef __BT_MODULE_H
#define __BT_MODULE_H

#include "stdint.h"

//#include "MDR32Fx.h"
//#include "MDR32F9Qx_config.h"
//#include "MDR32F9Qx_dma.h"
//#include "MDR32F9Qx_uart.h"

#include "Memory.h"


//****************����������� ���������******************

// is enable inverse read emergency signal
#define BT_EMERGY_READ_INV 

// enable UART2
#define BT_USE_UART2

// enable check emergy line mode
//#define BT_CHECK_EMERGY_LINE


//�������� �����������

#ifdef ACDC
//#define BT_BAUDRATE             115200 
//#define BT_BAUDRATE             460800
//#define BT_BAUDRATE             230400
#define BT_BAUDRATE             921600  
//#define BT_BAUDRATE             460800 
#endif

#ifdef DCDC 
#define BT_BAUDRATE             921600
//#define BT_BAUDRATE             1000000  
#endif
//#define BT_BAUDRATE             115200
//#define BT_BAUDRATE             9600
//������� ������ ms
#define BT_CMD_TIMEOUT          7000    
// ����� ��������� ������
#define BT_HEAD_LEN             8       
//����� ������ ��������
#define BT_MAX_PAYLOD_LEN       0xFF       
//����� ������ ������
#define BT_BUF_RX_LEN           BT_HEAD_LEN       
//����� ������ ���������
#define BT_BUF_MES_LEN          64      
//��������� ������ �����������
#define BT_TASK_TX_PRIORITY     3       
//������� �������� � �������
#define BT_QUEUE_TIMEOUT        100     
//����� ������� ��������� TX 
#define BT_QUEUE_TX_LEN         50        
// ring buffer size (bytes)
#define BT_RING_BUF_SIZE        (BT_BUF_MES_LEN*3)
// waiting ack in Emergy state
#define BT_EMERGY_TIMEOUT         10000
//#define BT_REINIT_COUNT         3 

// Start symbol
#define BT_PT_START_SYMBOL      0x55     

// for 3-rd arg in crc8 func
// Must be not equal ZERO, else empty packet will pass CRC test!
#define BT_CRC_INIT ( 0x66 )       





// states 
typedef enum
{
  BT_STATE_STOP,
  BT_STATE_START,
  BT_STATE_PRESTART,
  BT_STATE_RESET,
  BT_STATE_PING,
  BT_STATE_ACCEPT,
  BT_STATE_LINKED,
  BT_STATE_EMERGY,
  BT_STATE_HARDFAULT
} BT_state_machine_e;


// Destanation 
typedef enum
{
  BT_ACDC_ADDR = 0,
  BT_DCDC_ADDR,
  BT_DCAC_ADDR,
  BT_REMOTE_ADDR,
  BT_DEST_COUNT
} BT_destAddr_e;


//-- MSG's HEADER
typedef struct
{
  uint8_t startByte;
  uint8_t cmdId; // DestId 2bit | cmdId 6bit
  uint8_t varId; // valId or payload's len
  uint8_t crc;
  uint32_t arg; // value for var or pointer for payload
} BT_msg_t;
//--





//-- UART Module
typedef struct
{
  
#ifdef BT_CHECK_EMERGY_LINE
  uint8_t emergy_set;
  uint8_t emergy_read; 
#endif // BT_CHECK_EMERGY_LINE
  
//  uint8_t txBuf[255];
  
//  MEM_ring_buf_t rxHeadersBuf;
  
//  MEM_ring_buf_t txHighPriBuf;
//  MEM_ring_buf_t txLowPriBuf;
  
//  DMA_ChannelInitTypeDef DMA_InitStrIf1_tx;
//  DMA_ChannelInitTypeDef DMA_InitStrIf1_rx;
//  DMA_CtrlDataInitTypeDef DMA_PriCtrlStrIf1_tx;
//  DMA_CtrlDataInitTypeDef DMA_PriCtrlStrIf1_rx;
  
//  uint64_t  lastRxTimestamp;
//  uint64_t  cmdTimeOutTimestamp;
//  uint8_t * p_rxHeadBufForSirq;
//  BT_msg_t * p_txHeadForPayload;
  
//  MDR_UART_TypeDef *  uart;
//  MDR_PORT_TypeDef * txrx_port;
//  MDR_PORT_TypeDef * stxrx_port;
  
  uint32_t errorsCount;
  
  uint16_t rxSirqRead;
  uint16_t rxSirqLoad;
  uint16_t rxSirqMaxLoad;
  
  uint16_t      tx_pin;
  uint16_t      rx_pin;
  
  uint16_t      stx_pin;
  uint16_t      srx_pin;
  
  uint8_t payloadRestSize;
  uint8_t dmaTxDone;
  uint8_t waitAck;
  uint8_t waitHead;
  uint8_t errors;
  
  // state of machine
  BT_state_machine_e state;
  
} BT_uartModule_t;

    

extern BT_uartModule_t uarts[2];





//-- List of CMD
typedef enum
{ 
  BT_CMD_SET_VAL = 0,
  BT_CMD_GET_VAL,
  BT_CMD_ACK,
  BT_CMD_STAT,
  BT_CMD_END_8BYTE_CTG,
  BT_CMD_SET_MEM,
  BT_CMD_GET_MEM,
  BT_CMD_BEGIN_RAW_CTG,
  BT_CMD_RAW_MES,
  BT_CMD_CALC_MES,
  BT_CMD_COUNT
} BT_cmd_id_e;
//--






typedef enum
{
  BT_ACK_SET = 0,
  BT_ACK_CMD,
} BT_ACK_CMD_ID;


typedef enum
{
  BT_STAT_MAIN_ACDC = 0,
  BT_STAT_ERROR_ACDC,
  BT_STAT_MAIN_DCDC,
  BT_STAT_ERROR_DCDC,
  BT_STAT_MAIN_DCAC,
  BT_STAT_ERROR_DCAC
} BT_stat_type_e;


typedef enum
{
  BT_CONSOL_DCAC_GET,
  BT_CONSOL_DCAC_SET
} BT_CONSOLE_ID;


#ifndef DCDC

typedef enum
{
  BT_BOOST_SWITCH_A = 1,
  BT_BOOST_SWITCH_B = 2,
  BT_BOOST_SWITCH_C = 4
} BT_boost_switch_dcac;

typedef enum
{
  BT_BOOST_SW_A_BIT_NUM = 0,
  BT_BOOST_SW_B_BIT_NUM,
  BT_BOOST_SW_C_BIT_NUM
} BT_boost_sw_dcac_bit_num;

#endif // !DCDC

#ifndef DCAC
typedef enum
{
  BT_BOOST_SWITCH_L = 1,
  BT_BOOST_SWITCH_R = 2
} BT_boost_switch_dcdc;

typedef enum
{
  BT_BOOST_SW_L_BIT_NUM = 0,
  BT_BOOST_SW_R_BIT_NUM
} BT_boost_sw_dcdc_bit_num;
#endif // !DCAC

//--------------------------------//
//**************************************************//



//***************PROTOTYPES*****************//

void BT_init( void ); //Init

void BT_uart_init_ports( BT_uartModule_t * const BT_uart );
void BT_uart_init( BT_uartModule_t * const BT_uart );

void BT_sendMsgHighPri(const BT_destAddr_e destAddr, const BT_cmd_id_e cmdId, uint8_t varId, uint32_t arg);
void BT_sendMsgLowPri(const uint8_t cmdId, uint8_t * const data, const uint16_t size);
void BT_sendCalcVals( void );
void BT_sendStatus( void );

void BT_updates( void );

void BT_readLowPriMsg( void );
void BT_readHighPriMsg( void );


uint8_t BT_getMsgLen(BT_msg_t* msg);

int BT_crcHead_check(BT_msg_t *const ptr);
int BT_crcPayload_check(uint8_t *const payload, const uint8_t size);



#ifdef ACDC
  #define BT_CURRENT_ADDR       (BT_ACDC_ADDR) 
#endif

#ifdef DCDC
  #define BT_CURRENT_ADDR       (BT_DCDC_ADDR) 
#endif

#ifdef DCAC
  #define BT_CURRENT_ADDR       (BT_DCAC_ADDR)  
#endif




#endif
