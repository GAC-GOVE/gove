#include "GACGeoTileFetcher.h"
#include "GACGeoTiledMapReply.h"
#include "GACMapEngine.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>
#include <QtLocation/private/qgeotilefetcher_p_p.h>
#include <QUrl>
#include <string>
#include <QDebug>

namespace gove {
namespace location {

GACGeoTileFetcher::GACGeoTileFetcher(const QVariantMap &parameters,
                                   QGeoMappingManagerEngine *parent)
    : QGeoTileFetcher(parent),
      network_manager_ptr_(new QNetworkAccessManager(this)) {}

QGeoTiledMapReply* GACGeoTileFetcher::getTileImage(const QGeoTileSpec &spec) {
    QNetworkRequest request;

    request.setRawHeader(QByteArrayLiteral("Accept"),
                         QByteArrayLiteral("text/html,image/*"));
    request.setRawHeader(QByteArrayLiteral("User-Agent"),
                         QByteArrayLiteral("Mozilla/5.0"));

    auto url = GACMapEngine::Instance().GetURL(spec.x(), spec.y(), spec.zoom());
    request.setUrl(QUrl(QString::fromStdString(url)));
    
    QNetworkReply *reply = network_manager_ptr_->get(request);
    return new GACGeoTiledMapReply(reply, spec);
}

}  // namespace location
}  // namespace gove
