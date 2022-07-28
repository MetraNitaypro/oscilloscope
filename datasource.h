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
#ifndef DATASOURCE_H
#define DATASOURCE_H
#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "parsing_1.h"
#include <QMutex>
#include "CRC8.h"

QT_BEGIN_NAMESPACE
class QQuickView;
QT_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE
#define         SW_KM_24_L      ( 1 << RB_ID_RK5 )
#define         SW_KM_24_R      ( 1 << RB_ID_RK4 )

#define         SW_KM_24_48   ( SW_KM_24_L | SW_KM_24_R )
#define         SW_KM_ALL_DC    ( SW_KM_24_48 )

#define         SW_KM_3F_L      ( 1 << RB_ID_RK8 )
#define         SW_KM_1F_L      ( 1 << RB_ID_RK9 )
#define         SW_KM_3F_R      ( 1 << RB_ID_RK6 )
#define         SW_KM_1F_R      ( 1 << RB_ID_RK7 )
#define         SW_KM_ALL_AC    ( SW_KM_3F_L | SW_KM_1F_L | SW_KM_3F_R | SW_KM_1F_R )


#define         SW_KM_LIGHTS            ( 1 << RB_ID_RK1 )
#define         SW_KM_STOP_ALARM        ( 1 << RB_ID_RK2 )
#define         SW_KM_BEEP              ( 1 << RB_ID_RK3 )
#define         SW_KM_FAN_DRV           ( 1 << RB_ID_FAN_DRV )
class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QQuickView *appViewer, QObject *parent = 0);
    ~DataSource(){
    }
Q_SIGNALS:
public slots:
    void generateData(int type, int rowCount, int colCount);
    void update(int count, QAbstractSeries *series);
    void f(int a);
    void ff(QVariantList *a);
    void portInf();
    void setPort(QString gg);
    void getsend(QString num , QString name);
    void getRaW(QString num , QString name);
    void er(int);
    void cmd_1(int val);
    void cmd_2(int val);
    void cmd(QString val);
    void kk(QString val, QString val1);
    //void Buttom(int tag);
    void slide(int tag, int tag_1, int val, int set);
    void invertor(int tag, bool ch_1, bool ch_2, bool ch_3);
    void raw_data(int cpu_freg, int adc_div, int adc_cycles, bool avg, bool rms, bool vpp, bool fixed_point,
                  int frac_bits, int channels_count, int pack_size, int adc_freq_max, int avg_size,
                  int window_size, int offset, int fk, int koef);
    void set(char a, char b , int val);
    void relay(int val);
 signals:
      void sendToQml(QString count);
      void sentToQml(QString k);

     // void sendToQmL(char a);
private:
    QQuickView *m_appViewer;
    QList<QVector<QPointF> > m_data;
    QVector<QVector<QVector<QPointF>>> add;
    int size_add;
    int size_Big;
    QSerialPort port;
    QSerialPortInfo port_inf;
    Parsing_1 *pars;
    QMutex a;
    QVariantList* aa;
    QString str_1;
    int m_index;
    int **unit;
    QVector<QPointF> Win;
    int win_size;
    int flag_1;
    ///CMD
    int flag_CMD_1;
    int flag_CMD_2;
    int flag_CMD_3;
};
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
  MM_VAR_H_MOST_ACTIVE_CHNS, // bits channels mask ( 1 - ON, 0 - OFF )
  MM_VAR_BOOST_ACTIVE_CHNS, // 0xVVVVMMCC ( V - value, M - Mode, C - bits channel mask )
  MM_VAR_POWER_BLOCK_EN,
  MM_VAR_POWER_ACDC_ALPHA,
  MM_VAR_POWER_ACDC_ALPHA_NUM, // 0..169 + {0x8000 ( for Manual mode )}
  MM_VAR_ACDC_RECT_CTRL,// SWC_ctrl_e
  chlen,
  MM_VARS_COUNT
}
MM_varId_e;
typedef enum
{
  RB_ID_RK1 = 0,
  RB_ID_RK2,
  RB_ID_RK3,
  RB_ID_RK4,
  RB_ID_RK5,
  RB_ID_RK6,
  RB_ID_RK7,
  RB_ID_RK8,
  RB_ID_RK9,
  RB_ID_FAN_DRV,
  RB_ID_QP1,
  RB_ID_QP2,
  RB_ID_QP3,
  RB_ID_QP4,
  RB_ID_QP5,
  RB_ID_COUNT
} RB_ID_Type;

#endif // DATASOURCE_H
