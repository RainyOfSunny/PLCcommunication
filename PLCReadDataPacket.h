/**
����PLC���ݰ��࣬�������ݰ�ʱ����PLC��ȡ����
*/
#pragma once
#include "PLCDataPacketParam.h"

class CPLCReadDataPacket: public CPLCDataPacketParam
{
public:
	CPLCReadDataPacket(CPLCConnection *connect, int nPacketId, char *name = nullptr);
	~CPLCReadDataPacket(void);

	/*
	���ܣ���������
	�����
		(bool)�Ƿ���³ɹ�
	*/
	bool updatePacket();
};

