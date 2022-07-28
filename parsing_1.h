#ifndef PARSING_1_H
#define PARSING_1_H
#include<QThread>
#include <QDebug>
#include <QSerialPort>
#include <QApplication>
#include <QMutex>
#include "CRC8.h"
#include "BTMod.h"
class Parsing_1: public QThread{
    Q_OBJECT
private:
QSerialPort * port;//порт
long int * shit;//массив куда пишутся все значения
QVector<QVector<QVector<QPointF>>> *add;// массив для графиков
uint8_t * header;//сюда записывается шапка сообщения
uint8_t CMD1;//cmdid means
uint8_t * arg;//сюда считываются значения для графиков
int ** count_1;//// текущее значение для точки x окна
//////////////вспомогательные структуры
typedef enum {
    one_startByte,
    two_cmdId,
    three_varId,
    foure_crc,
    five_arg_0,
    six_arg_1,
    seven_arg_2,
    eathh_arg_3
}Byte;
/////////////////
typedef struct faf{
    uint32_t stat_flags;
    uint32_t stat_error;
}stats_t;
stats_t powerBlockStats[3];
QMutex *ad;
//////////////////
int buffer_size;//это размер add
int window_size;// это размер окна
int Big_buffer_size;
int *** uint = 0;// это текущее значение буффера (массива add)
public:
    Parsing_1(QSerialPort * port, QVector<QVector<QVector<QPointF>>> * add, QMutex * ad, int *** k, int buffer_size, int window_size, long int big_buffer){
        this->buffer_size = buffer_size;// размер массива add
        this->Big_buffer_size = big_buffer;
        this->shit = new long int [this->Big_buffer_size];// массив куда записываются все считанные значения
        this->header = new uint8_t[8];// header
        this->arg = new uint8_t[4];//сюда считываю точку
        //// текущее значение для точки x окна
        this->count_1 = new int *[6];
        for(int i = 0; i < 6; i++){
            this->count_1[i] = new int[10];
        }
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                this->count_1[i][j] = this->window_size - 1;
            }
        }
        ////////////
        this->uint = k;// это текущее значение буффера (массива add)
        this->ad = ad;// mutex
        this->add = add;// массив куда пишем значения
        this->port = port;// это порт
        this->window_size = window_size;// это размер окна
    }
    ~Parsing_1(){
          delete[] this->header;
          delete[] this->arg;
          delete[] this->shit;
    }
// функция для считывания байта
    void Read_Uart(QSerialPort* port, char* a){
        static int count_2;
        while(!this->port->getChar(a)){
        this->port->waitForReadyRead(1000);
        }
        //qDebug() << (*a);
        if (count_2 == this->Big_buffer_size){
            count_2 = 0;
        }
        this->shit[count_2] = *a;
        count_2++;

    }
 // функция для подсчета CRC
    bool CRC(uint8_t start_val)
    {
        uint8_t crc = this->header[foure_crc];
        this->header[foure_crc] = 0;
        if (crc8(this->header, 8, start_val) == crc)
        {
         return 1;
        }
        else return 0;
    }
