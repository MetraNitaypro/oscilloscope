#ifndef MAP_H
#define MAP_H

#include "stdint.h"
#include "stdbool.h"





typedef struct
{
  void * varAddr;
  uint8_t varSize;
}
MM_var_t;


typedef union{
  struct{ //Aeou noaoona
    bool ready : 1; //Aioiaiinou e ?aaioa
    bool workCh1 : 1; //Eaiae a ?aai?ai ?a?eia DC 1
    bool workCh2 : 1; //Eaiae a ?aai?ai ?a?eia DC 2
  }flags;
  uint8_t bytes[5]; //Aaeou noaoona
}MM_statDCDC_t;


//Статус ошибки DCDC
typedef union{
  struct{ //Биты статуса
    bool fwCrcErr : 1; //Целостность прошивки нарушена
    bool startAfterCrash : 1; //Запуск после аварии
    bool outMemErr : 1; //Ошибка внешней памяти
    bool powerCpuErr : 1; //Ошибка питания платы
    bool sensErrSBDU2 : 1; //Ошибка датчика SBDU2
    bool sensErrSBDU1 : 1; //Ошибка датчика SBDU1
    bool sensErrSODU2 : 1; //Ошибка датчика SODU2
    bool sensErrSODU1 : 1; //Ошибка датчика SODU1
    bool sensErrSLODI2 : 1; //Ошибка датчика SLODI2
    bool sensErrSLODI1 : 1; //Ошибка датчика SLODI1
    bool sensErrSRODI2 : 1; //Ошибка датчика SRODI2
    bool sensErrSRODI1 : 1; //Ошибка датчика SRODI1
    bool sensErrT1 : 1; //Ошибка датчика T1
    bool sensErrT2 : 1; //Ошибка датчика T2
    bool sensErrT3 : 1; //Ошибка датчика T3
    bool sensErrT4 : 1; //Ошибка датчика T4
    bool overCurrentCh1 : 1; //Перегрузка канала DC 1
    bool overCurrentCh2 : 1; //Перегрузка канала DC 2
    bool preOverCurrentCh1 : 1; //Нагрузка канала 80% по DC 1
    bool preOverCurrentCh2 : 1; //Нагрузка канала 80% по DC 2
    bool preOverCurrentCh24_48 : 1; //Нагрузка канала 80% по 24/48
    bool boostCompCh1 : 1; //Отработал компаратор буста DC 1
    bool boostCompCh2 : 1; //Отработал компаратор буста DC 2
    bool currentCompCh1 : 1; //Отработал компаратор тока DC 1
    bool currentCompCh2 : 1; //Отработал компаратор тока DC 2
    bool driverErrCh1 : 1; //Ошибка платы драйверов DC 1
    bool driverErrCh2 : 1; //Ошибка платы драйверов DC 2
    bool overheatPowerCh1 : 1; //Перегрев силового блока DC 1
    bool overheatPowerCh2 : 1; //Перегрев силового блока DC 2
    bool overheatDiodeCh1 : 1; //Перегрев выпрямителя DC 1
    bool overheatDiodeCh2 : 1; //Перегрев выпрямителя DC 2
  }flags;
  uint8_t bytes[5]; //Байты статуса
}MM_errorDCDC_t;

//Статус устройства DCAC
typedef union{
  struct{ //Биты статуса
    bool workPhaseA : 1; //Канал в рабочем режиме фаза A
    bool workPhaseB : 1; //Канал в рабочем режиме фаза B
    bool workPhaseC : 1; //Канал в рабочем режиме фаза C
    bool ready : 1; //Готовность к работе
    bool redyCoCPU : 1; //Сопроцессор готов к работе
  }flags;
  uint8_t bytes[5]; //Байты статуса
}MM_statDCAC_t;

