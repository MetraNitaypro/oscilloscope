#ifndef MEASURE_H
#define MEASURE_H

#include <QObject>

//#include "deviceDefs.h"
#include "stdbool.h"
#include "measureconfig.h"

//#include "MDR32F9Qx_config.h"

//#include "devCtrl.h"




//********************************Настройки*************************************

#define MS_CHECK_OUT_OF_MEMORY

#define         MS_DMA_PACK_SIZE        ( 4 )

#define MS_REF_VOLTAGE                  3300    //Напряжение референтное mV
#define MS_T25_RESIST                   15000   //Сопротивление при T=25C
#define MS_UP_RESIST                    5000    //Сопротивление верхнего резистора делителя
#define MS_CALC_WINDOW		        128      //Длина окна измерения
#define MS_CALC_STEP		        4       //Шаг расчета
#define MS_CALC_SHR_N                   3       // log2(MS_CALC_STEP)
#define MS_CALC_T_WINDOW		20      //Длина окна расчета среднего значения температуры



//********************************Приоритеты задач******************************

#define MS_MEASURE_PRIORITY             3       //Приоритет задачи обработки

//********************************Коррекция*************************************

//--------------------Дефолтные значения

#ifdef DCDC

//Если запян референт на 3.3В
#if MS_REF_VOLTAGE==3300

//Датчики напряжения буста
#define MS_DEFCOR_KOEF_SBDU1		1.0f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDU1		0      //Смещение
#define MS_DEFCOR_KOEF_SBDU2		1.0f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDU2		0      //Смещение
//Датчики напряжения
#define MS_DEFCOR_KOEF_SODU1		0.0085f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SODU1		0      //Смещение
#define MS_DEFCOR_KOEF_SODU2		0.0085f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SODU2		0      //Смещение
//Датчики тока
#define MS_DEFCOR_KOEF_SLODI1		0.0435f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLODI1		0      //Смещение
#define MS_DEFCOR_KOEF_SLODI2		0.0435f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLODI2		0      //Смещение
#define MS_DEFCOR_KOEF_SRODI1		0.34f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRODI1		0      //Смещение
#define MS_DEFCOR_KOEF_SRODI2		0.34f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRODI2		0      //Смещение
//Датчики температуры
#define MS_DEFCOR_KOEF_T		0.000865f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_T		0      //Смещение
#define MS_TKS                          -0.025f   //ТКС

#endif //3.3В

//Если запян референт на 3.0В
#if MS_REF_VOLTAGE==3000

//Датчики напряжения буста
#define MS_DEFCOR_KOEF_SBDU1		0.656f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDU1		0      //Смещение
#define MS_DEFCOR_KOEF_SBDU2		0.656f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDU2		0      //Смещение
//Датчики напряжения
#define MS_DEFCOR_KOEF_SODU1		0.1f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SODU1		0      //Смещение
#define MS_DEFCOR_KOEF_SODU2		0.1f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SODU2		0      //Смещение
//Датчики тока
#define MS_DEFCOR_KOEF_SLODI1		0.0435f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLODI1		0      //Смещение
#define MS_DEFCOR_KOEF_SLODI2		0.0435f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLODI2		0      //Смещение
#define MS_DEFCOR_KOEF_SRODI1		0.0435f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRODI1		0      //Смещение
#define MS_DEFCOR_KOEF_SRODI2		0.0435f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRODI2		0      //Смещение
//Датчики температуры
#define MS_DEFCOR_KOEF_T		0.000865f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_T		0      //Смещение
#define MS_TKS                          -0.05f   //ТКС

#endif //3.0В
#endif //DCDC

#ifdef ACDC

//Если запян референт на 3.3В
#if MS_REF_VOLTAGE==3300

//Трансформаторы напряжения
#define MS_DEFCOR_KOEF_SAUA		0.207018f   //Линеный коэффициент 120 Ом подрузка
#define MS_DEFCOR_OFFSET_SAUA		-1855    //Смещение
#define MS_DEFCOR_KOEF_SAUB		0.207018f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUB		-1855    //Смещение
#define MS_DEFCOR_KOEF_SAUC		0.207018f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUC		-1855    //Смещение
//Датчики тока
#define MS_DEFCOR_KOEF_SAIA		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAIA		0       //Смещение
#define MS_DEFCOR_KOEF_SAIB		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAIB		0       //Смещение
#define MS_DEFCOR_KOEF_SAIC		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAIC		0       //Смещение
//Датчик постоянного тока
#define MS_DEFCOR_KOEF_SDI		1.0f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SDI		0       //Смещение
//Датчик постоянного напряжения
#define  MS_DEFCOR_KOEF_SDU		0.1515f   //Линеный коэффициент номер 3
#define MS_DEFCOR_OFFSET_SDU		0       //Смещение
//Датчики температуры
#define MS_DEFCOR_KOEF_T		0.00083f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_T		0      //Смещение
#define MS_TKS                          -0.025f   //ТКС

