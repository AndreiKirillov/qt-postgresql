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
    // элемент записи в xml
    QDomElement parameter_elem = xml_root_doc.createElement("Parameter");

    // Задаём шифр
    QDomAttr code_attribute = xml_root_doc.createAttribute("Code");
    code_attribute.setValue(QString::number(_sensor_id));
    parameter_elem.setAttributeNode(code_attribute);

    // Задаём значение
    QDomAttr value_attribute = xml_root_doc.createAttribute("Value");
    value_attribute.setValue(QString::number(_int_value));
    parameter_elem.setAttributeNode(value_attribute);

    return parameter_elem;
}
