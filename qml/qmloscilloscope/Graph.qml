import QtQuick 2.0
import QtCharts 2.3

Item {
    ChartView {
        id: line
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        animationOptions: ChartView.noAnimation
        theme: ChartView.ChartThemeDark

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
            //useOpenGL: line.openGL
        }
        LineSeries {
            id: lineSeries2
            name: "signal 2"
            axisX: axisX
            axisYRight: axisY2
            //useOpenGL: line.openGL
        }
        LineSeries {
            id: lineSeries3
            name: "signal 3"
            axisX: axisX
            axisYRight: axisY2
            //useOpenGL: line.openGL
        }
        LineSeries {
            id: lineSeries4
            name: "signal 4"
            axisX: axisX
            axisYRight: axisY2
           // useOpenGL: line.openGL
        }
        LineSeries {
            id: lineSeries5
            name: "signal 5"
            axisX: axisX
            axisYRight: axisY2
           // useOpenGL:line.openGL
        }
        LineSeries {
            id: lineSeries6
            name: "signal 6"
            axisX: axisX
            axisYRight: axisY2
           // useOpenGL: line.openGL
        }

        LineSeries {
            id: lineSeries7
            name: "signal 7"
            axisX: axisX
            axisYRight: axisY2
           // useOpenGL: line.openGL
        }
        LineSeries {
            id: lineSeries8
            name: "signal 8"
            axisX: axisX
            axisYRight: axisY2
           // useOpenGL: line.openGL
        }
        LineSeries {
            id: lineSeries9
            name: "signal 9"
            axisX: axisX
            axisYRight: axisY2
           // useOpenGL:line.openGL
        }
        LineSeries {
            id: lineSeries10
            name: "signal 10"
            axisX: axisX
            axisYRight: axisY2
           // useOpenGL: line.openGL
        }
}
    Timer {
        id: refreshTimer
        interval: 1000 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
            dataSource.update(0,line.series(0));
            dataSource.update(1,line.series(1));
            dataSource.update(2,line.series(2));
            dataSource.update(3,line.series(3));
            dataSource.update(4,line.series(4));
            dataSource.update(5,line.series(5));
            dataSource.update(6,line.series(6));
            dataSource.update(7,line.series(7));
            dataSource.update(8,line.series(8));
            dataSource.update(9,line.series(9));


        }
    }

}
