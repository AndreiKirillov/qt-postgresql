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
    // элемент записи в xml
    QDomElement parameter_elem = xml_root_doc.createElement("Parameter");

    // Задаём шифр
    QDomAttr code_attribute = xml_root_doc.createAttribute("Code");
    code_attribute.setValue(_code);
    parameter_elem.setAttributeNode(code_attribute);

    // Задаём значение
    QDomAttr value_attribute = xml_root_doc.createAttribute("Value");
    value_attribute.setValue(_bool_value ? "true":"false");
    parameter_elem.setAttributeNode(value_attribute);

    return parameter_elem;
}
