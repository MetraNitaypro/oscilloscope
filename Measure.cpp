#include "Measure.h"

//#include "arm_math.h"

//#include "math.h"
#include "string.h"
#include "stdlib.h"

#include "BT_Module.h"
//#include "Measure.h"
//#include "FixedPoint.h"

//#include "MeasureConfig.h"


//Библиотека
//#include "MDR32F9Qx_config.h"
//#include "MDR32F9Qx_board.h"
//#include "MDR32F9Qx_rst_clk.h"
//#include "MDR32F9Qx_port.h"
//#include "MDR32F9Qx_adc.h"
//#include "MDR32F9Qx_dma.h"
//#include "MDR32F9Qx_it.h"
//#include "SoftIRQ.h"
//#include "Memory.h"


//*************Константы********************************************************




//*************Переменные*******************************************************

//DMA структуры



//Кольцевой буфер измерений
//MEM_ring_buf_t MS_adcRingBuf;

//Глобальные переменные

//MS_cfg_t MS_cfgs[MS_COUNT_READ_CH];

//float MS_calcVals[MS_COUNT_READ_CH];

//MS_calcValBuf_t MS_valBuf[MS_COUNT_READ_CH]; //Буфер измеряемых значений


uint16_t rawDataTranSize;


//*************Прототипы********************************************************

//ADC инициализация
static void MS_adcInit(void);
//DMA init
static void MS_dmaInit( void );

//----------------------------------------------------------------------------------------------------------


//static void allocBufMem(const MS_measureId_e valId)
//{
//  // alloc mem for val buffer
////  MS_valBuf[valId].valBuf = MEM_alloc(&staticAlloc, (windowsSizes[valId] * sizeof(int32_t)));
////  //p_free_mem += windowsSizes[valId] * sizeof(int32_t);
////  MS_cfgs[valId].koef = 0.30273f;
////  MS_cfgs[valId].dtf = 0.002173;
////  MS_cfgs[valId].offset = -2048*4;
////  MS_cfgs[valId].avgSize = 4;
////  MS_cfgs[valId].windowSize = 32;
//  //MS_cfgs[valId].fracPos = 4;

//}

//---------------------------------------//



//Инициализация


//static void MS_addValueToBuf(const uint8_t id)
//{
//  MS_calcValBuf_t * const  valBuf = &MS_valBuf[id];
//  //const uint16_t value = MS_thinData[id];
//  const uint8_t windowPos = valBuf->windowPos;

//  //AVG
//  if ((valBuf->calcFlag) & (1 << MS_CALC_FLAG_AVG))
//  {
//    int32_t * const buf = (int32_t*)valBuf->valBuf;
//    //valBuf->sumWin -= valBuf->valBuf[measureBufPos];
//    valBuf->sumWin -= buf[windowPos];
//    buf[windowPos] = valBuf->accumulator;
//    //valBuf->valBuf[measureBufPos] = value;
//    //valBuf->sumWin += valBuf->valBuf[measureBufPos];
//    valBuf->sumWin += buf[windowPos];
//  }

//  //RMS
//  if ((valBuf->calcFlag) & (1 << MS_CALC_FLAG_RMS))
//  {
////    if (id == 8)
////    {
////      tstBuf[tbi] = value/4;
////      ++tbi;
////      if (tbi == 320)
////      {
////        tbi = 0;
////      }
////    }
//    uint32_t * const buf = (uint32_t*)valBuf->valBuf;
////    if (id == 8)
////    //for (uint8_t i = 0; i < 40; ++i)
////    {
////      //float32_t tmp2 = (float)((uint32_t*)MS_valBuf[measureID].valBuf)[i];
////      //arm_sqrt_f32(tmp2, &tmp2);
////      //tmp2 /= 4.0f;
////      tbuf2[windowPos] = (int32_t)(value/4);
////    }
//    valBuf->sumSqr -= buf[windowPos];
//    buf[windowPos] = (uint32_t)valBuf->accumulator*valBuf->accumulator;
////    uint32_t tmp = buf[windowPos];
////    if (tmp)
////      asm("nop");
//    valBuf->sumSqr += buf[windowPos];

