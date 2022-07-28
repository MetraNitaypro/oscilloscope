import QtQuick 2.0
import QtQuick.Controls 2.15
Item {
    id:chlen
    anchors.horizontalCenter: parent.horizontalCenter  
    property int tag: 0
    property int time: 0
    property bool ch_1: checkBox1.checked
    property bool ch_2: checkBox2.checked
    property bool ch_3: checkBox3.checked
    property bool ch_11: false
    property bool ch_22: false
    property bool ch_33: false
    property bool flag_1: true
    property bool flag_11: false
    property bool flag_22: false
    property bool flag_33: false
    property bool ar: true
    signal sendval(int t, bool ch_111, bool ch_222, bool ch_333)
    signal send(int a)
    signal timer()
    signal send_111()
        Row{
            id:qwwe
            anchors.horizontalCenter: parent.horizontalCenter
            Text{
                id: text_1
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("INVERTOR")
            }
        CheckBox {
            id: checkBox1
            onCheckStateChanged: sendval(1, checkBox1.checked, checkBox2.checked, checkBox3.checked)
            checked: false
            text: qsTr("Ch_1")
        }
        CheckBox {
            id: checkBox2
            checked:  false
            onCheckStateChanged: sendval(2, checkBox1.checked, checkBox2.checked, checkBox3.checked)
            text: qsTr("Ch_2")
        }
        CheckBox {
            id: checkBox3
            checked:  false
            onCheckStateChanged: sendval(3, checkBox1.checked, checkBox2.checked, checkBox3.checked)
            text: qsTr("Ch_3")
            visible: ar
        }
        TextField{
            id:qwrdf
            placeholderText: "delay"
            onTextChanged: send(text)
            validator: RegExpValidator{regExp: /[0-9]+/}
            color:"green"
        }
        }
    onSend: {
              refreshTimer.interval = a
     }
    onSendval: {
      if((t == 1 && ch_11)||(t == 2 && ch_22)||(t == 3 && ch_33)){
       if(t == 1 && ch_11){
           checkBox1.checked = true

       }
       if(t == 2 && ch_22) {
           checkBox2.checked = true

       }
       if(t == 3 && ch_33) {
           checkBox3.checked = true

       }
       return
      }


        if(flag_1) dataSource.invertor(tag , checkBox1.checked, checkBox2.checked, checkBox3.checked)

    }
    onTimer: {
        refreshTimer.start()
    }
    Timer {
        id: refreshTimer
        interval: 200
        //running: true
        repeat: true
        onTriggered: {
            flag_1 = false
            //console.log("f");
            checkBox1.checked = false
            checkBox2.checked = false
            checkBox3.checked = false
            dataSource.invertor(tag , checkBox1.checked, checkBox2.checked, checkBox3.checked)
            flag_1 = true
            stop()
        }
    }

}
