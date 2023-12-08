#pragma once
#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QNetworkAccessManager>
#include <memory>

namespace gove {
namespace location {

class GACGeoTileFetcher : public QGeoTileFetcher {
    Q_OBJECT
public:
    GACGeoTileFetcher(const QVariantMap& parameters,
                      QGeoMappingManagerEngine* parent);

private:
    QGeoTiledMapReply *getTileImage(const QGeoTileSpec &spec) override;

private:
    QNetworkAccessManager* network_manager_ptr_;
};

}  // namespace location
}  // namespace gove