#endif //3.3В

//Если запян референт на 3.0В
#if MS_REF_VOLTAGE==3000

//Трансформаторы напряжения
#define MS_DEFCOR_KOEF_SAUA		0.207018f   //Линеный коэффициент 120 Ом подрузка
#define MS_DEFCOR_OFFSET_SAUA		-1855    //Смещение
#define MS_DEFCOR_KOEF_SAUB		0.207018f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUB		-1855    //Смещение
#define MS_DEFCOR_KOEF_SAUC		0.207018f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUC		-1855    //Смещение
//Датчики тока
#define MS_DEFCOR_KOEF_SAIA		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAIA		0       //Смещение
#define MS_DEFCOR_KOEF_SAIB		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAIB		0       //Смещение
#define MS_DEFCOR_KOEF_SAIC		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAIC		0       //Смещение
//Датчик постоянного тока
#define MS_DEFCOR_KOEF_SDI		1.0f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SDI		0       //Смещение
//Датчик постоянного напряжения
#define MS_DEFCOR_KOEF_SDU		0.1515f   //Линеный коэффициент номер 3
#define MS_DEFCOR_OFFSET_SDU		0       //Смещение
//Датчики температуры
#define MS_DEFCOR_KOEF_T		0.00083f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_T		0      //Смещение
#define MS_TKS                          -0.025f   //ТКС

#endif //3.0В
#endif //ACDC

//#ifdef DCAC

//Если запян референт на 3.3В
#if MS_REF_VOLTAGE==3300

//Трансформаторы напряжения
#define MS_DEFCOR_KOEF_SAUA		0.241f   //Линеный коэффициент 120 Ом подрузка
#define MS_DEFCOR_OFFSET_SAUA		-2040    //Смещение
#define MS_DEFCOR_KOEF_SAUB		0.242f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUB		-2050    //Смещение
#define MS_DEFCOR_KOEF_SAUC		0.239f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUC		 -2050    //Смещение

//Датчики тока
#define MS_DEFCOR_KOEF_SLAIA		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLAIA		-1857     //Смещение
#define MS_DEFCOR_KOEF_SLAIB		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLAIB		-1857     //Смещение
#define MS_DEFCOR_KOEF_SLAIC		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLAIC		-1857     //Смещение
#define MS_DEFCOR_KOEF_SRAIA		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRAIA		-1857     //Смещение
#define MS_DEFCOR_KOEF_SRAIB		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRAIB		-1857     //Смещение
#define MS_DEFCOR_KOEF_SRAIC		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRAIC		-1857     //Смещение
#define MS_DEFCOR_KOEF_SSAIL		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SSAIL		-1857     //Смещение
#define MS_DEFCOR_KOEF_SSAIR		0.220f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SSAIR		0         //Смещение

//Датчики напряжения буста
#define MS_DEFCOR_KOEF_SBDUA		0.37f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDUA		0      //Смещение
#define MS_DEFCOR_KOEF_SBDUB		0.37f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDUB		0      //Смещение
#define MS_DEFCOR_KOEF_SBDUC		0.37f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDUC		0      //Смещение

//#endif //3.3В

//Если запян референт на 3.0В
#if MS_REF_VOLTAGE==3000

//Трансформаторы напряжения
#define MS_DEFCOR_KOEF_SAUA		0.237f   //Линеный коэффициент 120 Ом подрузка
#define MS_DEFCOR_OFFSET_SAUA		-2040    //Смещение
#define MS_DEFCOR_KOEF_SAUB		0.22f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUB		-1855    //Смещение
#define MS_DEFCOR_KOEF_SAUC		0.22f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SAUC		-1855    //Смещение

