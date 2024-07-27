/**
�������ݰ��࣬�ڸ������ݰ�ʱ�����ݰ����͵�PLC
*/
#pragma once
#include "PLCDataPacketParam.h"

class CPLCWriteDataPacket: public CPLCDataPacketParam
{
public:
	CPLCWriteDataPacket(CPLCConnection *connect, int nPacketId, char *name = nullptr);
	~CPLCWriteDataPacket(void);

	/*
	���ܣ���������
	�����
		(bool)�Ƿ���³ɹ�
	*/
	bool updatePacket();

protected:
	// ���ʹ���
	int m_nSendTimes;
	// ��һ�θ���ʱ��buff�� -- ����package���ڴ棬���µ�package���жԱ�
	char m_lastBuff[sizeof(PLCPackage)];
};

