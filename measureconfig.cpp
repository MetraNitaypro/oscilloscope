#include "measureconfig.h"

#include "measureconfig.h"
#include "Measure.h"
#include "stdint.h"



//==================================ACDC========================//

#ifdef ACDC


//// adc channel number to measure ID
//const MS_measureId_e adcIndexMap[MS_ADC_CHNNELS_COUNT] =
//{
//  MS_ID_SDI,
//  MS_ID_SDU,
//  MS_ID_SAUA,
//  MS_ID_SAUB,
//  MS_ID_SAUC,
//  MS_ID_TEMP1,
//  MS_ID_TEMP2,
//
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN
//};


const uint8_t windowsSizes[MS_COUNT_READ_CH] =
{
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW
};


// MEM SIZE FOR WINDOWS
#define MS_WINDOWS_MEM_SIZE     (((MS_CALC_WINDOW)*(MS_COUNT_READ_CH))*sizeof(int32_t))


#endif //ACDC


//==================================DCAC========================//


#ifdef DCAC


//// adc channel number to measure ID
//const MS_measureId_e adcIndexMap[MS_ADC_CHNNELS_COUNT] =
//{
//  MS_ID_TEMP,
//  MS_ID_SAUA,
//  MS_ID_SAUB,
//  MS_ID_SAUC,
//  MS_ID_SLAIA,
//  MS_ID_SLAIB,
//  MS_ID_SLAIC,
//  MS_ID_SBDUA,
//  MS_ID_SBDUB,
//  MS_ID_SBDUC,
//  MS_ID_SSAIL,
//  MS_ID_SSAIR,
//  MS_ID_SRAIA,
//  MS_ID_SRAIB,
//  MS_ID_SRAIC,
//
//  MS_ADC_DISABLE_CHN
//};


const uint8_t windowsSizes[MS_COUNT_READ_CH] =
{
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW
};


// MEM SIZE FOR WINDOWS
#define MS_WINDOWS_MEM_SIZE     (((MS_CALC_WINDOW)*(MS_COUNT_READ_CH))*sizeof(int32_t))

#endif //DCAC


//==================================DCDC========================//


#ifdef DCDC


//// adc channel number to measure ID
//const MS_measureId_e adcIndexMap[MS_ADC_CHNNELS_COUNT] =
//{
//  MS_ID_SBDU1,
//  MS_ID_SBDU2,
//  MS_ID_SODU1,
//  MS_ID_SODU2,
//  MS_ID_TEMP_B1,
//  MS_ID_TEMP_HB1,
//  MS_ID_TEMP_B2,
//  MS_ID_TEMP_HB2,
//
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN,
//  MS_ADC_DISABLE_CHN
//};


const uint8_t windowsSizes[MS_COUNT_READ_CH] =
{
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW,
  MS_CALC_WINDOW
};


// MEM SIZE FOR WINDOWS
//(((MS_CALC_WINDOW)*(MS_COUNT_READ_CH))*sizeof(int32_t))


#endif //DCDC









//----------------Init flags----------------//


//===========================ACDC==================//
#ifdef ACDC

inline void intCalcFlags( void )
{
   //Установка флагов вычисления
  MS_valBuf[MS_ID_SAUA].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SAUB].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SAUC].calcFlag = (1 << MS_CALC_FLAG_RMS);
//  MS_valBuf[MS_ID_SAIA].calcFlag = (1 << MS_CALC_FLAG_RMS);
//  MS_valBuf[MS_ID_SAIB].calcFlag = (1 << MS_CALC_FLAG_RMS);
//  MS_valBuf[MS_ID_SAIC].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SDI].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_SDU].calcFlag = (1 << MS_CALC_FLAG_AVG);
//  MS_valBuf[MS_ID_REF15].calcFlag = (1 << MS_CALC_FLAG_AVG);
}

#endif // ACDC


//============================DCAC========================//

#ifdef DCAC

inline void intCalcFlags( void )
{
  //Установка флагов вычисления
  MS_valBuf[MS_ID_SAUA].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SAUB].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SAUC].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SLAIA].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SLAIB].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SLAIC].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SRAIA].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SRAIB].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SRAIC].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SSAIL].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SSAIR].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SBDUA].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_SBDUB].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_SBDUC].calcFlag = (1 << MS_CALC_FLAG_AVG);
}

#endif // DCAC



//============================DCDC========================//

#ifdef DCDC

inline void intCalcFlags( void )
{
//  //Установка флагов вычисления
  MS_valBuf[MS_ID_SBDU2].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_SBDU1].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_SODU2].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_SODU1].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_SODC1].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_SODC2].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_TEMP_B1].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_TEMP_HB1].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_TEMP_B2].calcFlag = (1 << MS_CALC_FLAG_RMS);
  MS_valBuf[MS_ID_TEMP_HB2].calcFlag = (1 << MS_CALC_FLAG_AVG);
  MS_valBuf[MS_ID_TEMP_HB2].calcFlag = (1 << MS_CALC_FLAG_AVG);
  //MS_valBuf[MS_ID_RES2].calcFlag = (1 << MS_CALC_FLAG_RMS);
}

#endif // DCDC

//--------------------------------------------//