//Датчики тока
#define MS_DEFCOR_KOEF_SLAIA		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLAIA		0        //Смещение
#define MS_DEFCOR_KOEF_SLAIB		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLAIB		0        //Смещение
#define MS_DEFCOR_KOEF_SLAIC		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SLAIC		0        //Смещение
#define MS_DEFCOR_KOEF_SRAIA		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRAIA		0        //Смещение
#define MS_DEFCOR_KOEF_SRAIB		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRAIB		0        //Смещение
#define MS_DEFCOR_KOEF_SRAIC		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SRAIC		0        //Смещение
#define MS_DEFCOR_KOEF_SSAIL		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SSAIL		0        //Смещение
#define MS_DEFCOR_KOEF_SSAIR		1.0f      //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SSAIR		0        //Смещение

//Датчики напряжения буста
#define MS_DEFCOR_KOEF_SBDUA		0.37f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDUA		0      //Смещение
#define MS_DEFCOR_KOEF_SBDUB		0.37f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDUB		0      //Смещение
#define MS_DEFCOR_KOEF_SBDUC		0.37f   //Линеный коэффициент
#define MS_DEFCOR_OFFSET_SBDUC		0      //Смещение

#endif //3.0В
#endif //DCAC

////Коррекция по каналам
//typedef struct
//{
//#ifdef USE_FIXED_POINT
//  float koef;           // Коэфициент линейный
//  int32_t conversion;     // Коэффициент для конверсии
//  uint32_t fracPos;      // bits count for fraction part
//#else
//  float koef;           //Коэфициент линейный
//  float conversion;     //Коэффициент для конверсии
//#endif // USE_FIXED_POINT
//  int16_t offset;       //Смещение в значениях отсчета ADC
//}
//MS_correct_t;


typedef struct
{
  float koef;
  float dtf;
  int32_t offset;
  uint8_t windowSize;
  uint8_t avgSize;
}
MS_cfg_t;

//********************************Каналы****************************************

//Enum channel from ADC buffer
enum {
  ADC_CH2 = 2,
  ADC_CH3,
  ADC_CH4,
  ADC_CH5,
  ADC_CH6,
  ADC_CH7,
  ADC_CH8,
  ADC_CH9,
  ADC_CH10,
  ADC_CH11,
  ADC_CH12,
  ADC_CH13,
  ADC_CH14,
  ADC_CH15
};

#ifdef DCDC

//Датчики температуры
typedef enum
{
  MS_ID_T1 = 0, //Силовой блок 1
  MS_ID_T2, //Силовой блок 2
  MS_ID_T3, //Выпрямительный блок 1
  MS_ID_T4, //Выпрямительный блок 2
  MS_ID_T5,
  MS_ID_T6,
  MS_ID_T7,
  MS_ID_T8,
  MS_COUNT_MUXED_CH //Количество мультиплексированных каналов
}
MS_measureIdT_e;

//Вычисляемые значения
typedef enum
{
  MS_ID_POUTD1 = 0, //Мощность DC 1
  MS_ID_POUTD2, //Мощность DC 2
  MS_ID_ID1, //Суммарный ток DC 1
  MS_ID_ID2, //Суммарный ток DC 2
  MS_COUNT_CALC_VAL //Количество вычисляемых переменных
}
MS_calcId_e;

#endif //DCDC

#ifdef ACDC

//Датчики температуры
typedef enum
{
  MS_ID_T1 = 0,
  MS_ID_T2,
  MS_ID_T3, //Внутри шкафа
  MS_ID_T4, //Выпрямительный блок
  MS_ID_T5,
  MS_ID_T6,
  MS_ID_T7,
  MS_ID_T8,
  MS_COUNT_MUXED_CH //Количество мультиплексированных каналов
}
MS_measureIdT_e;

//Вычисляемые значения
typedef enum
{
  PMAIN = 0, //Мощность преобразователя
  MS_COUNT_CALC_VAL //Количество вычисляемых переменных
}
MS_calcId_e;

#endif //ACDC

#ifdef DCAC

//Вычисляемые значения
typedef enum
{
  SIOUTA = 0,   //Суммарный ток A
  SIOUTB,       //Суммарный ток B
  SIOUTC,       //Суммарный ток C
  SOUTA,        //Полная мощность фазы A
  SOUTB,        //Полная мощность фазы B
  SOUTC,        //Полная мощность фазы C
  SOUT,         //Суммарная мощность по фазам преобразователя
  MS_COUNT_CALC_VAL //Количество вычисляемых переменных
}
MS_calcId_e;

#endif //DCAC

//********************************Типы данных***************************************

