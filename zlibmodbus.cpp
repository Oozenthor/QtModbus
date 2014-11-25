#include "zlibmodbus.h"

ZLibModbus::ZLibModbus()
{
}

ZLibModbus::~ZLibModbus()
{
    qDebug() << "Closing modbus connection";
    modbus_close(ctx); // Close the connection
    modbus_free(ctx);
}

bool ZLibModbus::connect()
{
    ctx = modbus_new_tcp("127.0.0.1", 502);

    if (ctx == NULL) {
        qDebug() << "Unable to allocate libmodbus context";
        return(false);
    }
    modbus_set_debug(ctx, FALSE);

    if (modbus_connect(ctx) == -1) {
        qDebug() << "Connection failed:" << modbus_strerror(errno) << errno;
        modbus_free(ctx);
        return(false);
    }

    modbus_set_debug(ctx, FALSE); //Set modbus library verbosity to "off"

    // Allocate and initialize the memory to store the bits
    //  mbb = (uint8_t *) malloc(MAXIMUM_BIT_POINTS * sizeof(uint8_t));
    //  memset(mbb, 0, MAXIMUM_BIT_POINTS * sizeof(uint8_t));

    // Allocate and initialize the memory to store the registers
    mbw = (uint16_t *) malloc(MAXIMUM_WORD_POINTS * sizeof(uint16_t));
    memset(mbw, 0, MAXIMUM_WORD_POINTS * sizeof(uint16_t));

    qDebug() << "Connected";
    return(true);
}

bool ZLibModbus::write(quint16 address, quint16 writeValue)
{
    uint16_t modbus_address = static_cast<uint16_t>(address);
    uint16_t modbus_value = static_cast<uint16_t>(writeValue);

    rc = modbus_write_register(ctx, modbus_address, modbus_value);
    if (rc == 1) {
        qDebug() << "Address:" << modbus_address << ",Value:" << modbus_value << "written";
        return(true);
    } else {
        qDebug() << "Write FAILED\n";
        return(false);
    }
}

quint16 ZLibModbus::read(quint16 address)
{
    uint16_t modbus_address = static_cast<uint16_t>(address);

    rc = modbus_read_registers(ctx, modbus_address, 1, mbw);
    if (rc == 1) {
        qDebug() << "Address:" << modbus_address << ",Value:" << mbw[0] << "read";
        return(static_cast<quint16>(mbw[0]));
    } else {
        qDebug() << "Read FAILED\n";
        return(0);
    }
}
