#include "hashcheckdialog.h"
#include "ui_hashcheckdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

#include <QDebug>

HashCheckDialog::HashCheckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HashCheckDialog)
{
    ui->setupUi(this);
    counter = new HashCounter();
    countThread = new QThread(this);
    countThread->start();
    counter->moveToThread(countThread);

    qRegisterMetaType<QMessageBox::Icon>("QMessageBox::Icon");

    connect(ui->open, &QPushButton::clicked, this, &HashCheckDialog::openFile);
    connect(ui->count, &QPushButton::clicked, this, &HashCheckDialog::countHash);
    connect(this, &HashCheckDialog::startCount, counter, &HashCounter::countHash);
    connect(counter, &HashCounter::message, this, &HashCheckDialog::messageBox);

    connect(counter, &HashCounter::countMd4Completed, this, &HashCheckDialog::showMd4);
    connect(counter, &HashCounter::countMd5Completed, this, &HashCheckDialog::showMd5);
    connect(counter, &HashCounter::countSha1Completed, this, &HashCheckDialog::showSha1);

    connect(counter, &HashCounter::countSha224Completed, this, &HashCheckDialog::showSha224);
    connect(counter, &HashCounter::countSha256Completed, this, &HashCheckDialog::showSha256);
    connect(counter, &HashCounter::countSha384Completed, this, &HashCheckDialog::showSha384);
    connect(counter, &HashCounter::countSha512Completed, this, &HashCheckDialog::showSha512);

    connect(counter, &HashCounter::countSha3_224Completed, this, &HashCheckDialog::showSha3_224);
    connect(counter, &HashCounter::countSha3_256Completed, this, &HashCheckDialog::showSha3_256);
    connect(counter, &HashCounter::countSha3_384Completed, this, &HashCheckDialog::showSha3_384);
    connect(counter, &HashCounter::countSha3_512Completed, this, &HashCheckDialog::showSha3_512);
}

HashCheckDialog::~HashCheckDialog()
{
    delete ui;
    countThread->terminate();
    //countThread->wait();
}

void HashCheckDialog::openFile()
{
    QString filename = QFileDialog::getOpenFileName(this);
    ui->file->setText(filename);
}

void HashCheckDialog::countHash()
{
    qDebug() << QThread::currentThreadId();
    ui->open->setEnabled(false);
    ui->count->setEnabled(false);
    ui->file->setReadOnly(true);
    ui->md4->setText(tr(u8"计算中"));
    ui->md5->setText(tr(u8"计算中"));
    ui->sha1->setText(tr(u8"计算中"));
    ui->sha224->setText(tr(u8"计算中"));
    ui->sha256->setText(tr(u8"计算中"));
    ui->sha384->setText(tr(u8"计算中"));
    ui->sha512->setText(tr(u8"计算中"));
    ui->sha3_224->setText(tr(u8"计算中"));
    ui->sha3_256->setText(tr(u8"计算中"));
    ui->sha3_384->setText(tr(u8"计算中"));
    ui->sha3_512->setText(tr(u8"计算中"));
    QString filename = ui->file->text();
    emit startCount(filename);
}

void HashCheckDialog::messageBox(QMessageBox::Icon icon, const QString& title, const QString& message)
{
    QMessageBox* box = new QMessageBox(icon, title, message, QMessageBox::Ok, this);
    box->show();
    if(icon == QMessageBox::Critical)
    {
        ui->md4->setText(tr(u8"计算失败"));
        ui->md5->setText(tr(u8"计算失败"));
        ui->sha1->setText(tr(u8"计算失败"));
        ui->sha224->setText(tr(u8"计算失败"));
        ui->sha256->setText(tr(u8"计算失败"));
        ui->sha384->setText(tr(u8"计算失败"));
        ui->sha512->setText(tr(u8"计算失败"));
        ui->sha3_224->setText(tr(u8"计算失败"));
        ui->sha3_256->setText(tr(u8"计算失败"));
        ui->sha3_384->setText(tr(u8"计算失败"));
        ui->sha3_512->setText(tr(u8"计算失败"));

        ui->open->setEnabled(true);
        ui->count->setEnabled(true);
        ui->file->setReadOnly(false);
    }
}


void HashCheckDialog::showMd4(const QString& hex)
{
    ui->md4->setText(hex);
}

void HashCheckDialog::showMd5(const QString& hex)
{
    ui->md5->setText(hex);
}

void HashCheckDialog::showSha1(const QString& hex)
{
    ui->sha1->setText(hex);
}

void HashCheckDialog::showSha224(const QString& hex)
{
    ui->sha224->setText(hex);
}

void HashCheckDialog::showSha256(const QString& hex)
{
    ui->sha256->setText(hex);
}

void HashCheckDialog::showSha384(const QString& hex)
{
    ui->sha384->setText(hex);
}

void HashCheckDialog::showSha512(const QString& hex)
{
    ui->sha512->setText(hex);
}

void HashCheckDialog::showSha3_224(const QString& hex)
{
    ui->sha3_224->setText(hex);
}

void HashCheckDialog::showSha3_256(const QString& hex)
{
    ui->sha3_256->setText(hex);
}

void HashCheckDialog::showSha3_384(const QString& hex)
{
    ui->sha3_384->setText(hex);
}

void HashCheckDialog::showSha3_512(const QString& hex)
{
    ui->sha3_512->setText(hex);
    ui->open->setEnabled(true);
    ui->count->setEnabled(true);
    ui->file->setReadOnly(false);
}
