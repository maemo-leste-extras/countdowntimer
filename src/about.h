#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
    class about;
}

class About : public QDialog {
    Q_OBJECT
public:
    About(QWidget *parent = 0);
    ~About();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::about *ui;    
};

#endif // ABOUT_H
