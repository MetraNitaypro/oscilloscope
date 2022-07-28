import QtQuick 2.4
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Window 2.14
Item {
    id:it_1
    anchors.fill: parent
    property Main a:sdf.at
    Column{
        id: cl_1
        width: parent.width
        height: parent.height
    Row {
        id: row
        width: parent.width
        height: parent.height/2
        Column{
            width:  parent.width/4
            height: parent.height
            Text{
                text:"ACDC"
                font.pointSize: 26
                width:  parent.width
                height: parent.height/10
            }
        ACDCForm {
            id: aCDCForm
            width:  parent.width
            height: parent.height*9/10
        }
        }
        Column{
            width:  parent.width*3/4
            height: parent.height
            Text{
                text:"DCAC"
                font.pointSize: 26
                width:  parent.width
                height:parent.height/10
            }
        DCACForm{
            id: sdff
            width:  parent.width
            height:parent.height*9/10
            layer.textureMirroring: ShaderEffectSource.MirrorVertically
            transformOrigin: Item.Top
            scale: 1
        }
       }
    }
    Column{
        width:  parent.width
        height:parent.height/2
        Text{
            text:"DCDC"
            font.pointSize: 26
            width:  parent.width
            height: parent.height/10
        }
    DCDCForm{
        id: sdf
        width:  parent.width
        height: parent.height*9/10
    }
    }
    }
}




/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
