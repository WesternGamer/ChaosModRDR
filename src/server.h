#pragma once

#include "pch.h"

class WebSocketServer
{
public:
	typedef websocketpp::server <websocketpp::config::asio> _server;

	WebSocketServer();

	void Init(int32_t port = 9149);
	void Run();

	void OnMessage(websocketpp::connection_hdl hdl, _server::message_ptr msg);
	void OnConnect(websocketpp::connection_hdl hdl);
	void OnDisconnect(websocketpp::connection_hdl hdl);

	void SendMessageToClient(std::string msg);
	void SendMessageToClient(const char* msg);

	void Stop();

private:
	_server instance;
	websocketpp::connection_hdl* client = nullptr;

	void OnIntervalUpdated(rapidjson::Document &document);
	void OnNewEffectActivated(rapidjson::Document &document);

	std::atomic<bool> bStarted = std::atomic<bool>(false);
};