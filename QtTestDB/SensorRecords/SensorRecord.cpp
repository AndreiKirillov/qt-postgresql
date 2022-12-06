#include "SensorRecord.h"

SensorRecord::SensorRecord()
{

}

SensorRecord::SensorRecord(QDateTime time, int object_id, int sensor_id, QString str):
    _record_time(time), _technology_object(object_id), _sensor_id(sensor_id), _string_value(str)
{
    _code = QString::number(_technology_object) + QString::number(_sensor_id);
}

void SensorRecord::print() const
{
    std::cout << "Time: " << _record_time.toString("yyyy-MM-dd  HH:mm:ss").toStdString()<<std::endl
              << "Tech object: " << _technology_object << std::endl
              << "Sensor id: " << _sensor_id << std::endl;
    if(!_string_value.isEmpty())
        std::cout << "String value: " << _string_value.toStdString() <<std::endl;
}

QDomElement SensorRecord::convertToXml(QDomDocument& xml_root_doc)
{
    // элемент записи в xml
    QDomElement parameter_elem = xml_root_doc.createElement("Parameter");

    // устанавливаем уникальный атрибут записи
    /*QDomAttr record_attribute = xml_root_doc.createAttribute("id");
    std::string attr_value = _record_time.toString("yyyyMMdd_HH_mm_ss").toStdString() + " "
            + std::to_string(_technology_object) + " " + std::to_string(_sensor_id);
    record_attribute.setValue(QString::fromStdString(attr_value));
    parameter_elem.setAttributeNode(record_attribute);

    QDomAttr code_attribute = xml_root_doc.createAttribute("Code");
    std::string code_value = _record_time.toString("yyyyMMdd_HH_mm_ss").toStdString() + " "
            + std::to_string(_technology_object) + " " + std::to_string(_sensor_id);
    code_attribute.setValue(_code);
    parameter_elem.setAttributeNode(code_attribute);

    QDomAttr value_attribute = xml_root_doc.createAttribute("Value");
    std::string code_value = _record_time.toString("yyyyMMdd_HH_mm_ss").toStdString() + " "
            + std::to_string(_technology_object) + " " + std::to_string(_sensor_id);
    code_attribute.setValue(_code);
    parameter_elem.setAttributeNode(code_attribute);
    em.appendChild(date_elem);

        QDomElement tech_object_elem = xml_root_doc.createElement("technology object");
        QDomText tech_obj_text = xml_root_doc.createTextNode(QString::fromStdString(std::to_string(_technology_object)));
        tech_object_elem.appendChild(tech_obj_text);
        parameter_elem.appendChild(tech_object_elem);

    // элемент даты
    QDomElement date_elem = xml_root_doc.createElement("reading_time");
    QDomText date_text = xml_root_doc.createTextNode(_record_time.toString("yyyy-MM-dd  HH:mm:ss"));
    date_elem.appendChild(date_text);
    parameter_el
    QDomElement sensor_elem = xml_root_doc.createElement("sensor_id");
    QDomText sensor_text = xml_root_doc.createTextNode(QString::fromStdString(std::to_string(_sensor_id)));
    sensor_elem.appendChild(sensor_text);
    parameter_elem.appendChild(sensor_elem);

    if(!_string_value.isEmpty())
    {
        QDomElement string_elem = xml_root_doc.createElement("string_value");
        QDomText str_text = xml_root_doc.createTextNode(_string_value);
        string_elem.appendChild(str_text);
        parameter_elem.appendChild(string_elem);
    }*/

    return parameter_elem;
}


