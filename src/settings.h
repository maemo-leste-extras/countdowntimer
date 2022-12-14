#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/Path>
#include <phonon/BackendCapabilities>


namespace Ui {
    class Settings;
}

class Settings : public QDialog {
    Q_OBJECT
public:
    Settings(QWidget *parent = 0);
    ~Settings();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    Ui::Settings *ui;
    QSettings mSettings;
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path mediaPath;

    void getValue();
    void setValue();

private slots:
    void on_pushButton_Sound_clicked();
    void on_pushButton_Apply_clicked();
};

#endif // SETTINGS_H
