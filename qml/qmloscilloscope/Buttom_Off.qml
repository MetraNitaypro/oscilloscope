import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    signal send_val(int tag,int cmd)
    property string name_1:"ad"
    property int value: 0
    property int tag:0
    Button{
        id:bt_1
        text: qsTr(name_1)

        anchors.horizontalCenter: parent.horizontalCenter


        onClicked: send_slide(10, tag)

    }
//    onSend_slide: {
//        //console.log(text + tag);

//    }
}
