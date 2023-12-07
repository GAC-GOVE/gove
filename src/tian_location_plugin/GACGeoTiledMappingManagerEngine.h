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

};

}  // namespace location
}  // namespace gove


