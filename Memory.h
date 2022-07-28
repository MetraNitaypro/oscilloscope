#ifndef MEMORY_H
#include "stdint.h"
#include "stdbool.h"

typedef enum
{
    MM_VAR_ACDC_STAT = 0,
    MM_VAR_ACDC_ERROR,
    MM_VAR_DCDC_STAT,
    MM_VAR_DCDC_ERROR,
    MM_VAR_DCAC_STAT,
    MM_VAR_DCAC_ERROR,
    MM_VAR_POWER_OFFSET,
    MM_VAR_RAW_DATA_TRANS_SIZE,
    MM_VAR_H_MOST_ACTIVE_CHNS,
    MM_VAR_BOOST_ACTIVE_CHNS,
    MM_VAR_POWER_BLOCK_EN,
    MM_VARS_COUNT
}
MM_varId_e;



typedef struct
{
    void* varAddr;
    uint8_t varSize;
}
MM_var_t;


typedef union {
    struct { //Aeou noaoona
        bool ready : 1; //Aioiaiinou e ?aaioa
        bool workCh1 : 1; //Eaiae a ?aai?ai ?a?eia DC 1
        bool workCh2 : 1; //Eaiae a ?aai?ai ?a?eia DC 2
    }flags;
    uint8_t bytes[5]; //Aaeou noaoona
}MM_statDCDC_t;


//������ ������ DCDC
typedef union {
    struct { //���� �������
        bool fwCrcErr : 1; //����������� �������� ��������
        bool startAfterCrash : 1; //������ ����� ������
        bool outMemErr : 1; //������ ������� ������
        bool powerCpuErr : 1; //������ ������� �����
        bool sensErrSBDU2 : 1; //������ ������� SBDU2
        bool sensErrSBDU1 : 1; //������ ������� SBDU1
        bool sensErrSODU2 : 1; //������ ������� SODU2
        bool sensErrSODU1 : 1; //������ ������� SODU1
        bool sensErrSLODI2 : 1; //������ ������� SLODI2
        bool sensErrSLODI1 : 1; //������ ������� SLODI1
        bool sensErrSRODI2 : 1; //������ ������� SRODI2
        bool sensErrSRODI1 : 1; //������ ������� SRODI1
        bool sensErrT1 : 1; //������ ������� T1
        bool sensErrT2 : 1; //������ ������� T2
        bool sensErrT3 : 1; //������ ������� T3
        bool sensErrT4 : 1; //������ ������� T4
        bool overCurrentCh1 : 1; //���������� ������ DC 1
        bool overCurrentCh2 : 1; //���������� ������ DC 2
        bool preOverCurrentCh1 : 1; //�������� ������ 80% �� DC 1
        bool preOverCurrentCh2 : 1; //�������� ������ 80% �� DC 2
        bool preOverCurrentCh24_48 : 1; //�������� ������ 80% �� 24/48
        bool boostCompCh1 : 1; //��������� ���������� ����� DC 1
        bool boostCompCh2 : 1; //��������� ���������� ����� DC 2
        bool currentCompCh1 : 1; //��������� ���������� ���� DC 1
        bool currentCompCh2 : 1; //��������� ���������� ���� DC 2
        bool driverErrCh1 : 1; //������ ����� ��������� DC 1
        bool driverErrCh2 : 1; //������ ����� ��������� DC 2
        bool overheatPowerCh1 : 1; //�������� �������� ����� DC 1
        bool overheatPowerCh2 : 1; //�������� �������� ����� DC 2
        bool overheatDiodeCh1 : 1; //�������� ����������� DC 1
        bool overheatDiodeCh2 : 1; //�������� ����������� DC 2
    }flags;
    uint8_t bytes[5]; //����� �������
}MM_errorDCDC_t;

//������ ���������� DCAC
typedef union {
    struct { //���� �������
        bool workPhaseA : 1; //����� � ������� ������ ���� A
        bool workPhaseB : 1; //����� � ������� ������ ���� B
        bool workPhaseC : 1; //����� � ������� ������ ���� C
        bool ready : 1; //���������� � ������
        bool redyCoCPU : 1; //����������� ����� � ������
    }flags;
    uint8_t bytes[5]; //����� �������
}MM_statDCAC_t;

