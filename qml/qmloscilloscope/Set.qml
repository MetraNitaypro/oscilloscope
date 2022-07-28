import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
Item {
    id:it_1
    anchors.fill: parent
    signal ad(string  a)
    signal add()
    Column{
        width: parent.width
        height:parent.height
    MultiButton {
        anchors.horizontalCenter: parent.horizontalCenter
        id: buttomwe
        text: "COM_Avaible"
        items: ["Load"]
        enabled: true
        currentSelection: 0
        onSelectionChanged: add();
    }
    ComboBox {
        anchors.horizontalCenter: parent.horizontalCenter
        currentIndex: 10
        id:asd
        model: ListModel {
            id: model
        }
        onCurrentIndexChanged: ad(model.get(currentIndex).text);
    }
    }
    onAdd:{
        model.clear();
        dataSource.portInf();
    }
    onAd: {
        dataSource.setPort(a)
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


       }
}
