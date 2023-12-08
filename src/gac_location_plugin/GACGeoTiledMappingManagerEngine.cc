#include "GACGeoTiledMappingManagerEngine.h"
#include "GACGeoTileFetcher.h"

#include <QtLocation/private/qgeocameracapabilities_p.h>
#include <QtLocation/private/qgeomaptype_p.h>
#include <QtLocation/private/qgeotiledmap_p.h>
#include <QtLocation/private/qgeofiletilecache_p.h>

namespace gove {
namespace location {

GACGeoTiledMappingManagerEngine::GACGeoTiledMappingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error,
    QString *errorString) {
    Init(parameters, error,errorString);
}

GACGeoTiledMappingManagerEngine::~GACGeoTiledMappingManagerEngine() {}

QGeoMap *GACGeoTiledMappingManagerEngine::createMap() {
    QGeoTiledMap *map = new QGeoTiledMap(this, nullptr);
    map->setPrefetchStyle(m_prefetchStyle);
    return map;
}

void GACGeoTiledMappingManagerEngine::Init(const QVariantMap &parameters,
                                           QGeoServiceProvider::Error *error,
                                           QString *errorString) {
    InitCameraCapabilities(parameters);
    InitTileFetcher(parameters);
    InitTileCache(parameters);

    m_prefetchStyle = QGeoTiledMap::NoPrefetching;
    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

void GACGeoTiledMappingManagerEngine::InitTileCache(
    const QVariantMap &parameters) {
    QString cache_dir;
    if (parameters.contains("MapChacheDirectory")) {
        cache_dir =
            parameters.value("MapChacheDirectory").toString();
    } else {
        cache_dir = QAbstractGeoTileCache::baseLocationCacheDirectory();
    }
    QGeoFileTileCache *tile_cache = new QGeoFileTileCache(cache_dir, this);
    const int cache_size = 512 * 1024 * 1024;
    tile_cache->setMaxDiskUsage(cache_size);
    setTileCache(tile_cache);
}

void GACGeoTiledMappingManagerEngine::InitCameraCapabilities(
    const QVariantMap &parameters) {
    QGeoCameraCapabilities camera_caps;
    camera_caps.setMinimumZoomLevel(2.0);
    camera_caps.setMaximumZoomLevel(20.0);
    camera_caps.setSupportsBearing(true);
    camera_caps.setSupportsTilting(true);
    camera_caps.setMinimumTilt(0);
    camera_caps.setMaximumTilt(80);
    camera_caps.setMinimumFieldOfView(20.0);
    camera_caps.setMaximumFieldOfView(120.0);
    camera_caps.setOverzoomEnabled(true);

    setCameraCapabilities(camera_caps);
}
void GACGeoTiledMappingManagerEngine::InitTileFetcher(
    const QVariantMap &parameters) {
    GACGeoTileFetcher *tile_fetcher = new GACGeoTileFetcher(parameters, this);
    setTileSize(QSize(256, 256));
    setTileFetcher(tile_fetcher); 
}

}  // namespace location
}  // namespace gove
