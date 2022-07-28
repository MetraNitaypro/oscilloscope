QT += charts qml quick
QT += serialport
QT += quick
QMAKE_CXXFLAGS-= -o1 -o2 -o3 -os
QMAKE_CXXFLAGS += -o0
HEADERS += \
    BTMod.h \
    CRC8.h \
    Map.h \
    Measure.h \
    datasource.h \
    measureconfig.h \
    parsing_1.h

SOURCES += \
    CRC8.cpp \
    Measure.cpp \
    main.cpp \
    datasource.cpp \
    measureconfig.cpp

RESOURCES += \
    resources.qrc

DISTFILES += \
    qml/qmloscilloscope/* \
    qml/qmloscilloscope/Faf.qml \
    qml/qmloscilloscope/FafForm.ui.qml \
    qml/qmloscilloscope/Ghhg.qml \
    qml/qmloscilloscope/GhhgForm.ui.qml \
    qml/qmloscilloscope/Graph.qml \
    qml/qmloscilloscope/Max_Val.qml \
    qml/qmloscilloscope/Panel.qml \
    qml/qmloscilloscope/PanelForm.ui.qml \
    qml/qmloscilloscope/S.qml \
    qml/qmloscilloscope/Setor_1.qml \
    qml/qmloscilloscope/Settings.ui.qml \
    qml/qmloscilloscope/SettingsWindow.qml \
    qml/qmloscilloscope/SettingsWindowForm.qml \
    qml/qmloscilloscope/SettingsWindowForm.ui.qml \
    qml/qmloscilloscope/Winsow_Settings.qml \
    qml/qmloscilloscope/Winsow_SettingsForm.ui.qml \
    qml/qmloscilloscope/Wsdf.qml \
    qml/qmloscilloscope/WsdfForm.ui.qml

target.path = $$[QT_INSTALL_EXAMPLES]/charts/qmloscilloscope
INSTALLS += target
