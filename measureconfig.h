#ifndef MEASURECONFIG_H
#define MEASURECONFIG_H


#include "stdint.h"

#define         MS_ADC_CHNNELS_COUNT    ( 16 )


//==================================ACDC========================//





#ifdef ACDC


typedef enum
{
  MS_ID_SDI = 0,
  MS_ID_SDU,
  MS_ID_SAUA,
  MS_ID_SAUB,
  MS_ID_SAUC,
  MS_ID_TEMP1,
  MS_ID_TEMP2,
  MS_COUNT_READ_CH,
  MS_ADC_DISABLE_CHN
}
MS_measureId_e;


// MEM SIZE FOR WINDOWS
#define MS_WINDOWS_MEM_SIZE     (((MS_CALC_WINDOW)*(MS_COUNT_READ_CH))*sizeof(int32_t))


#endif //ACDC


//==================================DCAC========================//


#ifdef DCAC

typedef enum
{
  MS_ID_TEMP,
  MS_ID_SAUA,
  MS_ID_SAUB,
  MS_ID_SAUC,
  MS_ID_SLAIA,
  MS_ID_SLAIB,
  MS_ID_SLAIC,
  MS_ID_SBDUA,
  MS_ID_SBDUB,
  MS_ID_SBDUC,
  MS_ID_SSAIL,
  MS_ID_SSAIR,
  MS_ID_SRAIA,
  MS_ID_SRAIB,
  MS_ID_SRAIC,
  MS_COUNT_READ_CH,
  MS_ADC_DISABLE_CHN
}
MS_measureId_e;


// MEM SIZE FOR WINDOWS
#define MS_WINDOWS_MEM_SIZE     (((MS_CALC_WINDOW)*(MS_COUNT_READ_CH))*sizeof(int32_t))

#endif //DCAC


//==================================DCDC========================//


#ifdef DCDC

typedef enum
{
  MS_ID_SBDU1 = 0,
  MS_ID_SBDU2,
  MS_ID_SODU1,
  MS_ID_SODU2,
  MS_ID_SODC1,
  MS_ID_SODC2,
  MS_ID_TEMP_B1,
  MS_ID_TEMP_HB1,
  MS_ID_TEMP_B2,
  MS_ID_TEMP_HB2,
  MS_COUNT_READ_CH,
  MS_ADC_DISABLE_CHN
}
MS_measureId_e;


// MEM SIZE FOR WINDOWS
#define MS_WINDOWS_MEM_SIZE     (((MS_CALC_WINDOW)*(MS_COUNT_READ_CH))*sizeof(int32_t))
//#define MS_WINDOWS_MEM_SIZE   ((238+40*14)*sizeof(uint32_t))


#endif //DCDC


#define MS_ADD_BUF      (((MS_COUNT_READ_CH*MS_DMA_PACK_SIZE) % 8) ? 8-((MS_COUNT_READ_CH*MS_DMA_PACK_SIZE) % 8) : 0)



// adc channel number to measure ID
//extern const MS_measureId_e adcIndexMap[MS_ADC_CHNNELS_COUNT];
//extern const uint8_t windowsSizes[MS_COUNT_READ_CH];



void intCalcFlags( void );



#endif // MEASURECONFIG_H
