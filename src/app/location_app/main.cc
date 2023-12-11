#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtPlugin>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    Q_IMPORT_PLUGIN(GACMapPlugin);

   QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(
        "applicationDirPath", QGuiApplication::applicationDirPath());

    const QUrl url(QStringLiteral("qrc:/MapView.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
