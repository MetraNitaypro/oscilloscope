import QtQuick 2.4

import QtQuick.Controls 2.12
import QtQuick.Controls.Imagine 2.3
import QtQuick.Extras 1.4
Item {
    width: 400
    height: 400


    Slider {
        id: control
        value: 0
       // stepSize:10

        background: Rectangle {
            x: control.leftPadding
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: 200
            implicitHeight: 4
            width: control.availableWidth
            height: implicitHeight*2
            radius: 2
            color: "#bdbebf"
           // scale: 2

            Rectangle {
                width: control.visualPosition * parent.width/2
                height: parent.height
                color: "#21be2b"
                radius: 2


            }
        }

        handle: Rectangle {
            x: control.leftPadding + control.visualPosition * (control.availableWidth - width)
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            radius: 50
           // color: control.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }
    }

    Gauge {
        id: gauge
          implicitWidth: 200
        x: 0
        y: 14
        width: 200
        height: 48
        layer.format: ShaderEffectSource.RGBA
        orientation: Qt.Horizontal
    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:2}
}
##^##*/
