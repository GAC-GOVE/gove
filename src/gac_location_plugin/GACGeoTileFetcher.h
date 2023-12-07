#pragma once
#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QNetworkAccessManager>

namespace gove {
namespace location {

class GACGeoTileFetcher : public QGeoTileFetcher {
    Q_OBJECT
public:
    GACGeoTileFetcher(const QVariantMap &parameters,
                      QGeoMappingManagerEngine *parent);

private:
    QGeoTiledMapReply *getTileImage(const QGeoTileSpec &spec) override;
    QString getUrl(const QGeoTileSpec &spec) const;

private:
    QString mapUrl;
    QString format{"png"};
    QNetworkAccessManager *networkManager;
};

}  // namespace location
}  // namespace gove
