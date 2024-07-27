/**
PLC ���ݰ��������á�������չ
*/
#pragma once
#include "PLCDataPacket.h"

class CPLCDataPacketParam: public CPLCDataPacket
{
public:
	/*
	���룺
		param1����CPLCConnection *��PLC���Ӷ���
		param2����nPacketId int�����ݰ�����
		param3����name char*������������{Ĭ�ϣ�nullptr}
	*/
	CPLCDataPacketParam(CPLCConnection *connect, int nPacketId, char *name = nullptr);
	~CPLCDataPacketParam(void);

	/**
	���ܣ��������ݰ�����
	���룺
		param1:(nPackageID int) ���ݰ�ID
		param2:(sPackage PLCPackage) ���ݰ�
	�����
		(bool) �Ƿ����óɹ�
	*/
	bool setPackage(int nPackageID, const PLCPackage &sPackage) const; 

	/**
	���ܣ���ȡ���ݰ�����
	�����
		��PLCPackage�����ݰ�
	*/
	PLCPackage getPackage() const;

	/**
	���ܣ��������ݰ���С
	���룺
		param1:(int)��С ��Χ��0<= x <=PACKET_MAX_SIZE
	*/
	void setPacketSize(int nSize);

	/**
	���ܣ����õ�������
	���룺
		param1:(int)����id
		param2:(int)����ֵ
	*/
	bool setValue(int id, int nValue) const;

	/*
	���ܣ���ȡ��������
	���룺
		param1:(int)����id
	�����
		(int)����ֵ
	*/
	int getValue(int id) const;
	
	/*
	���ܣ����õ������ݵ�bitֵ
	���룺
		param1:(int)����id
		param2:(int)λid
		param3:(bool)λֵ
	*/
	bool setBit(int id, int bitID, bool bValue) const;

	/*
	���ܣ���ȡ����bit����
	���룺
		param1:(int)����id
		param2:(int)λid
	�����
		(int)λֵ(id����ȷ�򷵻�-1)
	*/
	int getBit(int id, int bitId) const;

	/**
	 * ���ܣ����˶���order�ƶ������ݰ�
	 * ���룺
			param1: id
			param2: nValue
	 * �����
			bool
	 */ 
	bool setOrderValue(int id, int nValue = -1000) const;

protected:
	// ����
	PLCPackage *m_sPackage;
	// ����
	int m_nPacketID;
	// ʵ�����ݴ�С
	int m_nSize;
	// ����ʱ��buff��
	char m_buff[sizeof(PLCPackage)];
	// �Ƿ�򿪹���������������ʱ��delete
	bool m_isOpenShare;
};

