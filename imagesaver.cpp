#include "imagesaver.h"

#include <QZXing.h>

#include <QImage>

ImageSaver::ImageSaver() {}

void ImageSaver::qrSave(QString data, const QString correctionLevel,
                        const QString &path) {
    QZXing::EncodeErrorCorrectionLevel clevel;

    if (correctionLevel == "L") {
        clevel = QZXing::EncodeErrorCorrectionLevel_L;
    } else if (correctionLevel == "M") {
        clevel = QZXing::EncodeErrorCorrectionLevel_M;
    } else if (correctionLevel == "Q") {
        clevel = QZXing::EncodeErrorCorrectionLevel_Q;
    } else {
        clevel = QZXing::EncodeErrorCorrectionLevel_H;
    }
    QImage qrcode = QZXing::encodeData(data, QZXing::EncoderFormat_QR_CODE,
                                       QSize(960, 960), clevel, true, false);
    qrcode.save(path);
}
