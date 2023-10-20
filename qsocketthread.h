#ifndef QSOCKETTHREAD_H
#define QSOCKETTHREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QTime>

class QSocketThread : public QThread
{
    Q_OBJECT
public:
    explicit QSocketThread(int descriptor, QObject *parent = 0);
    ~QSocketThread();

    void run();

public slots:
    void onReadyRead();
    void onDisconnected();

private:
    int socketDescriptor;
    QTcpSocket* socket;
};

#endif // QSOCKETTHREAD_H
