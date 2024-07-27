/*----------------------------------------------------------------
 * ��Ȩ���� (c) �����е�Ƶ���װ�����޹�˾ ��������Ȩ����
 * ��˾���ƣ������е�Ƶ���װ�����޹�˾
 * 
 * �����ߣ���Ƚ
 * ����ʱ�䣺2024-7-27
 * �汾��V1.0.0
 * �������������ݰ��࣬�������ݰ�ʱ�����ݷ��͵�PLC
 *
 * ----------------------------------------------------------------
 * �޸��ˣ�
 * ʱ�䣺
 * �޸�˵����
 *
 * �汾��V1.0.0
 *----------------------------------------------------------------*/
#pragma once
#include "PLCDataPacket.h"

class CPLCOrderDataPacket:public CPLCDataPacket 
{
public:
	CPLCOrderDataPacket(CPLCConnection *connect);
	~CPLCOrderDataPacket(void);

	/**
	 * ���ܣ������������ݰ�
	 * ���룺
			param1: (OrderPackage) �������ݰ� 
	 */ 
	void setPackage(const OrderPackage &sOrderPackage);

	/**
	 * ���ܣ���ȡ�������ݰ�
	 * ���룺
			param1: ��int�����ݰ�ID
	 * �����
			��OrderPackage���������ݰ�
	 */ 
	OrderPackage getPackage() const;

	/**
	 * ���ܣ���������
	 * ���룺
			param1: ��int��������
			param2: ��int��ֵ
	 * �����
			��bool���Ƿ��ͳɹ�
	 */ 
	bool setOrderValue(int id, int nValue = -1000);

	/**
	 * ���ܣ���ȡ��������
	 * ���룺
			param1: ��int�������� 
	 * �����
			��int������ֵ
	 */ 
	int getOrderValue(int nOrderNum);

	/**
	 * ���ܣ���������
	 * �����
			��bool�������Ƿ���³ɹ�
	 */ 
	bool updatePacket();

private:
	// �������ݰ�
	OrderPackage m_sPackage;
	// ����ʱ��buff��
	char m_buff[sizeof(OrderPackage)];
};

