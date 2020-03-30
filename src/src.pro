QT += phonon
TARGET = countdowntimer
TEMPLATE = app
SOURCES += qtmain.cpp \
    settings.cpp \
    mainwindow.cpp \
    about.cpp \
    help.cpp
HEADERS += settings.h \
    mainwindow.h \
    about.h \
    help.h
FORMS += settings.ui \
    mainwindow.ui \
    about.ui \
    help.ui
RESOURCES = resource.qrc

unix {
    isEmpty(PREFIX) {
        PREFIX = /usr/local
    }
    BINDIR = $$PREFIX/bin
    DATADIR =$$PREFIX/share

    DEFINES += DATADIR=\\\"$$DATADIR\\\" PKGDATADIR=\\\"$$PKGDATADIR\\\"

    #MAKE INSTALL

    INSTALLS += target desktop icon64

        target.path =$$BINDIR

        desktop.path = $$DATADIR/applications/hildon
        desktop.files += countdowntimer.desktop

        icon64.path = $$DATADIR/icons/hicolor/64x64/apps
        icon64.files += ../data/64x64/countdowntimer.png

}
