#ifndef SENSORRECORD_H
#define SENSORRECORD_H

#include <iostream>
#include <QString>
#include <QDateTime>
#include <QtXml>

class SensorRecord
{
protected:
    QDateTime _record_time;
    int _technology_object;
    int _sensor_id;
    QString _code;   // шифр = ид_объекта + ид_сенсора
    QString _string_value;
public:
    SensorRecord();
    SensorRecord(QDateTime time, int object_id, int sensor_id, QString str = "");

    virtual void print() const;
    virtual QDomElement convertToXml(QDomDocument& xml_root_doc);
};

#endif // SENSORRECORD_H
