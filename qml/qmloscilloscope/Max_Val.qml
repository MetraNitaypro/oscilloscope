import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    id:it_1
    anchors.horizontalCenter: parent.horizontalCenter
    property int tag:0
    signal send_slide(int tag_1, int val)
    TextField{
        id:texxt_1
        placeholderText: "Max Value"
        anchors.horizontalCenter: parent.horizontalCenter
        onTextChanged: send_slide(tag, text)
    }

}
