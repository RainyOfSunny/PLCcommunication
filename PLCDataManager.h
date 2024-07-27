/**
����ģ�����
*/
#pragma once
#include "PLCConnection.h"

class CPLCDataManager
{
public:
	CPLCDataManager(void);
	~CPLCDataManager(void);

	/**
	���ܣ��Ƿ��ʼ���ɹ�
	�����
		��bool���Ƿ��ʼ���ɹ�
	*/
	bool isInitialized() const;

	/**
	���ܣ��Ƿ�������PLC(��������)
	�����
		��bool���Ƿ�������PLC
	*/
	bool isConnect();

	/**
	���ܣ��Ƿ�����״�����ͨ��
	�����
		��bool���Ƿ�����״�ͨ��
	*/
	bool isFinishFirstCommunction() const;

	/**
	���ܣ���������
	�����
		��bool���Ƿ���³ɹ�
	*/
	virtual bool update()=0;

	/**
	���ܣ�����PLC
	�����
		��bool���Ƿ����ӳɹ�
	*/
	virtual bool connectPLC()=0;

protected:
	/**
	���ܣ���ʼ��PLC���Ӷ���
	�����
		��bool���Ƿ��ʼ���ɹ�
	*/
	virtual bool initConnection()=0;

	/**
	���ܣ��ͷ��������Ӷ���
	*/
	virtual void releaseConnect(){};

	/**
	���ܣ��ͷ���Դ
	*/
	virtual void release();

	// �Ƿ��ʼ���ɹ�
	bool m_bIsInitialized;
	// �Ƿ�������PLC
	bool m_bIsConnectPLC;
	// �Ƿ�����״�ͨ��
	bool m_bIsFinishFirstCommunication;
};

