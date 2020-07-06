#include <QZXing.h>
#include <QrImageHandler.h>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    // register QZXing to qml
    QZXing::registerQMLTypes();
    QZXing::registerQMLImageProvider(engine);

    engine.rootContext()->setContextProperty("qrImageHandler",
                                             new QrImageHandler);

    engine.load(url);

    return app.exec();
}
