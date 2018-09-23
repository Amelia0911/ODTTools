#ifndef PARSEXML_H
#define PARSEXML_H

#include <QtXml>
#include <QMessageBox>

//数据结构
typedef struct ObjInfo
{
    QString name;
    int xmin;
    int ymin;
    int xmax;
    int ymax;
}ObjInfo;



//读取xml文件，并解析成指定数据结构的结果
class XMLReader
{
public:
    XMLReader(QString fileName);
    ~XMLReader();

    QList<ObjInfo> results;

private:
    void read(QString fileName);
//    QList<ObjInfo> getResult(QXmlStreamReader reader);


};



//生成xml文件
class XMLWriter
{
public:

};

#endif // PARSEXML_H
