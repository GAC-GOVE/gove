#include "GACGeoTileFetcher.h"
#include "GACGeoTiledMapReply.h"
#include "GACTianMapProvider.h"

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

    const std::string token{"9f275adccbcced91899b403723c22172"};
    GACTianMapProvider provider(token);

    auto url = provider.GetURL(spec.x(), spec.y(), spec.zoom());
    request.setUrl(QUrl(QString::fromStdString(url)));
    
    QNetworkReply *reply = network_manager_ptr_->get(request);
    return new GACGeoTiledMapReply(reply, spec);
}

}  // namespace location
}  // namespace gove