// функция для считывания CALC_DATA
    void Read_CALC()
    {
        float bb = 0;
//           if (this->CMD1 == BT_DCDC_ADDR || this->CMD1 == BT_ACDC_ADDR || this->CMD1 == BT_DCAC_ADDR)
//              {
               int jj = 0;
               int j = 0;
               for(int i = 0; i < this->header[three_varId]; i++)
                  {
                   this->Read_Uart(this->port, (char*) &this->arg[j]);
                   j++;
                   if (j == 4)
                     {
                       {
                       if (jj > 9 || jj < 0)
                       {
                          // qDebug() << "EROR CANAL_CALC" << endl;
                           break;
                       }
                       bb = 0;
                       memcpy(&((char*)&bb)[0], &this->arg[0], 4);
                       float rr =  bb;
                       double rrk = (double) bb;

                      // this->ad[0].lock();
                       if (this->uint[0][this->header[two_cmdId] - BT_CMD_CALC_MES][jj] == this->buffer_size)
                       {
                          this->uint[0][this->header[two_cmdId] - BT_CMD_CALC_MES][jj] = 0;
                       }
                       if (this->count_1[this->header[two_cmdId] - BT_CMD_CALC_MES][jj] < 0){
                           this->count_1[this->header[two_cmdId] - BT_CMD_CALC_MES][jj] = this->window_size - 1;
                       }

                       this->add[0][this->header[two_cmdId] - BT_CMD_CALC_MES][jj][this->uint[0][this->header[two_cmdId] - BT_CMD_CALC_MES][jj]] = QPointF(this->count_1[this->header[two_cmdId] - BT_CMD_CALC_MES][jj], bb);
                       this->uint[0][this->header[two_cmdId] - BT_CMD_CALC_MES][jj]++;
                       this->count_1[this->header[two_cmdId] - BT_CMD_CALC_MES][jj]--;
                       //this->ad[0].unlock();
                       j = 0;
                       jj++;
                       bb = 0;
                      }
                    }
               // }
            }
   }
    // функция для считывания RAW_DATA
    void Read_RAW()
    {
            float bb;
            int b;
            int j = 0;
            for(int i = 0; i < this->header[three_varId]; i++)
            {
                this->Read_Uart(this->port, (char*) &this->arg[j]);
                j++;
                if (j == 4)
                {
                    b = 0;
                    bb = 0;
                    memcpy(&((char*)&bb)[0], &this->arg[0], 2);
                    memcpy(&((char*)&b)[0], &this->arg[2], 2);
                    if (b < 0 || b > 9)
                    {
                       // qDebug() << "EROR CANAL_RAW" << endl;
                        break;
                    }
                    if (this->uint[0][this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b] == this->buffer_size)
                    {
                       this->uint[0][this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b] = 0;
                    }
                    if (this->count_1[this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b] == this->window_size){
                        this->count_1[this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b] = this->window_size - 1;
                    }
                    //this->ad[0].lock();
                    int  ij = this->header[two_cmdId] - BT_CMD_RAW_MES + 3;
                    ij = this->count_1[this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b];
                    ij = this->uint[0][this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b];
                    this->add[0][this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b][this->uint[0][this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b]] = QPointF(this->count_1[this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b], bb);
                   // this->ad[0].unlock();
                    this->count_1[this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b]--;
                    this->uint[0][this->header[two_cmdId] - BT_CMD_RAW_MES + 3][b]++;
                    j = 0;
                }
            }
    }
    void Read_Header()
    {
        while(this->header[one_startByte] != BT_PT_START_SYMBOL){
           this->Read_Uart(this->port, (char*) &this->header[one_startByte]);
        }
        this->Read_Uart(this->port, (char*) &this->header[two_cmdId]);
        if ((this->header[two_cmdId] >> 6) ==  BT_REMOTE_ADDR)
        {
           this->CMD1 = 0;
           this->CMD1 = this->header[two_cmdId] >> 4;
           ///if (!this->port->isOpen())break;
           this->Read_Uart(this->port, (char*) &this->header[three_varId]);
           this->Read_Uart(this->port, (char*) &this->header[foure_crc]);
           this->Read_Uart(this->port, (char*) &this->header[five_arg_0]);
           this->Read_Uart(this->port, (char*) &this->header[six_arg_1]);
           this->Read_Uart(this->port, (char*) &this->header[seven_arg_2]);
           this->Read_Uart(this->port, (char*) &this->header[eathh_arg_3]);
           this->header[two_cmdId] &= 0xF;
    }
    }
    void ACK(){
        if (this->header[two_cmdId] ==  BT_CMD_ACK)
           {
              if (1)
                {
                    //emit send_1(*((int*)this->header[five_arg_0]));
                }
           }
    }
 void run()
{
        while(1)
        {
           this->Read_Header();

           this->ACK();
           if (this->header[two_cmdId] == BT_CMD_CALC_MES){
               this->Read_CALC();
           }
           else if(this->header[two_cmdId] ==  BT_CMD_RAW_MES)
           {
               this->Read_RAW();
           }
           else
           {

           }
//           for(int i = 0; i < count_2; i++)this->shit[i];
       }
       exec();
}
signals:
    void send(int Canal, char flag_1);
    void send_1(int k);
public slots:
};
#endif // PARSING_1_H
