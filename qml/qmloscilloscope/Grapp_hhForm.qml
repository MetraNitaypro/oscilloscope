import QtQuick 2.4
import QtQuick.Controls 2.15
import QtCharts 2.3
Item {
    id:it_1
    width: 1000
    height: 1000
    anchors.fill: parent
    signal kk()
    property double x_1:0
    property double x_2:0
    property double y_1:0
    property double y_2:0
    signal send()
    onKk: {
//        console.log(mouse_1.mouseX)
//        spline.zoomIn(Qt.rect())
        x_1 = mouse_1.mouseX
        y_1 = mouse_1.mouseY
        x_2 = mouse_1.mouseX + 10
        y_2 = mouse_1.mouseY + 10
        spline.zoomIn(Qt.rect(x_1,y_2,x_2,y_2))
        console.log(x_1,y_1,x_2,y_2)
    }
    //visible: false
    Column{
        width: parent.width
        height: parent.height
        ComboBox {
            currentIndex: 0
            model: ListModel {
                id: model_2
                ListElement { text: "ACDC_CALC" }
                ListElement { text: "DCDC_CALC" }
                ListElement { text: "DCAC_CALC" }
                ListElement { text: "ACDC_RAW" }
                ListElement { text: "DCDC_RAW" }
                ListElement { text: "DCAC_RAW" }
            }
            onCurrentIndexChanged:signalSourceChanged(0, currentIndex, 0);
        }
    Row {
        id: row
        x: 0
        y: 0
        width: parent.width
        height: parent.height/2.5
        ChartView {
            id: spline
           //  plotAreaColor : "green"
            animationOptions: ChartView.noAnimation
            theme: ChartView.ChartThemeDark
            property bool openGL: true
            property bool openGLSupported: true
            width: parent.width/2
            height: parent.height
             MouseArea{
                 property bool flag_123:false
                 property int yy: 0
                 property int xx: 0
                 property double d:0
                 property double d_1:0
                 id:mouse_1
                 width: spline.plotArea.width
                 height: spline.plotArea.height
                 x:spline.plotArea.x
                 y:spline.plotArea.y
                 onDoubleClicked: {
                     spline.zoomReset()
                 }
                 onPressAndHold: {


                 }
                 onPressed: {
                      console.log(11111)
                     flag_123 = true
                     xx = mouse.x
                     yy = mouse.y
                 }
                 onReleased: {
                     console.log(1241)
                     flag_123 = false
                 }
                 onPositionChanged: {
                     d = (axisX.max - axisX.min)/100
                     d_1 = (axisY2.max - axisY2.min)/100
                    // console.log(d)
                     if(flag_123){
                         if(xx > mouse.x){
                            axisX.max += d
                            axisX.min += d
                         }
                         else if(xx < mouse.x){
                             axisX.max-=d
                             axisX.min-=d
                         }
                         if(yy > mouse.y){
                             axisY2.max -= d_1
                             axisY2.min -= d_1
                         }
                         else if(yy < mouse.y){
                             axisY2.max += d_1
                             axisY2.min += d_1
                         }
                         xx = mouse.x
                         yy = mouse.y
                     }
                     //console.log(mouse.x)
                 }
                 onWheel: {
                     console.log(spline.plotArea)
                     x_1 = wheel.x
                     y_1 = wheel.y
                     x_2 = wheel.x
                     y_2 = wheel.y
                     //spline.plotArea = Qt.rect(100,100,100,100)
                     if(wheel.angleDelta.y > 0) spline.zoomIn()
                     if(wheel.angleDelta.y < 0) spline.zoomOut()
                     console.log(spline.plotArea)

                     spline.update()
                 }
             }
            ValueAxis {
                id: axisY1
                min: -1
                max: 11
            }
            ValueAxis {
                id: axisY2
                min: -1
                max: 11
            }

            ValueAxis {
                id: axisX
                min: 0
                max: 1000
            }

            LineSeries {
                id: lineSeries1
                name: "signal 1"
                axisX: axisX
                axisY: axisY2
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries2
                name: "signal 2"
                axisX: axisX
                axisYRight: axisY2
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries3
                name: "signal 3"
                axisX: axisX
                axisYRight: axisY2
               // useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries4
                name: "signal 4"
                axisX: axisX
                axisYRight: axisY2
               // useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries5
                name: "signal 5"
                axisX: axisX
                axisYRight: axisY2
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries6
                name: "signal 6"
                axisX: axisX
                axisYRight: axisY2
                //useOpenGL: chartView.openGL
            }

            LineSeries {
                id: lineSeries7
                name: "signal 7"
                axisX: axisX
                axisYRight: axisY2
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries8
                name: "signal 8"
                axisX: axisX
                axisYRight: axisY2
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries9
                name: "signal 9"
                axisX: axisX
                axisYRight: axisY2
               // useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries10
                name: "signal 10"
                axisX: axisX
                axisYRight: axisY2
               // useOpenGL: chartView.openGL
            }

        }

        ChartView {
            id: spline1

            animationOptions: ChartView.noAnimation
            theme: ChartView.ChartThemeDark
            property bool openGL: true
            property bool openGLSupported: true
            width: parent.width/2
            height: parent.height
            MouseArea{
                property double dd:0
                property double d_11:0
                property bool flag_123:false
                property int yy: 0
                property int xx: 0
                id:mouse_11
                width: spline.plotArea.width
                height: spline.plotArea.height
                x:spline.plotArea.x
                y:spline.plotArea.y
                onDoubleClicked: {
                    spline1.zoomReset()
                }
                onPressAndHold: {


                }
                onPressed: {
                     console.log(11111)
                    flag_123 = true
                    xx = mouse.x
                    yy = mouse.y
                }
                onReleased: {
                    console.log(1241)
                    flag_123 = false
                }

                onPositionChanged: {
                    dd = (axisXx.max - axisXx.min)/100
                    d_11 = (axisY22.max - axisY22.min)/100
                    if(flag_123){
                        if(xx > mouse.x){
                            axisXx.max += dd
                            axisXx.min += dd

                        }
                        else if(xx < mouse.x){
                            axisXx.max -= dd
                            axisXx.min -= dd
                        }

                        if(yy > mouse.y){
                            axisY22.max -= d_11
                            axisY22.min -= d_11
                        }
                        else if(yy < mouse.y){
                            axisY22.max += d_11
                            axisY22.min += d_11
                        }
                        xx = mouse.x
                        yy = mouse.y

                    }
                    console.log(mouse.x)
                }
                onWheel: {
                      console.log(spline.plotArea)
                      x_1 = wheel.x
                      y_1 = wheel.y
                      x_2 = wheel.x
                      y_2 = wheel.y
                    //spline.plotArea = Qt.rect(100,100,100,100)
                      if(wheel.angleDelta.y > 0)spline1.zoomIn()
                      if(wheel.angleDelta.y < 0)spline1.zoomOut()
                      console.log(spline.plotArea)

                      spline1.update()
                }
            }
            ValueAxis {
                id: axisY11
                min: -1
                max: 11
            }

            ValueAxis {
                id: axisY22
                min: -1
                max: 11
            }

            ValueAxis {
                id: axisXx
                min: 0
                max: 1000
            }

            LineSeries {
                id: lineSeries11
                name: "signal 1"
                axisX: axisXx
                axisY: axisY22
               // useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries22
                name: "signal 2"
                axisX: axisXx
                axisYRight: axisY22
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries33
                name: "signal 3"
                axisX: axisXx
                axisYRight: axisY22
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries44
                name: "signal 4"
                axisX: axisXx
                axisYRight: axisY22
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries55
                name: "signal 5"
                axisX: axisXx
                axisYRight: axisY22
               // useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries66
                name: "signal 6"
                axisX: axisXx
                axisYRight: axisY22
                //useOpenGL: chartView.openGL
            }

            LineSeries {
                id: lineSeries77
                name: "signal 7"
                axisX: axisXx
                axisYRight: axisY22
               // useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries88
                name: "signal 8"
                axisX: axisXx
                axisYRight: axisY22
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries99
                name: "signal 9"
                axisX: axisXx
                axisYRight: axisY22
                //useOpenGL: chartView.openGL
            }
            LineSeries {
                id: lineSeries101
                name: "signal 10"
                axisX: axisXx
                axisYRight: axisY22
                //useOpenGL: chartView.openGL
            }
        }

    }
    Column{
        id: col_1
        width: parent.width
        height: parent.height/2
        y:parent.height/2
        Row{
            x:10
            spacing:10
//            width: parent.width*3/4
//            height: parent.height/6

            Column{
            Text {

                //anchors.verticalCenter : text_1.verticalCenter
                font.pointSize: 15
                text: qsTr("CPU_Freq")
            }
            TextField{
                 id : cpu_freg

            }
            }
            Column{
            Text {

                //anchors.verticalCenter : text_1.verticalCenter
                font.pointSize: 15
                text: qsTr("ADC_div")
            }
            TextField{
                id : adc_div

            }
            }
            Column{
            Text {

                //anchors.verticalCenter : text_1.verticalCenter
                font.pointSize: 15
                text: qsTr("ADC_Cycles")
            }
            TextField{
                 id : adc_cycles
            }
            }
            CheckBox{
                id: avg
                text: "AVG"
            }
            CheckBox{
                  id: rms
                  text: "RMS"
                 // x:
            }
            CheckBox{
                  id: vpp
                  text: "VPP"
                 // x:
            }
        }
        Row{
            x:10
            spacing:10
            width: parent.width*3/4
            height: parent.height/6
            CheckBox{
                  id: fixed_point
                  text: "Fixed Point"
                  anchors.verticalCenter : parent.verticalCenter
                 // x:


            }
            Column{
            Text {
                text: qsTr("Frac bits")
                anchors.verticalCenter : ch_4.verticalCenter
                font.pointSize: 15

            }
            TextField{
                id: frac_bits


            }
            }
            Column{
            Text {
                anchors.verticalCenter : text_1.verticalCenter
                font.pointSize: 15
                text: qsTr("Channels count")
            }
            TextField{
                 id : channels_count
            }
            }
            Column{
            Text {
                font.pointSize: 15
                text: qsTr("Pack_Size")
            }
            TextField{
                 id : pack_size
            }

            }
        }
        Row{
            x:10
            spacing:10
            width: parent.width*3/4
            height: parent.height/6
            Column{
            Text {
               // anchors.verticalCenter : parent.verticalCenter
                font.pointSize: 15
                text: qsTr("ADC_Freq_Max")
            }
            TextField{
                 id : adc_freq_max

            }
            }
        }
        Row{
            x:10
            spacing:10
            width: parent.width*3/4
            height: parent.height/6
            Column{
            Text {
                //anchors.verticalCenter : parent.verticalCenter
                font.pointSize: 15
                text: qsTr("Avg_Size")
            }
            TextField{
                 id : avg_size
            }
            }
            Column{
            Text {
                //anchors.verticalCenter : parent.verticalCenter
                font.pointSize: 15
                text: qsTr("Window_Size")
            }
            TextField{
                 id : window_size
            }
            }
            }
        Row{
            spacing:10
            x:10
            width: parent.width*3/4
            height: parent.height/6
            Column{
            Text {
               // anchors.verticalCenter : text_1.verticalCenter
                font.pointSize: 15
                text: qsTr("offset")
            }
            TextField{
                 id : offset
            }
            }
            Column{
            Text {
                anchors.verticalCenter : text_1.verticalCenter
                font.pointSize: 15
                text: qsTr("fk")
            }
            TextField{
                id:fk
            }
            }


            }
        Row{
            x:10
            spacing:10
            width: parent.width*3/4
            height: parent.height/6

            Column{
            Text {
                anchors.verticalCenter : text_1.verticalCenter
                font.pointSize: 15
                text: qsTr("koef")
            }
            TextField{
                 id : koef
            }
            }
                Button{
                    y:koef.y
                    id: bt_1
                    text:"sendVal"
                    onClicked: send()
                }
            }
        }


    }

    onSend:{
        dataSource.raw_data(cpu_freg.text,  adc_div.text,  adc_cycles.text,  avg.checked,
                            rms.checked,  vpp.checked,  fixed_point.checked,  frac_bits.text,
                            channels_count.text,  pack_size.text,  adc_freq_max.text,  avg_size.text,
                            window_size.text,  offset.text,  fk.text,  koef.text)

    }
   }




/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
