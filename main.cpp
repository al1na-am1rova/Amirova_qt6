#include "mainwindow.h"
#include "Amirova_Actor.h"
#include "Amirova_Group.h"
#include "utils.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
