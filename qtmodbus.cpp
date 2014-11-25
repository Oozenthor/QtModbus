#include "qtmodbus.h"
#include "ui_qtmodbus.h"

QtModbus::QtModbus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtModbus)
{
    ui->setupUi(this);

}

QtModbus::~QtModbus()
{
    delete ui;
}

void QtModbus::on_connectButton_clicked()
{
    if (!mb.connect()) {
        qDebug() << "fail connect";
        QApplication::exit(-1);
    }
}

void QtModbus::on_writeButton_clicked()
{
    bool ok;
    quint32 mbVal = QString(ui->writeEdit->text()).toUInt(&ok);
    if (!mb.write(1, mbVal)) {
        qDebug() << "fail write";
        QApplication::exit(-1);
    }
}

void QtModbus::on_readButton_clicked()
{
    ui->readEdit->setText(QString("%1").arg(mb.read(1)));
}

