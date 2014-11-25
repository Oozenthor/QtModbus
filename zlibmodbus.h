#ifndef ZLIBMODBUS_H
#define ZLIBMODBUS_H

#define MAXIMUM_WORD_POINTS 40	//maximum holding registers read at a time limit
#define MAXIMUM_BIT_POINTS 40		//maximum relay read at a time limit

#include <stdint.h>
#include <QDebug>
#include "libMb/modbus.h"

class ZLibModbus
{
public:
    ZLibModbus();
    ~ZLibModbus();

    bool connect();
    bool write(quint16 address, quint16 writeValue);
    quint16 read(quint16 address);

private:
    modbus_t *ctx;	//Modbus connection context
    int rc;			//Modbus call return value
    uint16_t *mbw;  //Modbus word holding array
};

#endif // ZLIBMODBUS_H
