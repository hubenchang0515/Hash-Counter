#ifndef HASHCOUNTER_H
#define HASHCOUNTER_H

#include <QObject>
#include <QCryptographicHash>
#include <QMessageBox>

class HashCounter : public QObject
{
    Q_OBJECT
public:
    explicit HashCounter(QObject *parent = nullptr);

private:
    QCryptographicHash md4;
    QCryptographicHash md5;
    QCryptographicHash sha1;

    QCryptographicHash sha224;
    QCryptographicHash sha256;
    QCryptographicHash sha384;
    QCryptographicHash sha512;

    QCryptographicHash sha3_224;
    QCryptographicHash sha3_256;
    QCryptographicHash sha3_384;
    QCryptographicHash sha3_512;

signals:
    void message(QMessageBox::Icon icon, const QString& title, const QString& msg);

    void countMd4Completed(const QString& hex);
    void countMd5Completed(const QString& hex);
    void countSha1Completed(const QString& hex);

    void countSha224Completed(const QString& hex);
    void countSha256Completed(const QString& hex);
    void countSha384Completed(const QString& hex);
    void countSha512Completed(const QString& hex);

    void countSha3_224Completed(const QString& hex);
    void countSha3_256Completed(const QString& hex);
    void countSha3_384Completed(const QString& hex);
    void countSha3_512Completed(const QString& hex);

public slots:
    void countHash(const QString& filename);
};

#endif // HASHCOUNTER_H
