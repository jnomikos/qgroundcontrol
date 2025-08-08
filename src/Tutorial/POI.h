#pragma once

#include <QtCore/QObject>
#include <QString>
#include <QGeoCoordinate>

class POI: public QObject {
    Q_OBJECT

    Q_PROPERTY(QGeoCoordinate coordinate READ coordinate WRITE setCoordinate NOTIFY coordinateChanged)
public:
    POI(QGeoCoordinate coordinate, QObject *parent = nullptr);

    QGeoCoordinate coordinate() const { return _coordinate; }

    void setCoordinate(const QGeoCoordinate& coordinate);

signals:
    void coordinateChanged();

private:
    QGeoCoordinate _coordinate;
};