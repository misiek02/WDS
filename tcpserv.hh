#ifndef TCPSERV_HH
#define TCPSERV_HH

#include <QWidget>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QMessageBox>


class TcpServ : public QWidget
{
    Q_OBJECT
public:
    explicit TcpServ(QWidget *parent = nullptr);

private slots:
    void newConnection();
    void Read_Data_From_Socket();



signals:
    void valueSharpChanged(int value);
    void valueTof1Changed(int value);
    void valueTof2Changed(int value);
    void valueMotor1Changed(int value);
private:
    void Add_New_Client_Connection(QTcpSocket *s);

private:
    QVector<float> dataVector;
    QTcpServer *server;
    QList<QTcpSocket*> Client_Connection_List;
};

#endif // TCPSERV_HH
