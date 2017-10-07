#include "hashcheckdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HashCheckDialog w;
    w.show();

    return a.exec();
}
