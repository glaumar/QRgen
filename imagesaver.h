#ifndef IMAGESAVER_H
#define IMAGESAVER_H

#include <QGraphicsObject>
#include <QtDebug>
#include <QtWidgets>

class ImageSaver : public QObject {
    Q_OBJECT
   public:
    explicit ImageSaver();

   public slots:
    void qrSave(QString data, QString correctionLevel, const QString &path);
};

#endif  // IMAGESAVER_H
