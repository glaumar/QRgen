#ifndef IMAGESAVER_H
#define IMAGESAVER_H

#include <QGraphicsObject>
#include <QUrl>
#include <QtDebug>
#include <QtWidgets>

class QrImageHandler : public QObject {
    Q_OBJECT
   public:
    explicit QrImageHandler();

   public slots:
    static void imageGen(const QString &data, const QString correctionLevel,
                         const QUrl &fileUrl);
    static QString decodeQrImg(const QUrl &fileUrl);
};

#endif  // IMAGESAVER_H
