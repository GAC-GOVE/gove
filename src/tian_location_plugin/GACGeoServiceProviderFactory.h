#pragma once
#include <QtCore/QObject>
#include <QtLocation/QGeoServiceProviderFactory>

namespace gove {
namespace location {

class GACGeoServiceProviderFactory : public QObject,
                                     public QGeoServiceProviderFactory {
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)
    Q_PLUGIN_METADATA(
        IID "org.qt-project.qt.geoservice.serviceproviderfactory/5.0" FILE
            "GACMapPlugin.json")
public:
    GACGeoServiceProviderFactory() = default;

    QGeoMappingManagerEngine *createMappingManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error,
        QString *errorString) const;
};

}  // namespace location
}  // namespace gove

