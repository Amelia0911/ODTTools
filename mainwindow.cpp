#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_openTestDir_clicked()
{
    QString file_path = QFileDialog::getExistingDirectory(this,"请选择图片路径...","/");
    if(!file_path.isEmpty())
    {
        ui->lineEdit->setText(file_path);
    }
}


void MainWindow::on_pushButton_start_clicked()
{
    QString dirName = ui->lineEdit->text();
    QDir dir(dirName);
    if(!dir.exists())
    {
        QMessageBox::information(NULL, QString("title"), QString("Dir path is invalid!"));
        return;
    }
    QStringList nameFilters;
    nameFilters << "*.xml";
    QFileInfoList files = dir.entryInfoList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

    for (int i = 0; i < files.size(); ++i)
    {
        QString tmp = files.at(i).absoluteFilePath();
        XMLReader XmlReader(tmp);
        QList<ObjInfo> result = XmlReader.results;
        qDebug() << "the num of obj: " << result.size();
        for(int i = 0;i < result.size();i++)
        {
            qDebug() << result.at(i).name;
            qDebug() << result.at(i).xmin;
            qDebug() << result.at(i).ymin;
            qDebug() << result.at(i).xmax;
            qDebug() << result.at(i).ymax;
            qDebug() << "++++++++++++++++++++";
        }

    }
    /*
    XMLReader XmlReader("/Users/lcgcf/Desktop/xml/1.xml");
    QList<ObjInfo> result = XmlReader.results;
    qDebug() << "the num of obj: " << result.size();
    for(int i = 0;i < result.size();i++)
    {
        qDebug() << result.at(i).name;
        qDebug() << result.at(i).xmin;
        qDebug() << result.at(i).ymin;
        qDebug() << result.at(i).xmax;
        qDebug() << result.at(i).ymax;
        qDebug() << "++++++++++++++++++++";
    }
    */
}
