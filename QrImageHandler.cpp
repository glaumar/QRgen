#include "QrImageHandler.h"

#include <QZXing.h>

#include <QImage>

QrImageHandler::QrImageHandler() {}

void QrImageHandler::imageGen(const QString &data,
                              const QString correctionLevel,
                              const QUrl &fileUrl) {
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
    qrcode.save(fileUrl.toLocalFile());
}

QString QrImageHandler::decodeQrImg(const QUrl &fileUrl) {
    QImage imageToDecode(fileUrl.toLocalFile());
    QZXing decoder;
    // mandatory settings
    decoder.setDecoder(QZXing::DecoderFormat_QR_CODE);

    // optional settings
    // decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal |
    // QZXing::SourceFilter_ImageInverted);
    decoder.setSourceFilterType(QZXing::SourceFilter_ImageNormal);
    decoder.setTryHarderBehaviour(QZXing::TryHarderBehaviour_ThoroughScanning |
                                  QZXing::TryHarderBehaviour_Rotate);

    // trigger decode
    QString result = decoder.decodeImage(imageToDecode);
    return result;
}
