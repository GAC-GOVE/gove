#include "GACGeoTiledMappingManagerEngine.h"
#include "GACGeoTileFetcher.h"

#include <QtLocation/private/qgeocameracapabilities_p.h>
#include <QtLocation/private/qgeomaptype_p.h>
#include <QtLocation/private/qgeotiledmap_p.h>
#include <QtLocation/private/qgeofiletilecache_p.h>

namespace gove {
namespace location {

namespace {

QGeoCameraCapabilities GetGeoCameraCapabilities() {
    QGeoCameraCapabilities camera_caps;
    camera_caps.setMinimumZoomLevel(0.0);
    camera_caps.setMaximumZoomLevel(20.0);
    camera_caps.setSupportsBearing(true);
    camera_caps.setSupportsTilting(true);
    camera_caps.setMinimumTilt(0);
    camera_caps.setMaximumTilt(80);
    camera_caps.setMinimumFieldOfView(20.0);
    camera_caps.setMaximumFieldOfView(120.0);
    camera_caps.setOverzoomEnabled(true);
    return camera_caps;
}

}

GACGeoTiledMappingManagerEngine::GACGeoTiledMappingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error,
    QString *errorString) {

    auto camera_caps = GetGeoCameraCapabilities();
    setCameraCapabilities(camera_caps);
    
    GACGeoTileFetcher *tile_fetcher = new GACGeoTileFetcher(parameters, this);
    setTileSize(QSize(256, 256));
    setTileFetcher(tile_fetcher);

    m_prefetchStyle = QGeoTiledMap::NoPrefetching;
    m_prefetchStyle = QGeoTiledMap::NoPrefetching;
    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

GACGeoTiledMappingManagerEngine::~GACGeoTiledMappingManagerEngine() {}

QGeoMap *GACGeoTiledMappingManagerEngine::createMap() {
    QGeoTiledMap *map = new QGeoTiledMap(this, nullptr);
    map->setPrefetchStyle(m_prefetchStyle);
    return map;
}

}  // namespace location
}  // namespace gove
