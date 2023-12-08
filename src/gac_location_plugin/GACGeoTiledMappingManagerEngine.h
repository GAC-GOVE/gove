#pragma once

#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

namespace gove {
namespace location {

class GACGeoTiledMappingManagerEngine : public QGeoTiledMappingManagerEngine {
    Q_OBJECT
public:
    GACGeoTiledMappingManagerEngine(const QVariantMap &parameters,
                                    QGeoServiceProvider::Error *error,
                                    QString *errorString);
    ~GACGeoTiledMappingManagerEngine();

    QGeoMap *createMap() override;

private:
    void Init(const QVariantMap &parameters, QGeoServiceProvider::Error *error,
              QString *errorString);
    void InitTileCache(const QVariantMap &parameters);
    void InitCameraCapabilities(const QVariantMap &parameters);
    void InitTileFetcher(const QVariantMap &parameters);
};

}  // namespace location
}  // namespace gove


