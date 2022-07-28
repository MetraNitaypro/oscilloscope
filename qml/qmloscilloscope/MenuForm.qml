import QtQuick 2.4
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
Item {
    signal show(int k)
    width: parent.width
    height: parent.height

    Column{
        width: parent.width
        height: parent.height
    Row{
        width: parent.width
        height: parent.height/10
    Button{
        id:bt_1
        text:"1"
        property string a: "red"
        style: ButtonStyle {
            id:e
            background: Rectangle {
                id:qe
                      implicitWidth: 100
                      implicitHeight: 25
                      border.width: control.activeFocus ? 2 : 1

                      color: "green"
                      radius: 4
                      gradient: Gradient {
//                          GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
//                          GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                      }
                  }


        }
        onClicked: show(1)
    }
    Button{
         id:bt_2
         text:"2"
         onClicked: show(2)
    }
    Button{
         id:bt_3
         text:"3"
         onClicked: show(3)
    }
    Button{
         id:bt_4
         text:"4"
         onClicked: show(4)
    }
    }
    Item{
        width: parent.width
        height: parent.height*9/10
    PanelForm{
        id: win_1
        width: parent.width
        height: parent.height
        visible: false
    }
    Grapp_hhForm{
        id: win_2
        visible: false
        width: parent.width
        height: parent.height
    }
    Main{
        id: win_3
        width: parent.width
        height: parent.height
    }
    Set{
        id: win_4
        width: parent.width
        height: parent.height
        visible: false
    }
    }
    }
    onShow:{
        if(k == 1){
            win_1.visible = true
            win_2.visible = false
            win_3.visible = false
            win_4.visible = false


        }
        if(k == 2){
            win_2.visible = true
            win_1.visible = false
            win_3.visible = false
            win_4.visible = false
        }
        if(k == 3){
            win_3.visible = true
            win_2.visible = false
            win_1.visible = false
            win_4.visible = false
        }
        if(k == 4){
            win_3.visible = false
            win_2.visible = false
            win_1.visible = false
            win_4.visible = true
        }
    }
}
