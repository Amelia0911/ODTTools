#include <parsexml.h>

XMLReader::XMLReader(QString fileName)
{
    read(fileName);

}

XMLReader::~XMLReader()
{

}

//TODO:此部分代码只是功能完成，代码需要重构
void XMLReader::read(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Error: Cannot read file " ;
    }
    QXmlStreamReader reader(&file);
    reader.readNext();
    QString strCharacters;
    ObjInfo result;
    while( !reader.atEnd() )
    {
        QXmlStreamReader::TokenType nType = reader.readNext();
        switch( nType )
        {
            // 开始文档
            case QXmlStreamReader::StartDocument:
            {
                QString strVersion = reader.documentVersion().toString();
                QString strEncoding = reader.documentEncoding().toString();
                bool bAlone = reader.isStandaloneDocument();
                qDebug() << "开始文档";
                break;
            }
            // 注释
            case QXmlStreamReader::Comment:
            {
                QString strComment = reader.text().toString();
                //qDebug() << strComment ;
                break;
            }
            // 处理指令
            case QXmlStreamReader::ProcessingInstruction:
            {
                QString strProcInstr = reader.processingInstructionData().toString();
                //qDebug() << strProcInstr << "\r\n";
                break;
            }
            // DTD
            case QXmlStreamReader::DTD:
            {
                qDebug() << QString::fromLocal8Bit("********** DTD ********** ");
                QString strDTD = reader.text().toString();
                QXmlStreamNotationDeclarations notationDeclarations = reader.notationDeclarations();  // 符号声明
                QXmlStreamEntityDeclarations entityDeclarations = reader.entityDeclarations();  // 实体声明
                // DTD 声明
                QString strDTDName = reader.dtdName().toString();
                QString strDTDPublicId = reader.dtdPublicId().toString();  // DTD 公开标识符
                QString strDTDSystemId = reader.dtdSystemId().toString();  // DTD 系统标识符
                qDebug() << QString::fromLocal8Bit("DTD : %1").arg(strDTD);
                qDebug() << QString::fromLocal8Bit("DTD 名称 : %1").arg(strDTDName);
                qDebug() << QString::fromLocal8Bit("DTD 公开标识符 : %1").arg(strDTDPublicId);
                qDebug() << QString::fromLocal8Bit("DTD 系统标识符 : %1").arg(strDTDSystemId);
                qDebug() << "\r\n";
                break;
            }
            // 开始元素
            case QXmlStreamReader::StartElement:
            {
                QString strElementName = reader.name().toString();
                // 根元素
                if (QString::compare( strElementName, "annotation") == 0)
                {
                    qDebug() << "enter in annotation";
                    QXmlStreamAttributes attributes = reader.attributes();
                    if (attributes.hasAttribute("object"))
                    {
                        QString strVersion = attributes.value("Version").toString();
                        qDebug() << QString::fromLocal8Bit("属性：Version(%1)").arg(strVersion);
                    }
         //start========================================
                    while( !reader.atEnd() )
                    {
                        reader.readNext();
                        if (reader.isStartElement())
                        {  // 开始元素
                            strElementName = reader.name().toString();
                            reader.readNext();
                            if (reader.isCharacters())
                            {
                                strCharacters = reader.text().toString();
                                //    qDebug() << QString("Characters : %1").arg(strCharacters);
                            }
                            //   QString strText = reader.text().toString();

                            // qDebug() << QString::fromLocal8Bit("********** 开始元素<") << strElementName << QString::fromLocal8Bit("> ********** ") << strCharacters;
                            if( QString( "folder" ) == strElementName )
                            {
                                //image_head.folder = strCharacters;
                            }
                            else if( QString( "filename" ) == strElementName )
                            {
                                //image_head.filename = strCharacters;
                            }
                            else if( QString( "path" ) == strElementName )
                            {
                                //image_head.path = strCharacters;
                            }
                            else if( QString( "source" ) == strElementName )
                            {
                                //image_head.source = strCharacters;
                            }
                            else if( QString( "database" ) == strElementName )
                            {
                                //image_head.database = strCharacters;
                            }
                            else if( QString( "width" ) == strElementName )
                            {
                                //image_head.image_width = strCharacters.toInt( &ok );

                            }
                            else if( QString( "height" ) == strElementName )
                            {
                                //image_head.image_height = strCharacters.toInt( &ok );
                            }
                            else if( QString( "depth" ) == strElementName )
                            {
                                //image_head.image_depth = strCharacters.toInt( &ok );

                            }
                            else if( QString( "segmented" ) == strElementName )
                            {
                                //image_head.segmented = strCharacters.toInt( &ok );

                            }
                            else if( QString( "object" ) == strElementName )
                            {
                                while(!reader.atEnd() )
                                {
                                    reader.readNext();
                                    if (reader.isStartElement())
                                    {  // 开始元素
                                        strElementName = reader.name().toString();
                                        reader.readNext();
                                        if (reader.isCharacters())
                                        {
                                            strCharacters = reader.text().toString();
                                        }
                                        //       qDebug() << QString::fromLocal8Bit("********** 开始元素<") << strElementName << QString::fromLocal8Bit("> ********** ") << strCharacters;
                                        if( QString( "name" ) == strElementName )
                                        {
                                            //obj.class_name = strCharacters;
                                            qDebug() << "name" << strCharacters;
                                            result.name = strCharacters;
                                        }
                                        else if( QString( "pose" ) == strElementName )
                                        {
                                            //obj.pose = strCharacters;
                                        }
                                        else if( QString( "truncated" ) == strElementName )
                                        {
                                            //obj.truncated = strCharacters.toInt( &ok );

                                        }
                                        else if( QString( "difficult" ) == strElementName )
                                        {
                                            //obj.difficult = strCharacters.toInt( &ok );

                                        }
                                        else if( QString( "xmin" ) == strElementName )
                                        {
                                            qDebug() << "xmin" << strCharacters;
                                            result.xmin = strCharacters.toInt();
                                        }
                                        else if( QString( "ymin" ) == strElementName )
                                        {
                                            result.ymin = strCharacters.toInt();
                                            qDebug() << "ymin" << strCharacters;
                                        }
                                        else if( QString( "xmax" ) == strElementName )
                                        {
                                            result.xmax = strCharacters.toInt();
                                            qDebug() << "xmax" << strCharacters;
                                        }
                                        else if( QString( "ymax" ) == strElementName )
                                        {
                                            result.ymax = strCharacters.toInt();
                                            qDebug() << "ymax" << strCharacters;
                                        }

                                    }
                                    else if ( reader.isEndElement() )
                                    {  // 结束元素
                                        QString strElementName = reader.name().toString();
                                        if( 0 == strElementName.compare( "object" ) )
                                        {
                                            results.push_back(result);
                                        }

                                    }
                                }
                            }
                        }
                        else if (reader.isEntityReference())
                        {  // 实体引用
                            QString strName = reader.name().toString();
                            QString strText = reader.text().toString();
                            qDebug() << QString("EntityReference : %1(%2)").arg(strName).arg(strText);
                        }
                        else if (reader.isCDATA())
                        {  // CDATA
                            reader.readNext();
                            if (reader.isCharacters())
                            {
                                QString strCharacters = reader.text().toString();
                                //        qDebug() << QString("Characters : %1").arg(strCharacters);
                            }
                        }
                        else if (reader.isEndElement())
                        {  // 结束元素
                            QString strElementName = reader.name().toString();
                            //     qDebug() << QString::fromLocal8Bit("********** 结束元素<") << strElementName << QString::fromLocal8Bit("> ********** ");
                        }
                        else if (reader.isDTD())
                        {  // CDATA
                            QString strDTD = reader.text().toString();
                            //     qDebug() << QString("DTD : %1").arg(strDTD);

                            reader.readNext();
                            if (reader.isCharacters())
                            {
                                QString strCharacters = reader.text().toString();
                                //        qDebug() << QString("Characters : %1").arg(strCharacters);
                            }
                        }
                    }

                }
                break;
            }
            // 结束文档
            case QXmlStreamReader::EndDocument:
            {
                qDebug() << QString::fromLocal8Bit("********** 结束文档 ********** ");
                break;
            }
            default:
                break;
        }
    }
}

