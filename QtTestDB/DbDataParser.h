#ifndef DBDATAPARSER_H
#define DBDATAPARSER_H

#include "DbReader.h"
#include "SensorRecords/SensorRecord.h"
#include "SensorRecords/SensorRecordDouble.h"
#include "SensorRecords/SensorRecordInt.h"
#include "SensorRecords/SensorRecordBool.h"

#include <QtXml>
#include <QSqlRecord>
#include <vector>

class DbDataParser
{
private:
    // модель, полученная из базы
    std::shared_ptr<QSqlQueryModel> _model;

    // прочитанные и обработанные данные
    std::vector<std::shared_ptr<SensorRecord>> _data_rows;
public:
    DbDataParser(std::shared_ptr<QSqlQueryModel>& model);

    void processData();

    void printParsedData();

    void convertToXml();
};

#endif // DBDATAPARSER_H
