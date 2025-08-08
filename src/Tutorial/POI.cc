#include "POI.h"

POI::POI(QGeoCoordinate coordinate, QObject *parent)
    : QObject(parent), _coordinate(coordinate)
{
}

void POI::setCoordinate(const QGeoCoordinate& coordinate)
{
    if (_coordinate != coordinate) {
        _coordinate = coordinate;
        emit coordinateChanged();
    }
}