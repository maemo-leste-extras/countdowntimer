#include "settings.h"
#include "ui_settings.h"
#include <QFileDialog>
#include <QtGui>


Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->lineEdit_mem1Name->setText(mSettings.value("mem1Name").toString());
    ui->lineEdit_mem2Name->setText(mSettings.value("mem2Name").toString());
    ui->lineEdit_mem3Name->setText(mSettings.value("mem3Name").toString());
    ui->lineEdit_mem4Name->setText(mSettings.value("mem4Name").toString());
    ui->lineEdit_mem1ValueMinutes->setValidator(new QIntValidator(0, 60, this));
    ui->lineEdit_mem1ValueSeconds->setValidator(new QIntValidator(0, 59, this));
    ui->lineEdit_mem2ValueMinutes->setValidator(new QIntValidator(0, 60, this));
    ui->lineEdit_mem2ValueSeconds->setValidator(new QIntValidator(0, 59, this));
    ui->lineEdit_mem3ValueMinutes->setValidator(new QIntValidator(0, 60, this));
    ui->lineEdit_mem3ValueSeconds->setValidator(new QIntValidator(0, 59, this));
    ui->lineEdit_mem4ValueMinutes->setValidator(new QIntValidator(0, 60, this));
    ui->lineEdit_mem4ValueSeconds->setValidator(new QIntValidator(0, 59, this));

    getValue();

    mediaObject = new Phonon::MediaObject(this);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaPath = Phonon::createPath(mediaObject, audioOutput);

}

Settings::~Settings()
{
    mediaObject->stop();
    delete ui;
}

void Settings::getValue()
{
    int memValue;
    QString memValueText;

    memValue = mSettings.value("mem1Value").toInt();
    memValueText.sprintf("%02d", memValue / 60);
    ui->lineEdit_mem1ValueMinutes->setText(memValueText);
    memValueText.sprintf("%02d", memValue % 60);
    ui->lineEdit_mem1ValueSeconds->setText(memValueText);

    memValue = mSettings.value("mem2Value").toInt();
    memValueText.sprintf("%02d", memValue / 60);
    ui->lineEdit_mem2ValueMinutes->setText(memValueText);
    memValueText.sprintf("%02d", memValue % 60);
    ui->lineEdit_mem2ValueSeconds->setText(memValueText);

    memValue = mSettings.value("mem3Value").toInt();
    memValueText.sprintf("%02d", memValue / 60);
    ui->lineEdit_mem3ValueMinutes->setText(memValueText);
    memValueText.sprintf("%02d", memValue % 60);
    ui->lineEdit_mem3ValueSeconds->setText(memValueText);

    memValue = mSettings.value("mem4Value").toInt();
    memValueText.sprintf("%02d", memValue / 60);
    ui->lineEdit_mem4ValueMinutes->setText(memValueText);
    memValueText.sprintf("%02d", memValue % 60);
    ui->lineEdit_mem4ValueSeconds->setText(memValueText);
}

void Settings::setValue()
{
    int memValue;

    memValue = ui->lineEdit_mem1ValueMinutes->text().toInt() * 60;
    memValue += ui->lineEdit_mem1ValueSeconds->text().toInt();
    mSettings.setValue("mem1Value", memValue);

    memValue = ui->lineEdit_mem2ValueMinutes->text().toInt() * 60;
    memValue += ui->lineEdit_mem2ValueSeconds->text().toInt();
    mSettings.setValue("mem2Value", memValue);

    memValue = ui->lineEdit_mem3ValueMinutes->text().toInt() * 60;
    memValue += ui->lineEdit_mem3ValueSeconds->text().toInt();
    mSettings.setValue("mem3Value", memValue);

    memValue = ui->lineEdit_mem4ValueMinutes->text().toInt() * 60;
    memValue += ui->lineEdit_mem4ValueSeconds->text().toInt();
    mSettings.setValue("mem4Value", memValue);
}



void Settings::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Settings::on_pushButton_Apply_clicked()
{
    mSettings.setValue("mem1Name", ui->lineEdit_mem1Name->text());
    mSettings.setValue("mem2Name", ui->lineEdit_mem2Name->text());
    mSettings.setValue("mem3Name", ui->lineEdit_mem3Name->text());
    mSettings.setValue("mem4Name", ui->lineEdit_mem4Name->text());
    setValue();
    mSettings.sync();
    mediaObject->stop();
}

void Settings::on_pushButton_Sound_clicked()
{
    QString location = QDesktopServices::storageLocation(QDesktopServices::MusicLocation);
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Sound"), location, tr("Audio Files (*.mp3 *.wav *.aac)"));
    mSettings.setValue("soundFile", fileName);
    mediaObject->setCurrentSource(Phonon::MediaSource(mSettings.value("soundFile").toString()));
    mediaObject->play();
//    ui->labelSound->setText(fileName);
}

void Settings::closeEvent(QCloseEvent *e)
{
    mediaObject->stop();
}

