#ifndef SENSORRECORDBOOL_H
#define SENSORRECORDBOOL_H

#include "SensorRecord.h"

class SensorRecordBool : public SensorRecord
{
private:
    bool _bool_value;
public:
    SensorRecordBool();
    SensorRecordBool(QDateTime time, int object_id, int sensor_id, bool bool_val, QString str = "");

    void print() const override;
    QDomElement convertToXml(QDomDocument& xml_root_doc) override;
};

#endif // SENSORRECORDBOOL_H
