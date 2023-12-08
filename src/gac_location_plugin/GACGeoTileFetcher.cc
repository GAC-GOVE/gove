#include "GACGeoTileFetcher.h"
#include "GACGeoTiledMapReply.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>
#include <QtLocation/private/qgeotilefetcher_p_p.h>
#include <QUrl>
#include <QDebug>

namespace gove {
namespace location {

GACGeoTileFetcher::GACGeoTileFetcher(const QVariantMap &parameters,
                                   QGeoMappingManagerEngine *parent)
    : QGeoTileFetcher(parent),
      network_manager_ptr_(new QNetworkAccessManager(this)) {}

static const QString tiandituImg = QStringLiteral(
    "http://t2.tianditu.gov.cn/img_w/"
    "wmts?SERVICE=WMTS&REQUEST=GetTile&VERSION=1.0.0&LAYER=img&STYLE=default&"
    "TILEMATRIXSET=w&FORMAT=tiles&TILEMATRIX=%1&TILEROW=%2&TILECOL=%3&tk=%4");

QString getURL(int x, int y, int zoom) {
    const QString s_x = QString("%1").arg(zoom);
    const QString s_y = QString("%1").arg(y);
    const QString s_z = QString("%1").arg(x);
    return tiandituImg.arg(s_x, s_y, s_z, "0aa1147d0129a72f6958656125461fe6");
}

QGeoTiledMapReply* GACGeoTileFetcher::getTileImage(const QGeoTileSpec &spec) {
    QNetworkRequest request;
    request.setRawHeader(QByteArrayLiteral("Accept"),
                         QByteArrayLiteral("text/html,image/*"));
    request.setRawHeader(
        QByteArrayLiteral("User-Agent"),
        QByteArrayLiteral(
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
            "(KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36"));
    auto url = getURL(spec.x(), spec.y(), spec.zoom());
    request.setUrl(QUrl(url));
    
    QNetworkReply *reply = network_manager_ptr_->get(request);
    return new GACGeoTiledMapReply(reply, spec);
}

}  // namespace location
}  // namespace gove
