#ifndef DETECT_H
#define DETECT_H
#include <QThread>


//目标检测器，另起一个线程
class Detecter :public QThread
{
public:
    Detecter()
    {

    }
    ~Detecter()
    {

    }

};

#endif // DETECT_H
