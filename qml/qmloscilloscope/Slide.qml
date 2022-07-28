import QtQuick 2.4
import QtQuick.Controls 2.15
import QtQuick.Extras 1.4
Column {
        signal cheke_Off();
        property int tag: 0
        property int tag_1: 0
        property bool ch: false
        property bool flag_1: false
        property bool k_1: checkBox.checked
        property bool k_2: checkBox1.checked
        property CheckBox k_3: checkBox2
        property int k_911: 3
    Text{
        id:text1
        text:"From - " + slider.value + " To - " + slider.str_f
        font.pointSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
    }
    signal moveded(int val);
    signal maxval(int val);
    Slider {
        id: slider
        anchors.horizontalCenter: parent.horizontalCenter
        snapMode :Slider.SnapAlways
        width: parent.width
        height: parent.height
        to: 100
        from: 0
        stepSize: 1
        value: 0
        onMoved: moveded(slider.value)
        property int timesed:0
        property int name: 0
        property int size: 100
        property int str_f: 0
        property int str_s: 0
        property int maxval_1: 100
        Gauge {
            id: gauge
            width: parent.width
            height: parent.height
            layer.format: ShaderEffectSource.RGBA
            orientation: Qt.Horizontal
        }
    }
    onMaxval: {

        slider.maxval_1 = val;
    }
    onMoveded: {
//        if(!flag_1 && tag != 1){
//            slider.value = 0;
//            slider.str_f = 0;
//            slider.str_s = 0;
//            return;
//        }

        if(checkBox2.checked){
            slider.value = 0;
            slider.str_f = 0;
            slider.str_s = 0;
            return;
        }
        if(!checkBox.a){
            slider.value = 0;
        }
        if(slider.value>slider.maxval_1){
            slider.value = slider.maxval_1;
            slider.str_f = slider.value;
        }
        if(slider.value >= slider.str_f){
            slider.str_f = slider.value;
            slider.value = slider.str_s;
        }
        else if(slider.value <= slider.str_s){
            slider.str_f = slider.value;
            slider.str_s = slider.value;
        }
        else{
            slider.str_f = slider.value;
            slider.value = slider.str_s;
        }
    }
    ListModel {
            id: dataModel
            property int arg:0
            //dynamicRoles: true
            Component.onCompleted: {
                for(var i = 0 ; i < slider.size; i++) dataModel.append({arg:i});
            }
        }
    Timer {
        id: refreshTimer
        interval: 200
        running: true
        repeat: true
        onTriggered: {
            if(!flag_1 && tag != 0){
                slider.value = 0;
                slider.str_f = 0;
                slider.str_s = 0;
                return;
            }
            if(checkBox2.checked){
                slider.value = 0;
                slider.str_f = 0;
                slider.str_s = 0;
                return;
            }
            if(!checkBox.a){
                slider.value = 0;
                slider.str_f = 0;
                slider.str_s = 0;
                return;
            }
            if(slider.str_f > slider.maxval_1){
                slider.str_f = slider.maxval_1;
            }
            if(slider.str_s > slider.str_f){
                slider.str_s = slider.str_f;
                slider.value = slider.str_s;
            }
            if(slider.str_s < slider.str_f){
                slider.str_s += slider.stepSize;
                slider.value = slider.str_s;
            }
            if (!(slider.timesed == slider.value)){
                dataSource.slide(tag, tag_1, slider.value,k_911 )
                //отправка значения///////////////////////////////////////////
                slider.timesed = slider.value;
            }
        }
    }
    signal cheke(bool a, int k);
    Row {
       id: row
       width: parent.width
       height: parent.height
       property int manual_123: 0;
       property int auto: 0;
       property int off: 0;
       anchors.horizontalCenter: parent.horizontalCenter
        CheckBox {
            property int a: 1;
            id: checkBox
            width: parent.width/3
            height: parent.height/3
            text: qsTr("Manual")
            checked: false
            onCheckStateChanged:cheke(checked, 1)
        }
        CheckBox {
            id: checkBox1
            width: parent.width/3
            height: parent.height/3
            text: qsTr("Auto")
            checked: false
            onCheckStateChanged:cheke(checked, 2)
        }
        CheckBox {
            id: checkBox2
            width: parent.width/3
            height: parent.height/3
            text: qsTr("off")
            checked: true
            onCheckStateChanged:cheke(checked, 0)
        }
    }
    property int jjj : 0
    signal prr();
    onPrr:{
    checkBox1.checked = false;
    checkBox.checked = false;
    checkBox2.checked  =  true;
    k_911 = 0;
    return;
    }

    onCheke:{
        if(!flag_1 && tag != 0){
            checkBox1.checked = false;
            checkBox.checked = false;
            checkBox2.checked  =  true;
            k_911 = 0;
            return;
        }
       // if(!flag_1) return;
            // console.log(flag_1);
            if(k == 2 && checkBox1.checked){
                checkBox2.checked = false;
                checkBox.checked = false;
                k_911 = 2;
                dataSource.slide(tag, tag_1, slider.value, k_911 )
            }
            else if(k == 1 && checkBox.checked){
                checkBox2.checked =  false;
                checkBox1.checked = false;
                k_911 = 1;
                dataSource.slide(tag, tag_1, slider.value, k_911 )
            }
            else if(k == 0 && checkBox2.checked){
                checkBox1.checked = false;
                checkBox.checked = false;
                slider.value = 0;
                slider.str_f = 0;
                slider.str_s = 0;
                slider.timesed = 0;
                k_911 = 0;
                dataSource.slide(tag, tag_1, slider.value, k_911 )

                //отправляем значение////////////////////////////////////////////////////////////////
            }
            if (!(checkBox2.checked || checkBox.checked || checkBox1.checked)){
                checkBox2.checked  =  true;
                k_911 = 0;
                slider.value = 0;
                slider.str_f = 0;
                slider.str_s = 0;
                slider.timesed = 0;
                 dataSource.slide(tag, tag_1, slider.value, k_911 )
                //dataSource.slide(tag, slider.value)
                //отправляем значение////////////////////////////////////////////////////////////////

        }
    }
    onCheke_Off:{
        checkBox2.checked = true;
        checkBox.checked = false;
        checkBox1.checked = false;
        k_911 = 0;
        slider.value = 0;
        slider.str_f = 0;
        slider.str_s = 0;
        slider.timesed = 0;
        console.log("adf")
       // dataSource.slide(tag, tag_1, slider.value, k_911 )
        ///////////////////////отправка значения////////////////////////////////////
    }
}

