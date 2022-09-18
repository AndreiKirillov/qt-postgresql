#ifndef SENSORRECORDINT_H
#define SENSORRECORDINT_H

#include "SensorRecord.h"

class SensorRecordInt : public SensorRecord
{
private:
    int _int_value;
public:
    SensorRecordInt();
    SensorRecordInt(QDateTime time, int object_id, int sensor_id, int int_val, QString str = "");

    void print() const override;
    QDomElement convertToXml(QDomDocument& xml_root_doc) override;
};

#endif // SENSORRECORDINT_H
