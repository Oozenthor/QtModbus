#ifndef QTMODBUS_H
#define QTMODBUS_H

#include <stdint.h>
#include <QDebug>
#include <QMainWindow>
#include <QLibrary>
#include "libMb/modbus.h"

namespace Ui {
class QtModbus;
}

class QtModbus : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtModbus(QWidget *parent = 0);
    ~QtModbus();

private:
    Ui::QtModbus *ui;

    void exitModbus(void);
    modbus_t *ctx;	//modbus connection
    int rc;			//modbus call return value
};

#endif // QTMODBUS_H
