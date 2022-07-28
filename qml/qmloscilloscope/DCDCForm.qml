import QtQuick 2.4
import QtQuick.Controls 2.15
Rectangle{
    id:adf
    border.width: 1
    signal send_1(int val)
    property  Main at: man_1
    Row{
        width: parent.width
        height: parent.height
Column {
 id: er
 width: parent.width/2
 height: parent.height
Row{
    id: ro
    width: parent.width
    height: parent.height*2/4
    Rectangle{
        width: parent.width/2
        height: parent.height
        border.width: 1
    Column {
        id: column_1
        width: parent.width
        height: parent.height/2
        spacing: 70
        Slide {
           id: slider_1
           anchors.horizontalCenter: parent.horizontalCenter
           width: parent.width
           height: parent.height/2
           tag:1
           tag_1:1
           flag_1: qwe.ch_1
        }
     signal send(int a)
        Button {
            id: button_3
            text: "ВЫКЛЮЧИТЬ"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: slider_1.cheke_Off();
        }
    }
     }
    Rectangle{
        width: parent.width/2
        height: parent.height
        border.width: 1
    Column {
        id: column
        spacing: 70
        width: parent.width
        height: parent.height/2
        Slide {
           id: slider
           anchors.horizontalCenter: parent.horizontalCenter
           width: parent.width
           height: parent.height/2
           tag:1
           tag_1:2
           flag_1: qwe.ch_2
        }
        Button {
            id: button_1
            text: "ВЫКЛЮЧИТЬ"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: slider.cheke_Off();
        }
    }
    }
}
Rectangle{
    width: parent.width/2
    height: parent.height*2/4
    border.width: 1

Column{
    id: ro_1
    width: parent.width
    height: parent.height
    spacing: 10
//anchors.horizontalCenter: parent.horizontalCenter
    Invertor{
        id:qwe
        width: parent.width
        height: parent.height/5
        anchors.horizontalCenter: parent.horizontalCenter
        tag: 1
        ch_11: !(slider_1.k_3.checked)
        ch_22: !(slider.k_3.checked)
        ar:false
        onSend_111: {
        }
    }
    TextField{
        property string col:"green"
        id:texxt_1
        placeholderText: "Max_Val"
        text: ""
        anchors.horizontalCenter: parent.horizontalCenter
        onTextChanged: adf.send_1(text)
        validator: RegExpValidator{regExp: /[0-9]+/}
        color:col
    }
    signal off();
    onOff: {
        if((!qwe.ch_1 && !qwe.ch_2 && !qwe.ch_3)){
            return
        }
        slider.cheke_Off();
        slider_1.cheke_Off();
        dataSource.slide(slider.tag, 3, 0, 0)
        //dataSource.slide(tag, tag_1, slider.value, k_911 )
        qwe.timer()
    }
    Button {
        id: button_2
        text: "ВЫКЛЮЧИТЬ"
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: ro_1.off()
    }
}
    }
}
Item{
    id: it_12
    width: parent.width/2
    height: parent.height
    Main{
        id:man_1
    }
}
}
onSend_1: {
    if(val >= 0 && val <=100){
    texxt_1.color = "green"
    texxt_1.update();
    slider.maxval(val);
    slider_1.maxval(val);
    }
    else{
        texxt_1.color = "red"
        texxt_1.update();
    }
}
}





/*##^##
Designer {
    D{i:0;formeditorZoom:0.75;height:500;width:1000}
}
##^##*/
