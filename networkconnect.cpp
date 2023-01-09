#include "networkconnect.h"



TcpClient::TcpClient(QObject *parent)
{
    conn = QObject::connect(this, &QTcpSocket::readyRead, this, &TcpClient::dataProcess);
}

TcpClient::TcpClient(const QString &serverIp, quint16 _port, QObject *parent):
    ip(serverIp), port(_port)
{
    conn = QObject::connect(this, &QTcpSocket::readyRead, this, &TcpClient::dataProcess);
    this->connectToHost(ip, port);
}

TcpClient::~TcpClient(){
    this->close();
    disconnect(conn);
}

void TcpClient::dataProcess()
{
    emit newData(this->readAll());
}

void TcpClient::connectTo(const QString &serverIp, quint16 _port)
{
    ip = serverIp;
    port = _port;
    this->connectToHost(ip, port);
}

void TcpClient::sendBuff(const QByteArray &buff)
{
    if(this->state() != SocketState::UnconnectedState){
        this->write(buff);
    }
}


UdpConnect::UdpConnect(QObject *parent)
{

}

UdpConnect::UdpConnect(const QString &serverIp, quint16 port, QObject *parent)
{

}

UdpConnect::~UdpConnect()
{

}

void UdpConnect::connectTo(const QString &serverIp, quint16 _port)
{
//    if( bind(QHostAddress(ip), port)){ return true; }
//    else{ return false; }
}
