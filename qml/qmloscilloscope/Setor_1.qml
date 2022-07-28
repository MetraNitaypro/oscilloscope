import QtQuick 2.4
import QtQuick.Controls 2.15
import QtQuick.Window 2.14
import QtCharts 2.3


Item {
    id: sets
    width: 150
    height: 100

    property string text: "Option: "
    TextField {
        id: textField
        x: 0
        y: 50
        width: 150
        height: 50
        onAccepted: {
          dataSource.kk(textField.text, sets.text)
        }
    }

    Text {
        id: text1
        x: 0
        y: 0
        width: 150
        height: 50
        text: sets.text
        font.pixelSize: 18
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.styleName: "Полужирный"
        font.family: "Courier"
    }


}
