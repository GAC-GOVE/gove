import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtPositioning 5.12
import QtLocation 5.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("GACLocation")

    Map {
        id: map
        anchors.fill: parent
        minimumZoomLevel: 2
        maximumZoomLevel: 22
        zoomLevel: 16

        center: QtPositioning.coordinate(23.038,113.497) //GAC

        plugin: Plugin {
            name: "GACMap" //"esri" "mapbox" "osm" "here"

            PluginParameter {
                name: "MapChacheDirectory"
                value: applicationDirPath+"/MapChache"
            }
        }

        Component.onCompleted: {
            
        }
    }
}
