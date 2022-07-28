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
import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
ColumnLayout {
    property alias openGLButton: openGLButton
    property alias antialiasButton: antialiasButton
    spacing: 8
    Layout.fillHeight: true
    signal animationsEnabled(bool enabled)
    signal seriesTypeChanged(string type)
    signal refreshRateChanged(variant rate)
    signal signalSourceChanged(string source, int signalCount, int sampleCount)
    signal antialiasingEnabled(bool enabled)
    signal openGlChanged(bool enabled)
    signal ad(string  a)
    signal add()
    signal sendCMD(string val)
    signal sendCMD_1(int currentindex)
    signal sendCMD_2(int currentindex)
/////////////COM
    MultiButton {
        id: buttomwe
        text: "COM_Avaible"
        items: ["Load"]
        enabled: true
        currentSelection: 0
        onSelectionChanged: add();
    }
    ComboBox {
        currentIndex: 10
        id:asd
        model: ListModel {
            id: model
        }
        onCurrentIndexChanged: ad(model.get(currentIndex).text);
    }
    ////////////////////////////CMD
    ComboBox {
        currentIndex: 0
        model: ListModel {
            id: model_CMD_1
            ListElement { text: "BT_CMD_SET_VAL"}
            ListElement { text: "BT_CMD_GET_VAL"}
            ListElement { text: "BT_CMD_ACK"}
            ListElement { text: "BT_CMD_STAT"}
            ListElement { text: "BT_CMD_END_8BYTE_CTG"}
            ListElement { text: "BT_CMD_SET_MEM"}
            ListElement { text: "BT_CMD_GET_MEM"}
            ListElement { text: "BT_CMD_BEGIN_RAW_CTG"}
            ListElement { text: "BT_CMD_RAW_MES"}
            ListElement { text: "BT_CMD_CALC_MES"}
            ListElement { text: "BT_CMD_COUNT"}
        }
        onCurrentIndexChanged:sendCMD_2(currentIndex);
    }
    ComboBox {
        currentIndex: 0
        model: ListModel {
            id: model_CMD_2
            ListElement { text: "MM_VAR_ACDC_STAT"}
            ListElement { text: "MM_VAR_ACDC_ERROR"}
            ListElement { text: "MM_VAR_DCDC_STAT"}
            ListElement { text: "MM_VAR_DCDC_ERROR"}
            ListElement { text: "MM_VAR_DCAC_STAT"}
            ListElement { text: "MM_VAR_DCAC_ERROR"}
            ListElement { text: "MM_VAR_POWER_OFFSET"}
            ListElement { text: "MM_VAR_RAW_DATA_TRANS_SIZE"}
            ListElement { text: "MM_VAR_H_MOST_ACTIVE_CHNS"}
            ListElement { text: "MM_VAR_BOOST_ACTIVE_CHNS"}
            ListElement { text: "MM_VAR_POWER_BLOCK_EN"}
            ListElement { text: "MM_VARS_COUNT"}
        }
        onCurrentIndexChanged:sendCMD_1(currentIndex);
    }
    TextField {
        id: text_2
        placeholderText: qsTr("")
    }
    MultiButton {
        id: com
        text: "send"
        items: ["Command","sdf"]
        currentSelection: 0
        onSelectionChanged: sendCMD(text_2.text);
    }
    TextField {
        id: text_1
        placeholderText: qsTr("sdg")
    }
    ///////source
    ComboBox {
        currentIndex: 0
        model: ListModel {
            id: model_2
            ListElement { text: "ACDC_CALC" }
            ListElement { text: "DCDC_CALC" }
            ListElement { text: "DCAC_CALC" }
            ListElement { text: "ACDC_RAW" }
            ListElement { text: "DCDC_RAW" }
            ListElement { text: "DCAC_RAW" }
        }
        onCurrentIndexChanged:signalSourceChanged(0, currentIndex, 0);
    }
    ///////////
    MultiButton {
        id: openGLButton
        text: "OpenGL: "
        items: ["false", "true"]
        currentSelection: 1
        onSelectionChanged: openGlChanged(currentSelection == 1);
    }
    MultiButton {
        text: "Graph: "
        items: ["line", "scatter"]
        currentSelection: 0
        onSelectionChanged: seriesTypeChanged(items[currentSelection]);
    }
    MultiButton {
        id: sampleCountButton
        text: "Samples: "
        items: ["6", "128", "1024", "10000"]
        currentSelection: 2
        onSelectionChanged: signalSourceChanged(
                                signalSourceButton.items[signalSourceButton.currentSelection],
                                5,
                                selection);
    }
    MultiButton {
        text: "Refresh rate: "
        items: ["1", "24", "60"]
        currentSelection: 2
        onSelectionChanged: refreshRateChanged(items[currentSelection]);
    }

    MultiButton {
        id: antialiasButton
        text: "Antialias: "
        items: ["OFF", "ON"]
        enabled: true
        currentSelection: 0
        onSelectionChanged: antialiasingEnabled(currentSelection == 1);
    }
    Connections {
           target: dataSource// Указываем целевое соединение
           /* Объявляем и реализуем функцию, как параметр
            * объекта и с имененем похожим на название сигнала
            * Разница в том, что добавляем в начале on и далее пишем
            * с заглавной буквы
            * */

           onSendToQml:{
               model.append({ text: count })
           }

           onSentToQml:{
               text_1.text = k
           }
       }

    onAdd:{
        model.clear();
        dataSource.portInf();
    }


}
