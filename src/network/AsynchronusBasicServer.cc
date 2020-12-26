#include <network/AsynchronusBasicServer.h>
#include <network/TcpListener.h>

namespace RStd {
namespace Network {

AsynchronusBasicServer::AsynchronusBasicServer() {}

void AsynchronusBasicServer::listenAndServe(int port) {

	TcpListener listener;

	listener.host(8080);

	while (true) {

		// TODO: process requests.

		TcpSocket client;
		if (listener.try_accept(client)) {
			clients.push_back(client);
		}

		for (auto &c : clients) {

			// TODO: receive

			// TODO: send

		}

	}

}

} // namespace Network
} // namespace RStd