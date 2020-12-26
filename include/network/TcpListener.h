#ifndef _RSTD_NETWORK_TCPLISTENER_H_
#define _RSTD_NETWORK_TCPLISTENER_H_

#include "TcpSocket.h"

namespace RStd {
namespace Network {

	class TcpListener {
	public:
		int port;
		int serverfd;
		TcpListener();
		bool host(int);
		bool try_accept(TcpSocket&);
	};

} // namespace Network
} // namespace RStd

#endif