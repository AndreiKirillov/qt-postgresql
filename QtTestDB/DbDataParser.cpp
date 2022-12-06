#include "DbDataParser.h"

DbDataParser::DbDataParser(std::shared_ptr<QSqlQueryModel>& model):
    _model(model), _data_rows(), _date_of_data()
{

}

void DbDataParser::processData()
{
    for (int i = 0; i < _model->rowCount(); ++i)
    {
        // читаем общие данные
        QDateTime record_time = _model->record(i).value("reading_time").toDateTime();
        _date_of_data = record_time.toString("yyyyMMdd_HH_mm_ss");    // сохраняем дату считывания данных

        int tech_object = _model->record(i).value("technology_object_id").toInt();
        int sensor_id = _model->record(i).value("sensor_id").toInt();
        QString string_value = _model->record(i).value("string_value").toString();

        //проверяем вещественный параметр
        auto double_value = _model->record(i).value("double_value");
        if(!double_value.isNull())
        {
            _data_rows.emplace_back(std::make_shared<SensorRecordDouble>(record_time, tech_object, sensor_id,
            double_value.toDouble(), string_value));
            continue;
        }

        //проверяем int параметр
        auto int_value = _model->record(i).value("int_value");
        if(!int_value.isNull())
        {
            _data_rows.emplace_back(std::make_shared<SensorRecordInt>(record_time, tech_object, sensor_id,
            int_value.toInt(), string_value));
            continue;
        }

        //проверяем bool параметр
        auto bool_value = _model->record(i).value("bool_value");
        if(!bool_value.isNull())
        {
            _data_rows.emplace_back(std::make_shared<SensorRecordBool>(record_time, tech_object, sensor_id,
            bool_value.toBool(), string_value));
        }
    }
}

void DbDataParser::printParsedData()
{
    for(auto& record : _data_rows)
    {
        record->print();
        std::cout << std::endl;
    }
}

void DbDataParser::convertToXml()
{
    QDomDocument document("VestaInpData");
    QDomElement root_elem = document.createElement("VestaInpData");
    document.appendChild(root_elem);

    QDomElement general_elem = document.createElement("General");
    root_elem.appendChild(general_elem);

    for(auto& record : _data_rows)
    {
        auto xml_record = record->convertToXml(document);
        general_elem.appendChild(xml_record);
    }


    QFile file (QString("IN_") + _date_of_data + QString(".xml"));
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << document.toString();
        file.close();
    }
}




