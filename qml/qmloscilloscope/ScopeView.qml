/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtCharts 2.1

//![1]
ChartView {
    id: chartView
    //animationOptions: ChartView.noAnimation
    theme: ChartView.ChartThemeBlueCerulean
    property bool openGL: true
    property bool openGLSupported: true
    MouseArea{
        property bool flag_123:false
        property int yy: 0
        property int xx: 0
        property double ddd:0
        property double d_111:0
        id:mouse_11
        width: chartView.plotArea.width
        height: chartView.plotArea.height
        x:chartView.plotArea.x
        y:chartView.plotArea.y
        onDoubleClicked: {
            chartView.zoomReset()
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
            ddd = (axisX.max - axisX.min)/200
            d_111 = (axisY2.max - axisY2.min)/200
            if(flag_123){
                if(xx > mouse.x){
                    axisX.max += ddd
                    axisX.min += ddd

                }
                else if(xx < mouse.x){
                    axisX.max -= ddd
                    axisX.min -= ddd
                }

                if(yy > mouse.y){
                    axisY2.max -= d_111
                    axisY2.min -= d_111
                }
                else if(yy < mouse.y){
                    axisY2.max += d_111
                    axisY2.min += d_111
                }
                xx = mouse.x
                yy = mouse.y

            }
            console.log(mouse.x)
        }
        onWheel: {
             //console.log(spline.plotArea)
//            x_1 = wheel.x
//            y_1 = wheel.y
//            x_2 = wheel.x
//            y_2 = wheel.y
            //spline.plotArea = Qt.rect(100,100,100,100)
            if(wheel.angleDelta.y > 0)chartView.zoomIn()
            if(wheel.angleDelta.y < 0)chartView.zoomOut()
            console.log(11111111111111111111111111)

            chartView.update()
        }
    }
    onOpenGLChanged: {
        if (openGLSupported) {
            series("signal 1").useOpenGL = openGL;
            series("signal 2").useOpenGL = openGL;
            series("signal 3").useOpenGL = openGL;
            series("signal 4").useOpenGL = openGL;
            series("signal 5").useOpenGL = openGL;
            series("signal 6").useOpenGL = openGL;
            series("signal 7").useOpenGL = openGL;
            series("signal 8").useOpenGL = openGL;
            series("signal 9").useOpenGL = openGL;
            series("signal 10").useOpenGL = openGL;
        }
    }
    Component.onCompleted: {
        if (!series("signal 1").useOpenGL) {
            openGLSupported = false
            openGL = false
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
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries2
        name: "signal 2"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries3
        name: "signal 3"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries4
        name: "signal 4"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries5
        name: "signal 5"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries6
        name: "signal 6"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }

    LineSeries {
        id: lineSeries7
        name: "signal 7"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries8
        name: "signal 8"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries9
        name: "signal 9"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }
    LineSeries {
        id: lineSeries10
        name: "signal 10"
        axisX: axisX
        axisYRight: axisY2
        useOpenGL: chartView.openGL
    }



//![1]

    //![2]
    Timer {
        id: refreshTimer
        interval: 1// 60 Hz
        running: true
        repeat: true
        onTriggered: {
            dataSource.update(0,chartView.series(0));
            dataSource.update(1,chartView.series(1));
            dataSource.update(2,chartView.series(2));
            dataSource.update(3,chartView.series(3));
            dataSource.update(4,chartView.series(4));
            dataSource.update(5,chartView.series(5));
            dataSource.update(6,chartView.series(6));
            dataSource.update(7,chartView.series(7));
            dataSource.update(8,chartView.series(8));
            dataSource.update(9,chartView.series(9));


        }
    }
    //![2]

    //![3]
    function changeSeriesType(type) {
        chartView.removeAllSeries();

        // Create two new series of the correct type. Axis x is the same for both of the series,
        // but the series have their own y-axes to make it possible to control the y-offset
        // of the "signal sources".
        if (type == "line") {
            var series1 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 1",
                                                 axisX, axisY1);
            series1.useOpenGL = chartView.openGL

            var series2 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 2",
                                                 axisX, axisY2);
            series2.useOpenGL = chartView.openGL

            var series3 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 3",
                                                 axisX, axisY1);
            series3.useOpenGL = chartView.openGL

            var series4 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 4",
                                                 axisX, axisY2);
            series4.useOpenGL = chartView.openGL

            var series5 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 5",
                                                 axisX, axisY1);
            series5.useOpenGL = chartView.openGL

            var series6 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 6",
                                                 axisX, axisY2);
            series6.useOpenGL = chartView.openGL

            var series7 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 7",
                                                 axisX, axisY1);
            series7.useOpenGL = chartView.openGL

            var series8 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 8",
                                                 axisX, axisY2);
            series8.useOpenGL = chartView.openGL

            var series9 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 9",
                                                 axisX, axisY1);
            series9.useOpenGL = chartView.openGL

            var series10 = chartView.createSeries(ChartView.SeriesTypeLine, "signal 10",
                                                 axisX, axisY2);
            series10.useOpenGL = chartView.openGL



        } else {
            var series1 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 1",
                                                 axisX, axisY1);
            series1.markerSize = 2;
            series1.borderColor = "transparent";
            series1.useOpenGL = chartView.openGL

            var series2 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 2",
                                                 axisX, axisY2);
            series2.markerSize = 2;
            series2.borderColor = "transparent";
            series2.useOpenGL = chartView.openGL

            var series3 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 3",
                                                 axisX, axisY1);
            series3.markerSize = 2;
            series3.borderColor = "transparent";
            series3.useOpenGL = chartView.openGL

            var series4 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 4",
                                                 axisX, axisY2);
            series4.markerSize = 2;
            series4.borderColor = "transparent";
            series4.useOpenGL = chartView.openGL

            var series5 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 5",
                                                 axisX, axisY2);
            series5.markerSize = 2;
            series5.borderColor = "transparent";
            series5.useOpenGL = chartView.openGL

            var series6 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 6",
                                                 axisX, axisY2);
            series6.markerSize = 2;
            series6.borderColor = "transparent";
            series6.useOpenGL = chartView.openGL
            var series7 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 7",
                                                 axisX, axisY2);
            series7.markerSize = 2;
            series7.borderColor = "transparent";
            series7.useOpenGL = chartView.openGL
            var series8 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 8",
                                                 axisX, axisY2);
            series8.markerSize = 2;
            series8.borderColor = "transparent";
            series8.useOpenGL = chartView.openGL

            var series9 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 9",
                                                 axisX, axisY2);
            series9.markerSize = 2;
            series9.borderColor = "transparent";
            series9.useOpenGL = chartView.openGL

            var series10 = chartView.createSeries(ChartView.SeriesTypeScatter, "signal 10",
                                                 axisX, axisY2);
            series10.markerSize = 2;
            series10.borderColor = "transparent";
            series10.useOpenGL = chartView.openGL
        }
    }

    function createAxis(min, max) {
        // The following creates a ValueAxis object that can be then set as a x or y axis for a series
        return Qt.createQmlObject("import QtQuick 2.0; import QtCharts 2.0; ValueAxis { min: "
                                  + min + "; max: " + max + " }", chartView);
    }
    //![3]

    function setAnimations(enabled) {
        if (enabled)
            chartView.animationOptions = ChartView.SeriesAnimations;
        else
            chartView.animationOptions = ChartView.NoAnimation;
    }

    function changeRefreshRate(rate) {
        refreshTimer.interval = 1 / Number(rate) * 1000;
    }
}
