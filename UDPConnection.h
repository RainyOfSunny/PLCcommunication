#pragma once
#include "PLCConnection.h"

/**
UDP �����࣬socket ʹ��UDPЭ�飬���͡���������
*/
class CUDPConnection: public CPLCConnection
{
public:
	CUDPConnection(void);
	~CUDPConnection(void);

	void prepareToConnect(PLCProtocolType plcType, PLCConnectInfo info);
	bool startConnectPLC();
	void closeConnectPLC();
	CString plcError();
	bool sendMessage(char *buff, int nSize);
	bool receiveMessage(char *buff, int nSize);

private:
	// socket ����
	SOCKET m_socket;
	// ����Ŀ���ַ
	sockaddr_in m_address;
	// ��ַ��С
	int m_addressSize;
	// �Ƿ��Ѿ���ʼ��
	bool m_isInitialized;
};

