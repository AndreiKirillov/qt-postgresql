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
    // элемент записи в xml
    QDomElement parameter_elem = xml_root_doc.createElement("Parameter");

    // Задаём шифр
    QDomAttr code_attribute = xml_root_doc.createAttribute("Code");
    code_attribute.setValue(QString::number(_sensor_id));
    parameter_elem.setAttributeNode(code_attribute);

    // Задаём значение
    QDomAttr value_attribute = xml_root_doc.createAttribute("Value");
    value_attribute.setValue(QString::number(_double_value));
    parameter_elem.setAttributeNode(value_attribute);

    return parameter_elem;
}
