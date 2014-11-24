#include "qtmodbus.h"
#include "ui_qtmodbus.h"

QtModbus::QtModbus(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::QtModbus)
{
  ui->setupUi(this);

//  QLibrary modLib("../libmodbus-5");

  qDebug() << "Start";// << modLib.isLoaded();

  ctx = modbus_new_tcp("127.0.0.1", 502);

  if (ctx == NULL) {
    qDebug() << "Unable to allocate libmodbus context";
    qApp->exit(-1);
  }
  modbus_set_debug(ctx, FALSE);

  if (modbus_connect(ctx) == -1) {

    qDebug() << "Connection failed:" << modbus_strerror(errno) << errno;
    modbus_free(ctx);
    qApp->exit(-1);
  }

  /* -------------------------------------------- */
  uint16_t modbus_address;
  uint16_t modbus_value;

  modbus_address=2;
  modbus_value=555;
  rc = modbus_write_register(ctx, modbus_address, modbus_value);
  if (rc == 1) {
    qDebug() << "Address 0x%X, value %d written\n" << modbus_address << modbus_value;
  } else {
    qDebug() << "Write FAILED\n";
    qApp->exit(-1);
  }
}

void QtModbus::exitModbus()
{
  qDebug() << "Closing connection";
  modbus_close(ctx); // Close the connection
  modbus_free(ctx);
}

QtModbus::~QtModbus()
{
  qDebug() << "Exiting";
  exitModbus();
  delete ui;
}

