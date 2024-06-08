#ifndef TCPSERV_HH
#define TCPSERV_HH

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
// https://www.youtube.com/watch?v=YIsALDZEQ7o&t=912s


/**
 * @file tcpserv.hh
 * @brief Definition of the TcpServclass
 *
 * This file contains the class definition.
 */


/**
 * @brief Responsible for creating a server robot connects to
 */
class TcpServ : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for TcpServ class
     * @param parent Pointer to parent widget, default is nullptr
     */
    explicit TcpServ(QWidget *parent = nullptr);

signals:
    /**
     * @brief valueSharpChanged informs about new data arrival
     * @param value New distance reading - int
     */
    void valueSharpChanged(int value);
    /**
     * @brief valueTof1Changed informs about new data arrival for sensor ToF1
     * @param value New distance reading - int
     */
    void valueTof1Changed(int value);
    /**
     * @brief valueTof2Changed informs about new data arrival for sensor ToF2
     * @param value New distance reading - int
     */
    void valueTof2Changed(int value);
    /**
     * @brief valueXChanged informs about new X coordinate data
     * @param value New X coordinate - float
     */
    void valueXChanged(float value);
    /**
     * @brief valueYChanged informs about new Y coordinate data
     * @param value New Y coordinate - float
     */
    void valueYChanged(float value);
    /**
     * @brief valueAngleChanged informs about new angle data
     * @param value New angle - float
     */
    void valueAngleChanged(float value);

private slots:
    /**
     * @brief Slot to handle new incoming connections
     */
    void newConnection();
    /**
     * @brief Slot to read data from the socket
     */
    void Read_Data_From_Socket();
    /**
     * @brief Slot to send data through the socket
     */
    void sendData();
    /**
     * @brief Slot to add a new client connection
     * @param s Pointer to the new QTcpSocket
     */
    void Add_New_Client_Connection(QTcpSocket *s);
    /**
     * @brief Slot to send data to a specific socket
     * @param data Data to send
     */
    void sendDataToSocket(const QByteArray &data);

private:
    QTcpServer *server;                        ///< TCP server instance
    QLineEdit *xEdit;                          ///< Line edit for X coordinate input
    QLineEdit *yEdit;                          ///< Line edit for Y coordinate input
    QPushButton *sendButton;                   ///< Button to send data
    QVector<QTcpSocket*> Client_Connection_List; ///< List of client connections
};

#endif // TCPSERV_HH
