/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "datasource.h"
#include <QtCharts/QXYSeries>
#include <QtCharts/QAreaSeries>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtCore/QDebug>
#include <QtCore/QRandomGenerator>
#include <QtCore/QtMath>
#include "Map.h"
#include <QtMath>
QT_CHARTS_USE_NAMESPACE
Q_DECLARE_METATYPE(QAbstractSeries *)
Q_DECLARE_METATYPE(QAbstractAxis *)
DataSource::DataSource(QQuickView *appViewer, QObject *parent) :
    QObject(parent),
    m_appViewer(appViewer),
    m_index(-1)
{
    qRegisterMetaType<QAbstractSeries*>();
    qRegisterMetaType<QAbstractAxis*>();
    this->flag_1 = 0;
    this->flag_CMD_1 = 0;
    this->flag_CMD_2 = 0;
    this->flag_CMD_3 = 0;
    this->win_size = 1000;
    this->size_add = 100000;
    this->size_Big = 100000000;
    this->add = QVector<QVector<QVector<QPointF>>>(6);
    for(int i = 0; i < 6; i++){
        this->add[i] = QVector<QVector<QPointF>>(10);
        for(int j = 0; j < 10; j++){
            this->add[i][j] = QVector<QPointF>(this->size_add);
        }
    }
    this->unit = new int* [6];// текущее значения графиков
    for(int i = 0; i < 6; i++){
        this->unit[i] = new int[10];
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++){
            this->unit[i][j] = 0;
        }
    }
    //Parsing_1(QSerialPort * port, QVector<QVector<QVector<QPointF>>> * add, QMutex * ad, int *** k, int buffer_size, int window_size, long int big_buffer)
    this->pars = new Parsing_1(&this->port, &add, &a, &this->unit, this->size_add, this->win_size, this->size_Big);
    this->Win =  QVector<QPointF> (win_size);
//    for(int i = 0; i < win_size; i++){
//        this->Win[i].setX(i);
//    }
    QIODevice::connect(this->pars, SIGNAL(send_1(int)), this, SLOT(er(int)));
}
void DataSource::update(int count, QAbstractSeries *series)
{
//    if (!this->port.isOpen())
//    {
//        return;
//    }

        QXYSeries *xySeries = static_cast<QXYSeries *>(series);
      //  this->a.lock();
        int tmp = this->unit[this->flag_1][count];
        if (tmp < this->win_size)
        {
            for(int i = 0; i <= tmp; i++)
            {
                this->Win[i].setX(i);
                this->Win[i].setY(this->add[this->flag_1][count][i].y());
            }
            int y = tmp + 1;
            for(int i = this->size_add - ( this->win_size - tmp) + 1; i < this->size_add ; i++)
            {

                this->Win[y].setX(y);
                this->Win[y].setY(this->add[this->flag_1][count][i].y());
                y++;
            }
        }
        else
        {
            int y = tmp - this->win_size + 1;
            for(int i = 0; i < this->win_size; i++)
            {
                this->Win[i].setX(i);
                this->Win[i].setY(this->add[this->flag_1][count][y].y());
                y++;
            }
        }
       // this->Win;
//        if (tmp < this->win_size)
//            {
//                 std::copy((this->add[0][0].end() - (this->win_size - tmp)), this->add[0][0].end(), this->Win.begin());
//                 std::copy(this->add[0][count].begin(), (this->add[0][count].begin() + tmp), (Win.end() - tmp));
//            }
//        else
//        {
//            std::copy(this->add[0][count].begin() + tmp - this->win_size, this->add[0][count].begin() + tmp, this->Win.begin());
//        }
       // this->Win;
        xySeries->replace(this->Win);
       // this->a.unlock();
    }
void DataSource::generateData(int type, int rowCount, int colCount)
{

}
void DataSource::f(int a){
this->flag_1 = a;
}

void DataSource::ff(QVariantList *a){
    this->aa = a;
    a[0].append("23");
}

