#ifndef ASIOTCPCONNECTION_H_
#define ASIOTCPCONNECTION_H_
#include "asio.hpp"
#include "SocketServer.hpp"

class AsioTcpConnetion: public Connection
{
public:
    AsioTcpConnetion(asio::io_service& io_service):socket_(io_service){}
    asio::ip::tcp::socket& socket(){return socket_;} 
    virtual bool start(){return true;}
private:
    asio::ip::tcp::socket socket_;
};

#endif /* ASIOTCPCONNECTION_H_ */