//  }

//  //Кольцевой счетчик буфера MS_valBuf
//  valBuf->windowPos++;
//  if (valBuf->windowPos == MS_cfgs[id].windowSize)
//  {
//    valBuf->windowPos = 0;
//  }

//}
////----------------------------------------------------------------------------------------------------------
////Calc avg
//static void MS_calcAvg(const MS_measureId_e measureID)
//{
//  if (MS_valBuf[measureID].calcFlag)
//  {
//#ifdef USE_FIXED_POINT
//    MS_calcVals[measureID] = MS_valBuf[measureID].avg;
//#else
//    //MS_valBuf[measureID].avg = ((float)MS_valBuf[measureID].sumWin/windowsSizes[measureID])*MS_correctVar[measureID].koef; //Относительное значение
//#endif
//  }
//}
////----------------------------------------------------------------------------------------------------------
////Calc Rms
//static volatile float tRms;

//static void MS_calcRms(const MS_measureId_e measureID)
//{
//  if (MS_valBuf[measureID].calcFlag)
//  {
//#ifdef USE_FIXED_POINT

//    float32_t tmp = (float)MS_valBuf[measureID].sumSqr * MS_cfgs[measureID].dtf;//0.0015625f;/// (1 << MS_valBuf[measureID].fracPos);
//    //tmp /= 40.0f;
//    arm_sqrt_f32(tmp, &tmp);

//    MS_valBuf[measureID].rms = (uint32_t)(tmp*MS_cfgs[measureID].koef);//(tmp * (1 << MS_valBuf[measureID].fracPos));
//    MS_calcVals[measureID] = MS_valBuf[measureID].rms;
//#else
//    //MS_valBuf[measureID].rms = sqrt((float)MS_valBuf[measureID].sumSqr/MS_cfgs[measureID].windSize)*MS_cfgs[measureID].koef; //Относительное значение
//#endif

//  }
//}
////----------------------------------------------------------------------------------------------------------
////Calc vpp
//static void MS_calcVpp(const MS_measureId_e measureID)
//{

//}
////----------------------------------------------------------------------------------------------------------
////Calc Disp
//static void MS_calcDisp(const MS_measureId_e measureID)
//{
//#ifdef USE_FIXED_POINT
//  //int32_t d = FDIV(INTTOFIX( MS_valBuf[measureID].sumSqr - MS_valBuf[measureID].sumWin*MS_valBuf[measureID].sumWin/windowsSizes[measureID]), INTTOFIX(windowsSizes[measureID]));
//  //MS_valBuf[measureID].dispersion = FSQRT(d);
//#else
//  float d = (float)( MS_valBuf[measureID].sumSqr - MS_valBuf[measureID].sumWin*MS_valBuf[measureID].sumWin/windowsSizes[measureID] ) / windowsSizes[measureID];
//  MS_valBuf[measureID].dispersion = sqrt( d );
//#endif
//}
////----------------------------------------------------------------------------------------------------------
////Measure calc value
//static void MS_calcValue(const MS_measureId_e measureID)
//{
//  //Calc avg
//  if ((MS_valBuf[measureID].calcFlag) & (1 << MS_CALC_FLAG_AVG))
//  {
//    MS_calcAvg(measureID);
//  }

//  //Calc vpp
//  if ((MS_valBuf[measureID].calcFlag) & (1 << MS_CALC_FLAG_VPP))
//  {
//    ///MS_calcVpp(measureID);
//  }

//  //Calc RMS
//  if ((MS_valBuf[measureID].calcFlag) & (1 << MS_CALC_FLAG_RMS))
//  {
//    MS_calcRms(measureID);
//  }

//  //Calc DISP
//  if ((MS_valBuf[measureID].calcFlag) & (1 << MS_CALC_FLAG_DISP))
//  {
//    MS_calcDisp(measureID);
//  }
//}
////----------------------------------------------------------------------------------------------------------







