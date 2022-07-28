import QtQuick 2.4
import QtQuick.Controls 2.15
Rectangle {
    border.width: 1
    width: 1000
    height: 1000
    signal moveded(int val);
    signal sendchlen(int k);
    Column{
        width: parent.width
        height: parent.height
    Column {
        id: column_123
        x: 0
        y: 0
        width: parent.width
        height: parent.height/2
        spacing: 100
       Slide{
           id: slider
           anchors.horizontalCenter: parent.horizontalCenter
           width: parent.width
           height: parent.height/3
           tag:0
           tag_1:0

       }
       Button {
           id: button_1
           text: "ВЫКЛЮЧИТЬ"
           anchors.horizontalCenter: parent.horizontalCenter
           onClicked: slider.cheke_Off();
          // y:500
           //width: parent.width
           //height: parent.height/7
           //clicked: сдесь отправляем команду по кнопке....................../////////////////////////////////////
       }
       signal sendbut(bool tag)


//        #define         SW_KM_24_L      ( 1 << RB_ID_RK5 )
//        #define         SW_KM_24_R      ( 1 << RB_ID_RK4 )

//        #define         SW_KM_24_48   ( SW_KM_24_L | SW_KM_24_R )
//        #define         SW_KM_ALL_DC    ( SW_KM_24_48 )

//        #define         SW_KM_3F_L      ( 1 << RB_ID_RK8 )
//        #define         SW_KM_1F_L      ( 1 << RB_ID_RK9 )
//        #define         SW_KM_3F_R      ( 1 << RB_ID_RK6 )
//        #define         SW_KM_1F_R      ( 1 << RB_ID_RK7 )
//        #define         SW_KM_ALL_AC    ( SW_KM_3F_L | SW_KM_1F_L | SW_KM_3F_R | SW_KM_1F_R )


//        #define         SW_KM_LIGHTS            ( 1 << RB_ID_RK1 )
//        #define         SW_KM_STOP_ALARM        ( 1 << RB_ID_RK2 )
//        #define         SW_KM_BEEP              ( 1 << RB_ID_RK3 )
//        #define         SW_KM_FAN_DRV           ( 1 << RB_ID_FAN_DRV )
    }


    Row{
    spacing: 10
    CheckBox {
        id: ch_1
        checked:  false
        onCheckStateChanged: sendchlen(4);
        text: qsTr("SW_KM_24_L")
    }
    CheckBox {
        id: ch_2
        checked:  false
        onCheckStateChanged:  sendchlen(3);
        text: qsTr(" SW_KM_24_R ")
    }
    CheckBox {
        id: ch_3
        checked:  false
        onCheckStateChanged:  sendchlen(456);
        text: qsTr("SW_KM_24_48")
    }
    }
    Row{
        spacing: 10
    CheckBox {
        id: ch_4
        checked:  false
        onCheckStateChanged:  sendchlen(456);
        text: qsTr("SW_KM_ALL_DC")

    }

    CheckBox {
        id: ch_5
        checked:  false
        onCheckStateChanged:  sendchlen(7);
        text: qsTr("SW_KM_3F_L ")
    }
    CheckBox {
        id: ch_6
        checked:  false
        onCheckStateChanged: sendchlen(8);
        text: qsTr("SW_KM_1F_L ")
    }
    }
    Row{
        spacing: 10
    CheckBox {
        id: ch_7
        checked:  false
        onCheckStateChanged:  sendchlen(5);
        text: qsTr("SW_KM_3F_R ")
    }
    CheckBox {
        id: ch_8
        checked:  false
        onCheckStateChanged:  sendchlen(6);
        text: qsTr("SW_KM_1F_R")
    }
    CheckBox {
        id: ch_12
        checked:  false
        onCheckStateChanged:  sendchlen(2123);
        text: qsTr("SW_KM_ALL_AC ")
    }


    }
    Row{
        spacing: 10
    CheckBox {
        CheckBox {
            id: ch_9
            checked:  false
            onCheckStateChanged:  sendchlen(0);
            text: qsTr("SW_KM_LIGHTS")
        }
        id: ch_10
        checked:  false
        onCheckStateChanged:  sendchlen(1);
        text: qsTr(" SW_KM_STOP_ALARM")
    }
    CheckBox {
        id: ch_11
        checked:  false
        onCheckStateChanged:  sendchlen(2);
        text: qsTr("SW_KM_BEEP")
    }

    }
    Row{
    CheckBox {
        id: ch_13
        checked:  false
        onCheckStateChanged:  sendchlen(9);
        text: qsTr("SW_KM_FAN_DRV")
    }
    }

    }


    Connections {
           target: dataSource// Указываем целевое соединение
           /* Объявляем и реализуем функцию, как параметр
            * объекта и с имененем похожим на название сигнала
            * Разница в том, что добавляем в начале on и далее пишем
            * с заглавной буквы
            * */



       }
        onSendchlen: {
            dataSource.relay(k);
        }

}






/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
