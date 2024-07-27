#include "StdAfx.h"
#include "UDPConnection.h"


CUDPConnection::CUDPConnection(void)
{
	m_isInitialized = false;
	m_isConnect = false;
}


CUDPConnection::~CUDPConnection(void)
{
	closeConnectPLC();
}

void CUDPConnection::prepareToConnect(PLCProtocolType plcType, PLCConnectInfo info)
{
	// ����Э���׼�ţ�IPV4��
	m_address.sin_family = AF_INET;
	// ���÷���Ŀ�Ķ˿ں�
	m_address.sin_port = htons(info.port);
	// ���÷���Ŀ��IP��ַ
	m_address.sin_addr.s_addr = inet_addr(info.ip.GetString());
	m_addressSize = sizeof(m_address);
	
	if (m_isConnect)
	{
		closeConnectPLC();
	}

	// ��ʼ������ͨ�Ź���
	WSADATA wsaData;
	if (0 != WSAStartup(MAKEWORD(2,2), &wsaData))
	{
		m_errorCode = WSAGetLastError();
		return;
	}

	// ��UDP����ӿ�
	m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (m_socket == INVALID_SOCKET)
	{
		m_errorCode = WSAGetLastError();
		return;
	}

	// ���ӿ�����Ϊ��������ʽ��������򽫳�ʱ��ȴ���������
	int iMode = 1;
	if (SOCKET_ERROR == ioctlsocket(m_socket, FIONBIO, reinterpret_cast<u_long*>(&iMode)))
	{
		m_errorCode = WSAGetLastError();
		return;
	}

	m_isInitialized = true;
}

bool CUDPConnection::startConnectPLC()
{
	if (!m_isInitialized)
	{
		m_errorCode = 1;
		return false;
	}

	if (m_isConnect)
	{
		return true;
	}

	// �󶨽��յ��ӿ�
	if (SOCKET_ERROR == bind(m_socket, reinterpret_cast<SOCKADDR*>(&m_address), m_addressSize))
	{
		m_errorCode = WSAGetLastError();
	}
	else
	{
		m_isConnect = true;
	}

	return m_isConnect;
}

void CUDPConnection::closeConnectPLC()
{
	closesocket(m_socket);
	m_isConnect = false;
}

CString CUDPConnection::plcError()
{
	CString err;
	switch(m_errorCode)
	{
	case 0:
		err = _T("");
		break;
	case 1:
		err = _T("δ���ò���/δ��ʼ��socket");
		break;
	case 2:
		err = _T("δ�󶨶˿�");
		break;
	case 10004:
		err = _T("����״̬�����");
		break;
	case 10022:
		err = _T("δ��");
		break;
	case 10035:
		err = _T("������SOCKET�Ĳ�����������ִ��");
		break;
	case 10038:
		err = _T("socket������");
		break;
	case 10040:
		err = _T("����������");
		break;
	case 10048:
		err = _T("�˿���ռ��");
		break;
	case 10049:
		err = _T("���ܷ�������ĵ�ַ");
		break;
	case 10093:
		err = _T("����ͨ�Ź���WSAStartupδ��ʼ��");
		break;
	default:
		err.Format(_T("δ֪����:%d"), m_errorCode);
		break;
	}

	return err;
}

bool CUDPConnection::sendMessage(char *buff, int nSize)
{
	bool isSuccess = false;

	if (!m_isInitialized)
	{
		m_errorCode = 1;
		return isSuccess;
	}

	if (!m_isConnect)
	{
		m_errorCode = 2;
		return isSuccess;
	}

	/*
	int PASCAL FAR sendto( SOCKET s, const char FAR* buf, int len, int flags, const struct sockaddr FAR* to,int tolen);
		s��һ����ʶ�׽ӿڵ������֡�
		buf���������������ݵĻ�������
		len��buf�����������ݵĳ��ȡ�
		flags�����÷�ʽ��־λ��
		to������ѡ��ָ�룬ָ��Ŀ���׽ӿڵĵ�ַ��
		tolen��to��ָ��ַ�ĳ��ȡ�
	*/
	const int nSendLen = sendto(m_socket, buff, nSize, 0, reinterpret_cast<SOCKADDR*>(&m_address), m_addressSize);
	if (SOCKET_ERROR == nSendLen)
	{
		m_errorCode = WSAGetLastError();
		isSuccess = false;
	}
	else
	{
		isSuccess = true;
	}

	return isSuccess;
}

bool CUDPConnection::receiveMessage(char *buff, int nSize)
{
	bool isSuccess = false;
	if (!m_isInitialized)
	{
		m_errorCode = 1;
		return isSuccess;
	}

	if (!m_isConnect)
	{
		m_errorCode = 2;
		return isSuccess;
	}

	/*
	int recvfrom(int s, void *buf, int len, unsigned int flags, struct sockaddr *from,int *fromlen);
	��	s��socket��������
		buf��UDP���ݱ������������������յ����ݣ��� 
		len�����������ȡ� 
		flags�����ò�����ʽ��һ������Ϊ0���� 
		from��ָ�������ݵĿͻ��˵�ַ��Ϣ�Ľṹ�壨sockaddr_in������ת������
		fromlen��ָ�룬ָ��from�ṹ�峤��ֵ��
	*/
	const int nReceiveLen = recvfrom(m_socket, buff, nSize, 0, reinterpret_cast<SOCKADDR*>(&m_address), &m_addressSize);
	if (SOCKET_ERROR == nReceiveLen)
	{
		m_errorCode = WSAGetLastError();
		isSuccess = false;
	}
	else
	{
		isSuccess = true;
	}

	return isSuccess;
}