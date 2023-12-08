#include "GACTianMapProvider.h"
#include <QString>

namespace gove {
namespace location {

GACTianMapProvider::GACTianMapProvider(const std::string& token)
    : token_(token) {}

std::string GACTianMapProvider::GetMapName() { return map_name_; }

std::string GACTianMapProvider::GetHost() { return host_; }

static const QString tiandituImg = QStringLiteral(
    "http://t0.tianditu.gov.cn/img_w/"
    "wmts?SERVICE=WMTS&REQUEST=GetTile&VERSION=1.0.0&LAYER=img&STYLE=default&"
    "TILEMATRIXSET=w&FORMAT=tiles&TILEMATRIX=%1&TILEROW=%2&TILECOL=%3&tk=%4");

std::string GACTianMapProvider::GetURL(int x, int y, int zoom) {
    QString s_x = QString("%1").arg(zoom);
    QString s_y = QString("%1").arg(y);
    QString s_z = QString("%1").arg(x);
    auto url_qstring =
        tiandituImg.arg(s_x, s_y, s_z, QString::fromStdString(token_));
    return url_qstring.toStdString();
}

}  // namespace location
}  // namespace gove
