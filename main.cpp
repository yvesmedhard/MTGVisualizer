#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

    QApplication application(argc, argv);
    MainWindow window;
    window.show();

    return application.exec();
}
