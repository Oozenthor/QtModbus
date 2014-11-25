#ifndef QTMODBUS_H
#define QTMODBUS_H

#include <QDebug>
#include <QMainWindow>
#include "zlibmodbus.h"

namespace Ui {
class QtModbus;
}

class QtModbus : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtModbus(QWidget *parent = 0);
    ~QtModbus();

private slots:
    void on_writeButton_clicked();
    void on_readButton_clicked();
    void on_connectButton_clicked();

private:
    Ui::QtModbus *ui;

    ZLibModbus mb;  //libModbus wrapper
};

#endif // QTMODBUS_H
