#ifndef SENSORRECORDDOUBLE_H
#define SENSORRECORDDOUBLE_H

#include "SensorRecord.h"

class SensorRecordDouble : public SensorRecord
{
private:
    double _double_value;
public:
    SensorRecordDouble();
    SensorRecordDouble(QDateTime time, int object_id, int sensor_id, double double_val, QString str = "");

    void print() const override;
    QDomElement convertToXml(QDomDocument& xml_root_doc) override;
};

#endif // SENSORRECORDDOUBLE_H
