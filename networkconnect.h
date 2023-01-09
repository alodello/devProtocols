#include <QTcpSocket>
#include <QUdpSocket>


class TcpClient: public QTcpSocket{
    Q_OBJECT

    QString ip;
    quint16 port;
    QMetaObject::Connection conn;

public:
    explicit TcpClient(QObject *parent=nullptr);
    explicit TcpClient(const QString &serverIp, quint16 port, QObject *parent=nullptr);
    ~TcpClient();


private slots:
    void dataProcess();

public slots:
    void connectTo(const QString &serverIp, quint16 port);
    void sendBuff(const QByteArray &buff);

signals:
    void newData(QByteArray);

};

class UdpConnect: public QUdpSocket{
    Q_OBJECT

    QString ip;
    quint16 port;
    QMetaObject::Connection conn;

public:
    explicit UdpConnect(QObject *parent=nullptr);
    explicit UdpConnect(const QString &serverIp, quint16 _port, QObject *parent=nullptr);
    ~UdpConnect();

public slots:
    void connectTo(const QString &serverIp, quint16 _port);

};
