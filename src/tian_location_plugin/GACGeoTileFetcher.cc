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
    : QGeoTileFetcher(parent), networkManager(new QNetworkAccessManager(this)) {
    if (parameters.contains("mapPath")) {
        mapUrl = QUrl::fromLocalFile(parameters.value("mapPath").toString())
                     .toString();
    }

    if (parameters.contains("format")) {
        format = parameters.value("format").toString();
    }
}

QGeoTiledMapReply *GACGeoTileFetcher::getTileImage(const QGeoTileSpec &spec) {
    QNetworkRequest request;
    request.setRawHeader("Accept", "*/*");
    request.setUrl(getUrl(spec));

    QNetworkReply *reply = networkManager->get(request);
    return new GACGeoTiledMapReply(reply, spec, format);
}

QString GACGeoTileFetcher::getUrl(const QGeoTileSpec &spec) const {
    const QString zz =
        QString("%1").arg(spec.zoom(), 2, 10, QLatin1Char('0')).toUpper();
    const QString yy =
        QString("%1").arg(spec.y(), 8, 16, QLatin1Char('0')).toUpper();
    const QString xx =
        QString("%1").arg(spec.x(), 8, 16, QLatin1Char('0')).toUpper();

    return QString("%1/L%2/R%3/C%4.%5")
        .arg(mapUrl)
        .arg(zz)
        .arg(yy)
        .arg(xx)
        .arg(format);
}

}  // namespace location
}  // namespace gove
