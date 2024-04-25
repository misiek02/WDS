// #include "socket.hh"


// Socket::Socket(QObject *parent)
//     : QObject{parent}
// {}

// void Socket::Connect()
// {
//     socket = new QTcpSocket(this);
//     socket->connectToHost("127.0.0.1", 80);

//     if(socket->waitForConnected(3000))
//     {
//         qDebug() << "Connected!";

//         // send
//         // socket->write("hello server\r\n\r\n\r\n\r\n");
//         // socket->waitForBytesWritten(1000);
//         // socket->waitForReadyRead(3000);
//         // qDebug() << "Reading: " << socket->bytesAvailable();

//         qDebug() << socket->readAll();

//         socket->close();
//     }
//     else
//     {
//         qDebug() << "Not connected!";
//     }


// }
