/**
PLC ���ݰ�����
*/
#pragma once
#include <iostream>
#include "PLCConnection.h"
#include "PLCModuleDefine.h"

using namespace std;

class CPLCDataPacket
{
public:
	CPLCDataPacket(CPLCConnection *connect);
	~CPLCDataPacket(void);

	/**
	���ܣ��������ݰ�
	�����
		��bool���Ƿ���³ɹ�
	*/
	virtual bool updatePacket()=0;

protected:
	// PLC ���Ӷ���
	CPLCConnection *m_connect;
	// ����ʱ��buff��С
	int m_nByteSize;
};

