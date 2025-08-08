#include <QApplicationStatic>

#include "POIManager.h"
#include "POI.h"

Q_APPLICATION_STATIC(POIManager, _poiManagerInstance);

POIManager::POIManager(QObject *parent)
    : QObject(parent), _poiList(new QmlObjectListModel(this))
{}

POIManager *POIManager::instance()
{
    return _poiManagerInstance();
}

void POIManager::addCoordinate(const QGeoCoordinate &coord) {
    _poiList->append(new POI(coord, this));
}

void POIManager::removePoi(QObject* poi) {
    POI* poiItem = qobject_cast<POI*>(poi);
    if(poiItem) {
        _poiList->removeOne(poiItem);
    }
}