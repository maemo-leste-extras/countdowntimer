#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QMessageBox>
#include <qdatetime.h>
#include <QSettings>
#include <Phonon/AudioOutput>
#include <Phonon/MediaObject>
#include <Phonon/Path>
#include <Phonon/BackendCapabilities>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "settings.h"
#include "about.h"
#include "help.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Settings *settingsDialog;
    About *aboutDialog;
    Help *helpDialog;
    QSettings mSettings;
    QTimer *mvpTimer;
    QTime mvTime;
    QMenuBar *menuBar;
    QMenu *helpMenu;
    QAction *aboutAct;
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path mediaPath;
    int mvCountDown;
    int mvStarted;
    bool mvTimeUp;

    void syncSettings();
    void formatTimer(int timerSeconds);
    void setTimer(int timerSeconds);
    void changeTimer(bool addTime, int amountSeconds);
    void timeUp();
    void timerColour(bool timerRed);


private slots:
    void on_actionHelp_triggered();
    void on_actionDonate_triggered();
    void on_actionAbout_triggered();
    void on_pushButton_start_clicked();
    void on_pushButton_reset_clicked();
    void on_pushButton_minutes_plus_clicked();
    void on_pushButton_minutes_minus_clicked();
    void on_pushButton_seconds_plus_clicked();
    void on_pushButton_seconds_minus_clicked();
    void on_pushButton_mem_1_clicked();
    void on_pushButton_mem_2_clicked();
    void on_pushButton_mem_3_clicked();
    void on_pushButton_mem_4_clicked();
    void on_pushButton_settings_clicked();


public slots:
    void update();
};

#endif // MAINWINDOW_H
