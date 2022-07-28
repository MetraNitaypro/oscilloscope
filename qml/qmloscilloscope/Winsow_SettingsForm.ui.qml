import QtQuick 2.4
import QtQuick.Controls 2.15
import QtQuick.Window 2.14
import QtCharts 2.3
import QtQuick.Timeline 1.0
import QtQuick3D 1.15


Item {
    id: main
    width: 1920
    height: 1080
    anchors.fill: parent
    signal seriesTypeChanged(string type)
    signal refreshRateChanged(variant rate)
    Grid {
        id: grid
        x: 0
        y: 0
        width: 1920
        height: 303
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        Item {
            id: item1
            x: 0
            y: 0
            width: 150
            height: 100

            Setor_1 {
                id: setor_1
                x: 0
                y: 0
                text:"CPU_Freq"
            }

        }
        Item {
            id: item2
            x: 150
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_2
                x: 0
                y: 0
                text:"ADC_div"

            }
        }

        Item {
            id: item3
            x: 300
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_3
                x: 0
                y: 0
                text:"ADC_Cycles"
            }
        }

        Item {
            id: item4
            x: 450
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_4
                x: 0
                y: 0
                text:"Frac bits"
            }
        }

        Item {
            id: item5
            x: 600
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_5
                x: 0
                y: 0
                text:"channels_count"
            }

        }

        Item {
            id: item6
            x: 750
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_6
                x: 0
                y: 0
                text:"Pack_Size"
            }

        }

        Item {
            id: item7
            x: 900
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_7
                x: 0
                y: 0
                text:"Avg_Size"
            }

        }

        Item {
            id: item8
            x: 1050
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_8
                x: 0
                y: 0
                text:"window_Size"
            }
        }

        Item {
            id: item9
            x: 1200
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_9
                x: 0
                y: 0
                text:"offset"
            }
        }

        Item {
            id: item10
            x: 1350
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_10
                x: 0
                y: 0
                text:"fk"
            }

        }
        Item {
            id: item11
            x: 1350
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_11
                x: 0
                y: 0
                text:"koef"
            }

        }
        Item {
            id: item12
            x: 1350
            y: 0
            width: 150
            height: 100
            Setor_1 {
                id: setor_12
                x: 0
                y: 0
                text:"ADC_Freq_Max"
            }

        }
    }



    CheckBox {
        id: checkBox
        x: 793
        y: 263
        text: qsTr("AVG")
    }

    CheckBox {
        id: checkBox1
        x: 864
        y: 263
        text: qsTr("RMS")
    }

    CheckBox {
        id: checkBox2
        x: 933
        y: 263
        text: qsTr("VPP")
        anchors.verticalCenter: checkBox.verticalCenter
    }

    CheckBox {
        id: checkBox3
        x: 600
        y: 0
        text: qsTr("Fixed Point")
    }
    Connections {
           target: dataSource// Указываем целевое соединение
           /* Объявляем и реализуем функцию, как параметр
            * объекта и с имененем похожим на название сигнала
            * Разница в том, что добавляем в начале on и далее пишем
            * с заглавной буквы
            * */



    }

Button {
    id: button
    x: 836
    y: 27
    width: 154
    height: 55
    text: qsTr("Button")
    anchors.top: checkBox3.top

}

Button {
    id: button1
    x: 1048
    y: 27
    width: 159
    height: 55
    text: qsTr("Button")
    anchors.top: checkBox3.top
    anchors.bottom: button.bottom
}

Item {
    id: item13
    x: 8
    y: 391
    width: 965
    height: 561

    Graph {
        id: graph
        x: -8
        y: 0
        width: 965
        height: 561
    }
}

Item {
    id: item14
    x: 979
    y: 391
    width: 933
    height: 561

    Graph {
        id: graph1
        x: -16
        y: 0
        width: 949
        height: 561
    }
}

Text {
    id: text1
    x: 8
    y: 329
    width: 414
    height: 43
    text: qsTr("Calc")
    font.pixelSize: 27
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
}

Text {
    id: text2
    x: 985
    y: 329
    width: 414
    height: 43
    text: qsTr("Raw")
    font.pixelSize: 27
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
}



states: [
    State {
        name: "State1"
    }
]






}





/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}
}
##^##*/
