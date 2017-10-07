#include "hashcounter.h"
#include <QFile>

HashCounter::HashCounter(QObject *parent) : QObject(parent),
    md4(QCryptographicHash::Md4),
    md5(QCryptographicHash::Md5),
    sha1(QCryptographicHash::Sha1),
    sha224(QCryptographicHash::Sha224),
    sha256(QCryptographicHash::Sha256),
    sha384(QCryptographicHash::Sha384),
    sha512(QCryptographicHash::Sha512),
    sha3_224(QCryptographicHash::Sha3_224),
    sha3_256(QCryptographicHash::Sha3_256),
    sha3_384(QCryptographicHash::Sha3_384),
    sha3_512(QCryptographicHash::Sha3_512)
{

}


void HashCounter::countHash(const QString& filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
    {
        emit message(QMessageBox::Critical, QString(u8"错误"), file.errorString());
        return ;
    }

    md4.reset();
    file.reset();
    md4.addData(&file);
    QString md4Hex = md4.result().toHex();
    emit countMd4Completed(md4Hex);

    md5.reset();
    file.reset();
    md5.addData(&file);
    QString md5Hex = md5.result().toHex();
    emit countMd5Completed(md5Hex);

    sha1.reset();
    file.reset();
    sha1.addData(&file);
    QString sha1Hex = sha1.result().toHex();
    emit countSha1Completed(sha1Hex);

    /* SHA2 */
    sha224.reset();
    file.reset();
    sha224.addData(&file);
    QString sha224Hex = sha224.result().toHex();
    emit countSha224Completed(sha224Hex);

    sha256.reset();
    file.reset();
    sha256.addData(&file);
    QString sha256Hex = sha256.result().toHex();
    emit countSha256Completed(sha256Hex);

    sha384.reset();
    file.reset();
    sha384.addData(&file);
    QString sha384Hex = sha384.result().toHex();
    emit countSha384Completed(sha384Hex);

    sha512.reset();
    file.reset();
    sha512.addData(&file);
    QString sha512Hex = sha512.result().toHex();
    emit countSha512Completed(sha512Hex);

    /* SHA3 */
    sha3_224.reset();
    file.reset();
    sha3_224.addData(&file);
    QString sha3_224Hex = sha3_224.result().toHex();
    emit countSha3_224Completed(sha3_224Hex);

    sha3_256.reset();
    file.reset();
    sha3_256.addData(&file);
    QString sha3_256Hex = sha3_256.result().toHex();
    emit countSha3_256Completed(sha3_256Hex);

    sha3_384.reset();
    file.reset();
    sha3_384.addData(&file);
    QString sha3_384Hex = sha3_384.result().toHex();
    emit countSha3_384Completed(sha3_384Hex);

    sha3_512.reset();
    file.reset();
    sha3_512.addData(&file);
    QString sha3_512Hex = sha3_512.result().toHex();
    emit countSha3_512Completed(sha3_512Hex);
    file.close();
}
