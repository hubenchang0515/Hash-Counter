#ifndef HASHCHECKDIALOG_H
#define HASHCHECKDIALOG_H

#include <QDialog>
#include <QThread>
#include <QMessageBox>
#include "hashcounter.h"

namespace Ui {
class HashCheckDialog;
}

class HashCheckDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HashCheckDialog(QWidget *parent = 0);
    ~HashCheckDialog();

private:
    Ui::HashCheckDialog *ui;
    HashCounter* counter;
    QThread* countThread;

signals:
    void startCount(const QString& filename);

private slots:
    void openFile();
    void countHash();
    void messageBox(QMessageBox::Icon icon, const QString& title, const QString& message);

    void showMd4(const QString& hex);
    void showMd5(const QString& hex);
    void showSha1(const QString& hex);

    void showSha224(const QString& hex);
    void showSha256(const QString& hex);
    void showSha384(const QString& hex);
    void showSha512(const QString& hex);


    void showSha3_224(const QString& hex);
    void showSha3_256(const QString& hex);
    void showSha3_384(const QString& hex);
    void showSha3_512(const QString& hex);
};

#endif // HASHCHECKDIALOG_H