//Структура данных для вычисления переменной
typedef struct
{
  int32_t sumWin; //Сумма в окне
  uint32_t sumSqr; //Сумма квадратов

  uint8_t * valBuf; //[MS_CALC_WINDOW]; //Буфер переменных читстые данные с учетом смещения и коэффициентов
  //[MS_CALC_WINDOW]

  int16_t * maxBuf; //[MS_SEGMENT_COUNT];  //Буфер максимальных значений в кадрах
  int16_t * minBuf; //[MS_SEGMENT_COUNT];  //Буфер минимальных значений в кадрах

  int32_t accumulator;
  uint8_t count;

#ifdef USE_FIXED_POINT
  int32_t avg; //Среднее значение
  uint32_t rms; //СКЗ
  int32_t dispersion; //Среднеквадратичное отклонение
  int32_t valConv; //Сконвертированное значение
  int16_t vpp; //Размах
  uint8_t fracPos;
#else
  float avg; //Среднее значение
  float rms; //СКЗ
  float vpp; //Размах
  float dispersion; //Среднеквадратичное отклонение
  float valConv; //Сконвертированное значение
#endif // USE_FIXED_POINT

  int16_t max; //максимальное значение
  int16_t min; //минимальное значение

  uint8_t calcFlag; //Флаг рассчета
  uint8_t windowPos;
  //uint8_t winSize;

}
MS_calcValBuf_t;

///////////extern float MS_calcVals[MS_COUNT_READ_CH];

//Структура данных для вычсиления температуры
typedef struct{
  uint32_t valSumT; //Сумма для вычисление среднего значения

#ifdef USE_FIXED_POINT
  int32_t avgConvT; //Среднее значение конвертированное в температуру
#else
  float avgConvT; //Среднее значение конвертированное в температуру
#endif

  uint16_t valBufT[MS_CALC_T_WINDOW]; //Буфер переменных
  uint16_t avgT; //Среднее значение

  uint8_t pos; //Количество добавленных значений

} MS_calcValT_t;

//Структура сырых данных
typedef struct{
  uint64_t timestamp; //Временная метка измерений на основе глобального таймера
 /////////////////////////////////////////////////////////////////////////// uint16_t dataAdc[ MS_COUNT_READ_CH ]; //Буфер измерений сырых данных
  // .. mux
  // .. boost
}MS_rawData_t;

//********************************Отклонения************************************

//#define CHECK_SENSOR_DIV  //Оценить отклонения датчиков

#ifdef ACDC

//Отклонения датчика
#define MS_DIV_AVG_SDI      10.0f             //Отклонение +-SDI
#define MS_DIV_AVG_SDU      10.0f             //Отклонение +-SDU

#endif //ACDC
//********************************Расчеты***************************************

//Флаги расчетов
#define MS_CALC_FLAG_RMS		0		//СКЗ
#define MS_CALC_FLAG_AVG		1		//Среднее значение
#define MS_CALC_FLAG_VPP		2		//Vpp
#define MS_CALC_FLAG_DISP		3		//Дисперсия
#define MS_CALC_FLAG_CONV		4		//Конверсия

//Коэффициенты коррекции
//extern MS_correct_t MS_correctVar[MS_COUNT_READ_CH];
//Переменная корректирующих коэффициентов температур
#ifndef DCAC
//extern MS_correct_t MS_correctVarT[MS_COUNT_MUXED_CH];
#endif
//Сырые данные из буфера
//extern uint16_t MS_rawData[MS_COUNT_READ_CH];
//Буфер измеряемых значений
///////////////////////////////////////extern MS_calcValBuf_t MS_valBuf[MS_COUNT_READ_CH];

extern uint8_t MS_calcsCount;

#ifndef DCAC
//Датчики температуры
////////////////////////////////////////////extern MS_calcValT_t MS_valBufT[MS_COUNT_MUXED_CH];
#endif

//Прореженые данные из буфера
///////////////////////////////////////////extern int16_t MS_thinData[MS_COUNT_READ_CH];

//Вычисляемые переменные
#ifdef USE_FIXED_POINT
extern int32_t MS_calcProdBuf[MS_COUNT_CALC_VAL];
#else
/////////////////////////////////extern float MS_calcProdBuf[MS_COUNT_CALC_VAL];
#endif

// adc channel number to measure ID
//extern const MS_measureId_e adcIndexMap[MS_ADC_CHNNELS_COUNT];

//********************************Функции***************************************

//Init
//////////////////////////////////RET_val MS_init(void);

void MS_adcRestart( void );

void MS_calcValues( void );

//Вызов из отложенного прерывания
bool MS_deffuredCallback(void);

//Обновить инициализацию
void MS_dmaReInit(void);


#endif // MEASURE_H