//Статус ошибки DCAC
typedef union{
  struct{ //Биты статуса
    bool fwCrcErr : 1; //Целостность прошивки нарушена
    bool startAfterCrash : 1; //Запуск после аварии
    bool outMemErr : 1; //Ошибка внешней памяти
    bool powerCpuErr : 1; //Ошибка питания платы
    bool sensErrSAUA : 1; //Ошибка датчика SAUA
    bool sensErrSAUB : 1; //Ошибка датчика SAUB
    bool sensErrSAUC : 1; //Ошибка датчика SAUC
    bool sensErrSLAIA : 1; //Ошибка датчика SLAIA
    bool sensErrSLAIB : 1; //Ошибка датчика SLAIB
    bool sensErrSLAIC : 1; //Ошибка датчика SLAIC
    bool sensErrSBDUA : 1; //Ошибка датчика SBDUA
    bool sensErrSBDUB : 1; //Ошибка датчика SBDUB
    bool sensErrSBDUC : 1; //Ошибка датчика SBDUC
    bool sensErrSSAIL : 1; //Ошибка датчика SSAIL
    bool sensErrSSAIR : 1; //Ошибка датчика SSAIR
    bool sensErrSRAIA : 1; //Ошибка датчика SRAIA
    bool sensErrSRAIB : 1; //Ошибка датчика SRAIB
    bool sensErrSRAIC : 1; //Ошибка датчика SRAIC
    bool sensErrT1 : 1; //Ошибка датчика T1
    bool sensErrT2 : 1; //Ошибка датчика T2
    bool sensErrT3 : 1; //Ошибка датчика T3
    bool overCurrentPA : 1; //Перегрузка фаза A
    bool overCurrentPB : 1; //Перегрузка фаза B
    bool overCurrentPC : 1; //Перегрузка фаза C
    bool preOverCurrentPA : 1; //Нагрузка 80% по фазе A
    bool preOverCurrentPB : 1; //Нагрузка 80% по фазе B
    bool preOverCurrentPC : 1; //Нагрузка 80% по фазе C
    bool boostCompPA : 1; //Отработал компаратор буста PA
    bool boostCompPB : 1; //Отработал компаратор буста PB
    bool boostCompPC : 1; //Отработал компаратор буста PC
    bool currentCompPA : 1; //Отработал компаратор тока PA
    bool currentCompPB : 1; //Отработал компаратор тока PB
    bool currentCompPC : 1; //Отработал компаратор тока PC
    bool driverErrPA : 1; //Ошибка платы драйверов PA
    bool driverErrPB : 1; //Ошибка платы драйверов PB
    bool driverErrPC : 1; //Ошибка платы драйверов PC
    bool overheatPA : 1; //Перегрев выпрямителя PA
    bool overheatPB : 1; //Перегрев выпрямителя PB
    bool overheatPC : 1; //Перегрев выпрямителя PC
    bool coprocessorErr : 1; //Ошибка сопроцессора
  }flags;
  uint8_t bytes[5]; //Байты статуса
}MM_errorDCAC_t;

//Получаемые параметры из стрима
typedef struct {
  MM_statDCDC_t dcdcStat; //Статус DCDC
  MM_errorDCDC_t dcdcError; //Ошибки DCDC
  MM_statDCAC_t dcacStat; //Статус DCAC
  MM_errorDCAC_t dcacError; //Ошибки DCAC
} MM_stream_t;

//Статус устройства
typedef union{
  struct{ //Биты статуса
    bool ready : 1; //Готовность к работе
    bool powerLine : 1; // питающая сеть в норме
    bool charged : 1; //Произведен выход на режим
    bool powerSynch : 1; //Выполнена синхронизация от сети
    bool heating : 1; //Работает обогрев
    bool powerOff : 1; //Силовой автомат выключен
  }flags;
  uint8_t bytes[5]; //Байты статуса
}MM_statACDC_t;

//Статус ошибки
typedef union{
  struct {
    bool powerSupply : 1; //Питающая сеть
    bool powerPhaseAbreak : 1; // phases error
    bool powerPhaseBbreak : 1; // phases error
    bool powerPhaseCbreak : 1; // phases error
    bool phaseSeq: 1; // phase sequence
    bool synchError : 1;
    bool shortCircuit : 1; // short circuit
    bool chargeVoltLim : 1; //Выход из коридора напряжения для заданного угла отпирания тиристоров
    bool brakerOff : 1; //Сработал силовой автомат
    bool crashButton : 1; //Аварийный останов
    bool openDoor : 1; //Открыта дверь
    bool controlPanel : 1; //Панель управления
    bool sensErrSAUA : 1; //Ошибка датчика SAUA
    bool sensErrSAUB : 1; //Ошибка датчика SAUB
    bool sensErrSAUC : 1; //Ошибка датчика SAUC
    bool sensErrSAIA : 1; //Ошибка датчика SAIA
    bool sensErrSAIB : 1; //Ошибка датчика SAIB
    bool sensErrSAIC : 1; //Ошибка датчика SAIC
    bool sensErrSDI : 1; //Ошибка датчика SDI
    bool sensErrSDU : 1; //Ошибка датчика SDU
    bool sensErrT1 : 1; //Ошибка датчика T1
    bool sensErrT2 : 1; //Ошибка датчика T2
    bool interfaceDcdcErr : 1; //Ошибка интерфейса DCDC
    bool interfaceDcacErr : 1; //Ошибка интерфейса DCAC
    bool overPower : 1; //Превышена общая мощность преобразователя
    bool overheat : 1; //Перегрев блока выпрямителя
  }flags;
  uint32_t bytes;
}MM_errorACDC_t;

//************************************Переменные********************************

extern uint8_t MM_dout; //Цифровые выхода платы
extern uint16_t MM_control; //Регистр управления
extern MM_errorACDC_t MM_errorACDC; //Статус ошибки
extern MM_statACDC_t MM_statACDC; //Статус устройства
extern MM_stream_t MM_stream; //Стримминговые данные


//***********************************Функции************************************

void MM_writeVal( const MM_varId_e varId, void * const src );
void MM_writeValWithSize( const MM_varId_e varId, void * const src, const uint16_t offset, const uint16_t size );
void MM_readVal( const MM_varId_e varId, void * const dst );
void MM_readValWithSize( const MM_varId_e varId, void * const dst, const uint16_t offset, const uint16_t size );




#endif // MAP_H
