#include "tcpserv.hh"

TcpServ::TcpServ(QWidget *parent)
    : QWidget{parent}
{
    server = new QTcpServer();


    if(server->listen(QHostAddress::Any, 8080)){

        connect(server, SIGNAL(newConnection()),this,SLOT(newConnection()));
        QMessageBox::information(this,"info","Server started");
    }

    else{
        QMessageBox::information(this,"info","Server start fail");
    }


}

void TcpServ::Read_Data_From_Socket() {
    QTcpSocket *s = qobject_cast<QTcpSocket*>(sender());
    QByteArray msg = s->readAll();

    //qDebug() << msg;

    QTextStream stream(&msg);
    QVector<float> dataVector;

    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed(); // Trim leading and trailing whitespaces

        if (line.isEmpty() || line == "\r\n") // Skip empty lines or lines containing only "\r\n"
            continue;

        QStringList values = line.split(" ");

        if (values.size() < 6) // If less than 6 values in a line, skip it
            continue;

        QVector<float> lineData;
        for (const QString& value : values) {
            bool conversionOK;
            float floatValue = value.toFloat(&conversionOK);
            if (conversionOK)
                lineData.append(floatValue);
        }

        if (lineData.size() == 6)
            dataVector.append(lineData);
    }

    if (!dataVector.isEmpty()) {
        emit valueSharpChanged(dataVector[2]);
        emit valueTof1Changed(dataVector[3]);
        emit valueTof2Changed(dataVector[4]);
        emit valueMotor1Changed(dataVector[5]);
    }
}



void TcpServ::newConnection()
{
    while(server->hasPendingConnections()){
        Add_New_Client_Connection(server->nextPendingConnection());
    }
}

void TcpServ::Add_New_Client_Connection(QTcpSocket *s)
{
    Client_Connection_List.append(s);
    connect(s, SIGNAL(readyRead()), this, SLOT(Read_Data_From_Socket()));
    QString Client = "Client" + QString::number(s->socketDescriptor()) + " Connected.";

}

