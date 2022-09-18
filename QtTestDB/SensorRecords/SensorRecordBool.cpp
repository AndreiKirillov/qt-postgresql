#include "SensorRecordBool.h"

SensorRecordBool::SensorRecordBool()
{

}

SensorRecordBool::SensorRecordBool(QDateTime time, int object_id, int sensor_id, bool bool_val, QString str):
    SensorRecord(time, object_id, sensor_id, str), _bool_value(bool_val)
{

}

void SensorRecordBool::print() const
{
    SensorRecord::print();
    std::cout << "Bool value: " << (_bool_value ? "true":"false") << std::endl;
}

QDomElement SensorRecordBool::convertToXml(QDomDocument &xml_root_doc)
{
    QDomElement record_elem = SensorRecord::convertToXml(xml_root_doc);

    QDomElement bool_elem = xml_root_doc.createElement("bool_value");
    QDomText bool_text = xml_root_doc.createTextNode(_bool_value ? "true":"false");
    bool_elem.appendChild(bool_text);
    record_elem.appendChild(bool_elem);

    return record_elem;
}
