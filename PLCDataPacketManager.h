/**
���ݰ�ģ�����
*/
#pragma once
#include <map>
#include "PLCDataManager.h"
#include "PLCReadDataPacket.h"
#include "PLCWriteDataPacket.h"
#include "PLCOrderDataPacket.h"

using namespace std;

class CPLCDataPacketManager: public CPLCDataManager
{
public:
	CPLCDataPacketManager(void);
	~CPLCDataPacketManager(void);

	/**
	 * ���ܣ���ȡ�������ݰ�����
	 * �����
			��OrderPacket *���������ݰ�����
	 */ 
	CPLCOrderDataPacket* getOrderPacket() const;

	/**
	���ܣ���ȡ�������ݰ�����
	���룺
		param1����int nPacketId�����ݰ�ID
	�����
		��CPLCWriteDataPacket*�����ݰ�����
	*/
	CPLCWriteDataPacket* getWritePacket(int nPacketId);

	/**
	���ܣ���ȡ�������ݰ�����
	�����
		(CPLCReadDataPacket*) ���ݰ�����	
	*/
	CPLCReadDataPacket* getReadPacket() const;

	/*
	���ܣ���ʼ�����ݰ�����
	�����
		(bool)���Ƿ��ʼ���ɹ�
	*/
	virtual bool initPacket()=0;
	
	/*
	���ܣ������������ݰ�����
	���룺
		param1:(int)���ݰ�ID
	�����
		��bool�����Ƿ񴴽��ɹ�
	*/
	virtual bool createWritePacket(int nPacketId)=0;

	/**
	���ܣ��ͷ����з������ݰ�����
	*/
	void releaseWritePacket();
	
	/**
	���ܣ��ͷ��������ݰ�����
	*/
	void releasePacket();
	void releaseConnect();
	void release();

protected:
	// �����������Ӷ���UDP�����뷢��IP��ͬ��
	CPLCConnection *m_pSendConnection;
	// �������ݶ���
	CPLCConnection *m_pReceiveConnection;

	// �������ݰ�����
	CPLCOrderDataPacket *m_pOrderPacket;
	// �������ݰ�����
	CPLCReadDataPacket *m_pReadDataPacket;
	// �������ݰ���������
	map<int, CPLCWriteDataPacket*> m_writeDataPacketMap;
};

