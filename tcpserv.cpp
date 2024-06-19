#include "tcpserv.hh"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>

TcpServ::TcpServ(QWidget *parent)
    : QWidget{parent}, server(new QTcpServer(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // xEdit = new QLineEdit(this);
    // xEdit->setPlaceholderText("Enter X value");
    // yEdit = new QLineEdit(this);
    // yEdit->setPlaceholderText("Enter Y value");

    // sendButton = new QPushButton("Send Coordinates", this);

    // layout->addWidget(xEdit);
    // layout->addWidget(yEdit);
    // layout->addWidget(sendButton);

    if (server->listen(QHostAddress::Any, 8080)) {
        connect(server, &QTcpServer::newConnection, this, &TcpServ::newConnection);
        QMessageBox::information(this, "Info", tr("Server started"));
    } else {
        QMessageBox::information(this, "Info", tr("Server start fail"));
    }

  //  connect(sendButton, &QPushButton::clicked, this, &TcpServ::sendData);
}

void TcpServ::Read_Data_From_Socket() {
    QTcpSocket *s = qobject_cast<QTcpSocket*>(sender());
    QByteArray msg = s->readAll();
    qDebug() << "Received data:" << msg;

    QTextStream stream(&msg);
    QVector<float> dataVector;

    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();
        if (line.isEmpty() || line == "\r\n")
            continue;

        QStringList values = line.split(" ");
        if (values.size() < 9)
            continue;

        QVector<float> lineData;
        for (const QString& value : values) {
            bool conversionOK;
            float floatValue = value.toFloat(&conversionOK);
            if (!conversionOK) {
                qDebug() << "Failed to convert value to float:" << value;
                break;
            }
            lineData.append(floatValue);
        }

        if (lineData.size() == 9)
            dataVector.append(lineData);
    }

    if (!dataVector.isEmpty()) {
        emit accelerationXChanged(dataVector[0]);
        emit accelerationYChanged(dataVector[1]);
        emit valueSharpChanged(dataVector[2]);
        emit valueTof1Changed(dataVector[3]);
        emit valueTof2Changed(dataVector[4]);
        emit valueXChanged(dataVector[5]);
        emit valueYChanged(dataVector[6]);
        emit valueAngleChanged(dataVector[7]);
        emit valueSpeedChanged(dataVector[8]);

    }
}

void TcpServ::newConnection() {
    while (server->hasPendingConnections()) {
        Add_New_Client_Connection(server->nextPendingConnection());
    }
}

void TcpServ::Add_New_Client_Connection(QTcpSocket *s) {
    if (!s) {
        qDebug() << "Add_New_Client_Connection: Invalid socket";
        return;
    }

    Client_Connection_List.append(s);
    connect(s, &QTcpSocket::readyRead, this, &TcpServ::Read_Data_From_Socket);

   // QString Client = "Client " + QString::number(s->socketDescriptor()) + " Connected.";
    //qDebug() << Client;
}

void TcpServ::sendDataToSocket(const QByteArray &data) {

    foreach(QTcpSocket *socket, Client_Connection_List){
        socket->write(data);
        qDebug() << data << "\n";

    }
}

void TcpServ::sendData() {
    bool xOk, yOk;
    float x = xEdit->text().toFloat(&xOk);
    float y = yEdit->text().toFloat(&yOk);

    if (xOk && yOk) {
        QByteArray data = QString("%1 %2 \n").arg(x).arg(y).toUtf8();
        sendDataToSocket(data);
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter valid float values for X and Y.");
    }
}


bool TcpServ::isActive() const
{
    return active;
}

void TcpServ::activateServer()
{
    active = true;

}


void TcpServ::deactivateServer()
{
    active = false;

}
