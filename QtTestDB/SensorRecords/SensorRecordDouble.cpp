#include "SensorRecordDouble.h"

SensorRecordDouble::SensorRecordDouble()
{

}

SensorRecordDouble::SensorRecordDouble(QDateTime time, int object_id, int sensor_id, double double_val, QString str):
    SensorRecord(time, object_id, sensor_id, str), _double_value(double_val)
{

}

void SensorRecordDouble::print() const
{
    SensorRecord::print();
    std::cout << "Double value: " << _double_value << std::endl;
}

QDomElement SensorRecordDouble::convertToXml(QDomDocument &xml_root_doc)
{
    QDomElement record_elem = SensorRecord::convertToXml(xml_root_doc);

    QDomElement double_elem = xml_root_doc.createElement("double_value");
    QDomText double_val_text = xml_root_doc.createTextNode(QString::fromStdString(std::to_string(_double_value)));
    double_elem.appendChild(double_val_text);
    record_elem.appendChild(double_elem);

    return record_elem;
}
