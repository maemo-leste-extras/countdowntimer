#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mvStarted = 0;
    mvCountDown = 0;

    ui->setupUi(this);
    mvpTimer = new QTimer(this);
    connect(mvpTimer, SIGNAL(timeout()), this, SLOT(update()));

    timerColour(false);
    syncSettings();

    mediaObject = new Phonon::MediaObject(this);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaPath = Phonon::createPath(mediaObject, audioOutput);
    mediaObject->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::syncSettings()
{
    if (mSettings.value("mem1Name").isNull()) {
        mSettings.setValue("mem1Name", "1 min");
        mSettings.setValue("mem1Value", 60);
    }
    if (mSettings.value("mem2Name").isNull()) {
        mSettings.setValue("mem2Name", "2 min");
        mSettings.setValue("mem2Value", 120);
    }
    if (mSettings.value("mem3Name").isNull()) {
        mSettings.setValue("mem3Name", "3 min");
        mSettings.setValue("mem3Value", 180);
    }
    if (mSettings.value("mem4Name").isNull()) {
        mSettings.setValue("mem4Name", "4 min");
        mSettings.setValue("mem4Value", 240);
    }
    if (mSettings.value("soundFile").isNull()) {
        mSettings.setValue("soundFile", "/home/user/MyDocs/.sounds/Ringtones/beep.aac");
    }
    ui->pushButton_mem_1->setText(mSettings.value("mem1Name").toString());
    ui->pushButton_mem_2->setText(mSettings.value("mem2Name").toString());
    ui->pushButton_mem_3->setText(mSettings.value("mem3Name").toString());
    ui->pushButton_mem_4->setText(mSettings.value("mem4Name").toString());
}

void MainWindow::update()
{
    int timerSeconds;

    if (mvTimeUp) {
        timerSeconds = mvCountDown + mvTime.elapsed() / 1000;
    } else {
        timerSeconds = mvCountDown - mvTime.elapsed() / 1000;
    }

    formatTimer(timerSeconds);

    if (timerSeconds == 0 && !mvTimeUp) {
        timeUp();
    }
}

void MainWindow::formatTimer(int timerSeconds)
{
    QString text;
    text.sprintf("%02d:%02d", timerSeconds / 60, timerSeconds % 60);
    ui->label->setText(text);
}

void MainWindow::setTimer(int timerSeconds)
{
    mediaObject->stop();
    mvpTimer->stop();
    timerColour(false);
    mvTimeUp = false;
    mvCountDown = timerSeconds;
    formatTimer(mvCountDown);
    ui->pushButton_start->setText("Start");
    mvStarted = 0;
}

void MainWindow::changeTimer(bool addTime, int amountSeconds)
{
    if (mvStarted != 1) {

        if (addTime) {
            mvCountDown += amountSeconds;
        } else {
            mvCountDown -= amountSeconds;
        }

        if (mvCountDown <= 0) {
            mvCountDown = 0;
        } else if (mvCountDown >= 3600) {
            mvCountDown = 3600;
        }

        formatTimer(mvCountDown);
    }
}

void MainWindow::timeUp()
{
    timerColour(true);
    mediaObject->setCurrentSource(Phonon::MediaSource(mSettings.value("soundFile").toString()));
    mediaObject->play();
    mvTimeUp = true;
    mvTime.restart();
    mvCountDown = 0;
}

void MainWindow::timerColour(bool timerRed)
{
    QPalette textPalette(QColor(255,255,255));

    if (timerRed) {
        textPalette.setColor(QPalette::WindowText, QColor(255,0,0));
    } else {
        textPalette.setColor(QPalette::WindowText, QColor(255,255,255));
    }

    ui->label->setPalette(textPalette);
}

void MainWindow::on_pushButton_start_clicked()
{

    switch (mvStarted) {
    case 0:
        mvTimeUp = false;
        timerColour(false);
        if (mvCountDown != 0) {
            mvTimeUp = false;
        } else {
            mvTimeUp = true;
        }
        mvTime.start();
        update();
        mvpTimer->start(100);
        ui->pushButton_start->setText("Stop");
        mvStarted = 1;
        break;
    case 1:
        mvpTimer->stop();
        update();
        mediaObject->stop();
        if (mvTimeUp) {
            mvCountDown = 0;
            ui->pushButton_start->setText("Start");
            mvStarted = 0;
        } else {
            mvCountDown -= mvTime.elapsed() / 1000;
            ui->pushButton_start->setText("Continue");
            mvStarted = 2;
        }
        break;
    case 2:
        mvTime.restart();
        mvpTimer->start(100);
        update();
        ui->pushButton_start->setText("Stop");
        mvStarted = 1;
        break;
    }
        //QSound::play("whip1.wav");
}

void MainWindow::on_pushButton_reset_clicked()
{
    setTimer(0);
}

void MainWindow::on_pushButton_seconds_plus_clicked()
{
    changeTimer(true, 1);
}

void MainWindow::on_pushButton_seconds_minus_clicked()
{
    changeTimer(false, 1);
}

void MainWindow::on_pushButton_minutes_plus_clicked()
{
    changeTimer(true, 60);
}

void MainWindow::on_pushButton_minutes_minus_clicked()
{
    changeTimer(false, 60);
}

void MainWindow::on_pushButton_mem_1_clicked()
{
    setTimer(mSettings.value("mem1Value").toInt());
}

void MainWindow::on_pushButton_mem_2_clicked()
{
    setTimer(mSettings.value("mem2Value").toInt());
}

void MainWindow::on_pushButton_mem_3_clicked()
{
    setTimer(mSettings.value("mem3Value").toInt());
}

void MainWindow::on_pushButton_mem_4_clicked()
{
    setTimer(mSettings.value("mem4Value").toInt());
}

void MainWindow::on_pushButton_settings_clicked()
{
    settingsDialog = new Settings;
    settingsDialog->exec();
    syncSettings();
}

void MainWindow::on_actionAbout_triggered()
{
    aboutDialog = new About;
    aboutDialog->exec();
}

void MainWindow::on_actionDonate_triggered()
{
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=sascha.makela@gmail.com&lc=LT&item_name=STM%20Software%20-%20Countdown%20Timer&currency_code=EUR&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHosted"));
//    QDesktopServices::openUrl(QUrl("http://www.google.com"));
}

void MainWindow::on_actionHelp_triggered()
{
    helpDialog = new Help;
    helpDialog->exec();
}
