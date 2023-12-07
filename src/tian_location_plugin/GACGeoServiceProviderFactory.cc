#include "GACGeoServiceProviderFactory.h"
#include "GACGeoTiledMappingManagerEngine.h"

#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

Q_EXTERN_C Q_DECL_EXPORT const char *qt_plugin_query_metadata();
Q_EXTERN_C Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance();

const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_MyMapPlugin()
{
    QT_PREPEND_NAMESPACE(QStaticPlugin) plugin = { qt_plugin_instance, qt_plugin_query_metadata};
    return plugin;
}

namespace gove {
namespace location {

QGeoMappingManagerEngine *
GACGeoServiceProviderFactory::createMappingManagerEngine(
    const QVariantMap &parameters, QGeoServiceProvider::Error *error,
    QString *errorString) const {
    return new GACGeoTiledMappingManagerEngine(parameters, error, errorString);
}

}  // namespace location
}  // namespace gove
