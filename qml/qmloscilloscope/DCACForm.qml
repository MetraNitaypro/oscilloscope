import QtQuick 2.4
import QtQuick.Controls 2.15
Rectangle{
    id:adf
    border.width: 1
    signal send_1(int val)
Column{
    id:cl_12
    width: parent.width
    height: parent.height
    spacing: 10
Row{
    id: ro
    width: parent.width
    height: parent.height*2/4
    Rectangle {
        border.width: 1
        width: parent.width/3
       height: parent.height
    Column {
        id: column_1
        width: parent.width
        height: parent.height*2/4*3/4
        spacing: 100
        Slide {
           id: slider_1
           anchors.horizontalCenter: parent.horizontalCenter
           width: parent.width
           height: parent.height*3/4
           tag: 2
           tag_1: 1
           flag_1: inv_1.ch_1
           //ch:inv_1.ch_1
        }
        Button {
            id: button_3
            text: "ВЫКЛЮЧИТЬ"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: slider_1.cheke_Off();
        }
    }
    }
    Rectangle {
        border.width: 1
        width: parent.width/3
        height: parent.height
    Column {
        id: column_111
        width: parent.width
        height: parent.height*2/4*3/4
        spacing: 100
        Slide{
            id: slider_111
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            height: parent.height*3/4
            tag:2
            tag_1: 2
            flag_1: inv_1.ch_2
            //ch:inv_1.ch_2
        }
        Button {
            id: button_2
            text: "ВЫКЛЮЧИТЬ"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: slider_111.cheke_Off();
        }
    }
}
    Rectangle {
       border.width: 1
       width: parent.width/3
       height: parent.height
    Column {
        id: column
        width: parent.width
        height: parent.height*2/4*3/4
        spacing: 100
        Slide {
            id: slider
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            height: parent.height*3/4
            tag: 2
            tag_1: 4
            flag_1: inv_1.ch_3
           // ch:inv_1.ch_3
        }
        Button{
            id: button_1
            text: "ВЫКЛЮЧИТЬ"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: slider.cheke_Off();
        }
}
}
}
Invertor{
    id:inv_1
    width: parent.width
    height: parent.height/8
    tag:2

    ch_11: !(slider_1.k_3.checked)
    ch_22: !(slider_111.k_3.checked)
    ch_33: !(slider.k_3.checked)
    onSend_111: {


    }
}

TextField{
    id:qwrdf
    placeholderText: "Max_Val"
    anchors.horizontalCenter: parent.horizontalCenter
    onTextChanged: send_1(text)
    validator: RegExpValidator{regExp: /[0-9]+/}
    color:"green"
}
signal off();
onOff: {
    if((!inv_1.ch_1 && !inv_1.ch_2 && !inv_1.ch_3)){
        return
    }
    slider.cheke_Off();
    slider_1.cheke_Off();
    slider_111.cheke_Off();
    dataSource.slide(slider.tag, 7, 0, 0 )
    //dataSource.slide(slider.tag, 3, 0, 0)
    //dataSource.slide(tag, tag_1, slider.value, k_911 )
    inv_1.timer();

}
Button{
   id:fvsjn
   text:"ВЫКЛЮЧИТЬ"
   anchors.horizontalCenter: parent.horizontalCenter
   onClicked: cl_12.off();
}
}
onSend_1: {
    if(val >= 0 && val <=100){
    qwrdf.color = "green";
    qwrdf.update();
    slider.maxval(val);
    slider_1.maxval(val);
    slider_111.maxval(val);
    }
    else{
        qwrdf.color = "red";
        qwrdf.update();
    }

}

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.66;height:480;width:640}
}
##^##*/
