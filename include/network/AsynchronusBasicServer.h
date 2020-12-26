#ifndef _RSTD_NETWORK_ASYNCHRONUSBASICSERVER_H_
#define _RSTD_NETWORK_ASYNCHRONUSBASICSERVER_H_


#include "TcpSocket.h"
#include <vector>
using std::vector;

namespace RStd {
namespace Network {

class AsynchronusBasicServer {

public:
	vector<TcpSocket> clients;
	AsynchronusBasicServer();
	void listenAndServe(int);

};

}
}

#endif