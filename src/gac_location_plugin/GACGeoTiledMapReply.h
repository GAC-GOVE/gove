#pragma once
#include <QtNetwork/QNetworkReply>
#include <QtLocation/private/qgeotiledmapreply_p.h>

namespace gove {
namespace location {

class GACGeoTiledMapReply : public QGeoTiledMapReply {
    Q_OBJECT

public:
    GACGeoTiledMapReply(QNetworkReply *reply, const QGeoTileSpec &spec,
                        QObject *parent = nullptr);

private Q_SLOTS:
    void networkReplyFinished();
    void networkReplyError(QNetworkReply::NetworkError error);
};

}  // namespace location
}

