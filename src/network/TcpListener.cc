#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>

#include <network/TcpListener.h>

namespace RStd {
namespace Network {


TcpListener::TcpListener() {

}

bool TcpListener::host(int port) {

	struct sockaddr_in serv_addr;

	serverfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	bzero((char*) &serv_addr, sizeof(serv_addr));

	if (bind(
		serverfd,
		(struct sockaddr*) &serv_addr,
		sizeof(serv_addr)
	) < 0) {
		return false;
	}

	listen(serverfd, 5);

	return true;

}

bool TcpListener::try_accept(TcpSocket &client) {

	struct sockaddr_in client_addr;

	int clientfd = accept4(
		serverfd,
		(struct sockaddr*) &client_addr,
		(socklen_t*)sizeof(client_addr),
		SOCK_NONBLOCK
	);

	if (clientfd < 0) {
		return false;
	}

	client.socketfd = clientfd;

	return true;

}

}
}