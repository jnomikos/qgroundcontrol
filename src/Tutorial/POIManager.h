#pragma once

#include <QtCore/QObject>
#include <QString>
#include <QList>
#include <QGeoCoordinate>

#include "QmlObjectListModel.h"

class POIManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(const QmlObjectListModel* poiList READ poiList CONSTANT)
public:
    POIManager(QObject *parent = nullptr);
    static POIManager *instance();

    Q_INVOKABLE void addCoordinate(const QGeoCoordinate &coord);
    Q_INVOKABLE void removePoi(QObject* poi);


    const QmlObjectListModel* poiList() const { return _poiList; }

private:
    QmlObjectListModel* _poiList = nullptr;
};

