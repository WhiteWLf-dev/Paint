#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow a;
    a.resize(1500,1000);
    a.show();
    return app.exec();
}