void DataSource::portInf(){
    QList<QSerialPortInfo> list_1;
    list_1 = this->port_inf.availablePorts();
    for (auto i = list_1.begin(); i < list_1.end();i++){
        this->str_1 += i->portName();
        emit sendToQml(i->portName());
    }
}
void DataSource::setPort(QString gg){
   // this->pars->quit();
    this->port.flush();
    if (this->port.isOpen()) this->port.close();
    this->port.setPortName(gg);
    this->port.setBaudRate(921600);
    this->port.setReadBufferSize(2000);

    this->port.open(QIODevice::ReadWrite);
    if (!this->port.isOpen()){
        qDebug()<<"notOpen"<<endl;
    }
    qDebug()<<"ыв"<<endl;
    this->pars->start();
}
void DataSource::getRaW(QString num , QString name){
    char a[8];
    memset(a,0,8);
    a[0] =  BT_PT_START_SYMBOL;
    a[1] = (BT_DCDC_ADDR << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL;
    a[2] = MM_VAR_RAW_DATA_TRANS_SIZE;
    a[3] = 0;
      int r = num.toInt();
    memcpy(&a[4], &r, 4);
    a[3] = crc8((uint8_t *)a, 8, 0x66);
    this->port.waitForBytesWritten(0);
    this->port.write(a, 8);
   if (!this->port.isOpen()) qDebug()<<"sfs";
       this->port.flush();
    memset(a,0,8);
    a[0] =  BT_PT_START_SYMBOL;
    a[1] = (BT_DCDC_ADDR << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_GET_VAL;
    a[2] = MM_VAR_RAW_DATA_TRANS_SIZE;
    a[3] = 0;
    r = 0;
    //int r = num.toInt();
    memcpy(&a[4], &r, 4);
    a[3] = crc8((uint8_t *)a, 8, 0x66);
    this->port.waitForBytesWritten(0);
    this->port.write(a, 8);
    if (!this->port.isOpen()) qDebug()<<"sfs";
    this->port.flush();
//    char a[8];
//    memset(a,0,8);
//    a[0] = startByte;
//    a[1] = (BT_DCDC_ADDR <<6)|(BT_REMOTE_ADDR<<4)|BT_CMD_GET_VAL;
//    a[2] = MM_VAR_DCDC_STAT;
//    a[3] = 0;
//    a[4] = 1;
//    a[5] = 1;
//    a[6] = 1;
//    a[7] = 1;
//   a[3] = crc8((uint8_t *)a, 8, 0x66);
//   this->gg.waitForBytesWritten(0);
//   this->gg.write(a,8);
//   this->gg.flush();
}
void DataSource::getsend(QString num , QString name){
    char a[8];
//    memset(a,0,8);
//    a[0] = startByte;
//    a[1] = (BT_DCDC_ADDR <<6)|(BT_REMOTE_ADDR<<4)|BT_CMD_GET_VAL;
//    a[2] = MM_VAR_DCDC_STAT;
//    a[3] = 0;
//    a[4] = 1;
//    a[5] = 1;
//    a[6] = 1;
//    a[7] = 1;
//   a[3] = crc8((uint8_t *)a, 8, 0x66);
//   this->gg.waitForBytesWritten(0);
//   this->gg.write(a,8);
//   this->gg.flush();
}
void DataSource::er(int k){

     emit sentToQml(QString::number(k));
    // emit sendToQml("i->portName()");
}
void DataSource::cmd_1(int val){
this->flag_CMD_1 = val;
}
void DataSource::cmd_2(int val){
this->flag_CMD_2 = val;
}
void DataSource::cmd(QString val){
//this->flag_CMD_3 = val.toInt();
//    char a[8];
//    memset(a,0,8);
//    a[0] =  BT_PT_START_SYMBOL;
//    a[1] = (BT_DCDC_ADDR << 6) | (BT_REMOTE_ADDR << 4) | this->flag_CMD_1;
//    a[2] = this->flag_CMD_2;
//    a[3] = 0;
//    //memcpy(&a[4], &r, 4);
//    a[3] = crc8((uint8_t *)a, 8, 0x66);
//    this->port.waitForBytesWritten(0);
//    this->port.write(a, 8);
//    if (!this->port.isOpen()) qDebug()<<"sfs";
//    this->port.flush();
    char a[8];
    memset(a,0,8);
    a[0] =  BT_PT_START_SYMBOL;
    a[1] = (BT_DCDC_ADDR << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL;
    a[2] = MM_VAR_RAW_DATA_TRANS_SIZE;
    a[3] = 0;
      //int r = num.toInt();
    //memcpy(&a[4], &r, 4);
    a[3] = crc8((uint8_t *)a, 8, 0x66);
    this->port.waitForBytesWritten(0);
    this->port.write(a, 8);
   if (!this->port.isOpen()) qDebug()<<"sfs";
       this->port.flush();
    memset(a, 0, 8);
    a[0] =  BT_PT_START_SYMBOL;
    a[1] = (BT_DCDC_ADDR << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_GET_VAL;
    a[2] = MM_VAR_RAW_DATA_TRANS_SIZE;
    a[3] = 0;
    //r = 0;
    //int r = num.toInt();
    //memcpy(&a[4], &r, 4);
    a[3] = crc8((uint8_t *)a, 8, 0x66);
    this->port.waitForBytesWritten(0);
    this->port.write(a, 8);
    //if (!this->port.isOpen()) qDebug()<<"sfs";
    this->port.flush();
}
void DataSource::kk(QString val, QString jj){
    QString k = val;
    QString hhh = jj;
}
void DataSource::slide(int tag, int tag_1, int val, int set){
    //qDebug() << 1;
    switch(tag){

    case 0: {
        if(set == 0){
            this->set((tag << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, MM_VAR_ACDC_RECT_CTRL ,0);
        }
        else if(set == 2){
            this->set((tag << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, MM_VAR_POWER_ACDC_ALPHA_NUM ,0);
            this->set((tag << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, MM_VAR_ACDC_RECT_CTRL , 1);

        }
        else{
        this->set((tag << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, MM_VAR_POWER_ACDC_ALPHA_NUM , val | 0x8000);
        this->set((tag << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, MM_VAR_ACDC_RECT_CTRL , 1);
        }
        return;
    }
    default:{
       // qDebug()<<tag;
        this->set((tag << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, MM_VAR_BOOST_ACTIVE_CHNS , set<<8 |tag_1| val<<16);

    }
    }
}

void DataSource::invertor(int tag, bool ch_1, bool ch_2, bool ch_3){
    //qDebug()<<ch_1 | (ch_2 << 1) | (ch_3 << 2);
     qDebug() << tag <<  (ch_1 | (ch_2 << 1) | (ch_3 << 2));
    this->set((tag << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, MM_VAR_H_MOST_ACTIVE_CHNS,  ch_1 | (ch_2 << 1) | (ch_3 << 2));
}

void DataSource::raw_data(int cpu_freg, int adc_div, int adc_cycles, bool avg, bool rms, bool vpp, bool fixed_point,
                          int frac_bits, int channels_count, int pack_size, int adc_freq_max, int avg_size,
                          int window_size, int offset, int fk, int koef){
//    qDebug()<< cpu_freg << " "<<  adc_div<< " "<<   adc_cycles<< " "<<  avg<< " "<<
//            rms<< " "<<  vpp<< " "<<  fixed_point<< " "<<   frac_bits<< " "<<
//            channels_count<< " "<<   pack_size<< " "<<  adc_freq_max<< " "<<   avg_size<< " "<<
//            window_size<< " "<<   offset<< " "<<   fk<< " "<<   koef << endl;

    int raw_data_size = 100;

}
void DataSource::set(char cmd_id, char var_id , int val){
    char a[8];
    memset(a,0,8);
    a[0] =  BT_PT_START_SYMBOL;
    a[1] = cmd_id;
    a[2] = var_id;
    memcpy(&a[4], &val, 4);
    a[3] = crc8((uint8_t *)a, 8, 0x66);
    this->port.waitForBytesWritten(0);
    this->port.write(a, 8);
    this->port.flush();
}
void DataSource::relay(int val){
    //val -  rb
    this->set((0 << 6) | (BT_REMOTE_ADDR << 4) | BT_CMD_SET_VAL, chlen ,0);
}
