#include "SensorRecordInt.h"

SensorRecordInt::SensorRecordInt()
{

}

SensorRecordInt::SensorRecordInt(QDateTime time, int object_id, int sensor_id, int int_val, QString str):
    SensorRecord(time, object_id, sensor_id, str), _int_value(int_val)
{

}

void SensorRecordInt::print() const
{
    SensorRecord::print();
    std::cout << "Int value: " << _int_value << std::endl;
}

QDomElement SensorRecordInt::convertToXml(QDomDocument &xml_root_doc)
{
    QDomElement record_elem = SensorRecord::convertToXml(xml_root_doc);

    QDomElement int_elem = xml_root_doc.createElement("int_value");
    QDomText int_val_text = xml_root_doc.createTextNode(QString::fromStdString(std::to_string(_int_value)));
    int_elem.appendChild(int_val_text);
    record_elem.appendChild(int_elem);

    return record_elem;
}