//������ ������ DCAC
typedef union {
    struct { //���� �������
        bool fwCrcErr : 1; //����������� �������� ��������
        bool startAfterCrash : 1; //������ ����� ������
        bool outMemErr : 1; //������ ������� ������
        bool powerCpuErr : 1; //������ ������� �����
        bool sensErrSAUA : 1; //������ ������� SAUA
        bool sensErrSAUB : 1; //������ ������� SAUB
        bool sensErrSAUC : 1; //������ ������� SAUC
        bool sensErrSLAIA : 1; //������ ������� SLAIA
        bool sensErrSLAIB : 1; //������ ������� SLAIB
        bool sensErrSLAIC : 1; //������ ������� SLAIC
        bool sensErrSBDUA : 1; //������ ������� SBDUA
        bool sensErrSBDUB : 1; //������ ������� SBDUB
        bool sensErrSBDUC : 1; //������ ������� SBDUC
        bool sensErrSSAIL : 1; //������ ������� SSAIL
        bool sensErrSSAIR : 1; //������ ������� SSAIR
        bool sensErrSRAIA : 1; //������ ������� SRAIA
        bool sensErrSRAIB : 1; //������ ������� SRAIB
        bool sensErrSRAIC : 1; //������ ������� SRAIC
        bool sensErrT1 : 1; //������ ������� T1
        bool sensErrT2 : 1; //������ ������� T2
        bool sensErrT3 : 1; //������ ������� T3
        bool overCurrentPA : 1; //���������� ���� A
        bool overCurrentPB : 1; //���������� ���� B
        bool overCurrentPC : 1; //���������� ���� C
        bool preOverCurrentPA : 1; //�������� 80% �� ���� A
        bool preOverCurrentPB : 1; //�������� 80% �� ���� B
        bool preOverCurrentPC : 1; //�������� 80% �� ���� C
        bool boostCompPA : 1; //��������� ���������� ����� PA
        bool boostCompPB : 1; //��������� ���������� ����� PB
        bool boostCompPC : 1; //��������� ���������� ����� PC
        bool currentCompPA : 1; //��������� ���������� ���� PA
        bool currentCompPB : 1; //��������� ���������� ���� PB
        bool currentCompPC : 1; //��������� ���������� ���� PC
        bool driverErrPA : 1; //������ ����� ��������� PA
        bool driverErrPB : 1; //������ ����� ��������� PB
        bool driverErrPC : 1; //������ ����� ��������� PC
        bool overheatPA : 1; //�������� ����������� PA
        bool overheatPB : 1; //�������� ����������� PB
        bool overheatPC : 1; //�������� ����������� PC
        bool coprocessorErr : 1; //������ ������������
    }flags;
    uint8_t bytes[5]; //����� �������
}MM_errorDCAC_t;

//���������� ��������� �� ������
typedef struct {
    MM_statDCDC_t dcdcStat; //������ DCDC
    MM_errorDCDC_t dcdcError; //������ DCDC
    MM_statDCAC_t dcacStat; //������ DCAC
    MM_errorDCAC_t dcacError; //������ DCAC 
} MM_stream_t;

//������ ����������
typedef union {
    struct { //���� �������
        bool ready : 1; //���������� � ������
        bool powerLine : 1; // �������� ���� � �����
        bool charged : 1; //���������� ����� �� �����
        bool powerSynch : 1; //��������� ������������� �� ����
        bool heating : 1; //�������� �������
        bool powerOff : 1; //������� ������� ��������
    }flags;
    uint8_t bytes[5]; //����� �������
}MM_statACDC_t;

//������ ������
typedef union {
    struct {
        bool powerSupply : 1; //�������� ����
        bool powerPhaseAbreak : 1; // phases error
        bool powerPhaseBbreak : 1; // phases error
        bool powerPhaseCbreak : 1; // phases error
        bool phaseSeq : 1; // phase sequence
        bool synchError : 1;
        bool shortCircuit : 1; // short circuit
        bool chargeVoltLim : 1; //����� �� �������� ���������� ��� ��������� ���� ��������� ����������
        bool brakerOff : 1; //�������� ������� �������
        bool crashButton : 1; //��������� �������
        bool openDoor : 1; //������� �����
        bool controlPanel : 1; //������ ����������
        bool sensErrSAUA : 1; //������ ������� SAUA
        bool sensErrSAUB : 1; //������ ������� SAUB
        bool sensErrSAUC : 1; //������ ������� SAUC
        bool sensErrSAIA : 1; //������ ������� SAIA
        bool sensErrSAIB : 1; //������ ������� SAIB
        bool sensErrSAIC : 1; //������ ������� SAIC
        bool sensErrSDI : 1; //������ ������� SDI
        bool sensErrSDU : 1; //������ ������� SDU
        bool sensErrT1 : 1; //������ ������� T1
        bool sensErrT2 : 1; //������ ������� T2
        bool interfaceDcdcErr : 1; //������ ���������� DCDC
        bool interfaceDcacErr : 1; //������ ���������� DCAC
        bool overPower : 1; //��������� ����� �������� ���������������
        bool overheat : 1; //�������� ����� �����������
    }flags;
    uint32_t bytes;
}MM_errorACDC_t;

//************************************����������********************************

extern uint8_t MM_dout; //�������� ������ �����
extern uint16_t MM_control; //������� ����������
extern MM_errorACDC_t MM_errorACDC; //������ ������
extern MM_statACDC_t MM_statACDC; //������ ����������
extern MM_stream_t MM_stream; //������������� ������


//***********************************�������************************************

void MM_writeVal(const MM_varId_e varId, void* const src);
void MM_writeValWithSize(const MM_varId_e varId, void* const src, const uint16_t offset, const uint16_t size);
void MM_readVal(const MM_varId_e varId, void* const dst);
void MM_readValWithSize(const MM_varId_e varId, void* const dst, const uint16_t offset, const uint16_t size);


#define MEMORY_H

#endif // MEMORY_H
