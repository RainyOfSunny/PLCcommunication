#include "StdAfx.h"
#include "PLCWriteDataPacket.h"


CPLCWriteDataPacket::CPLCWriteDataPacket(CPLCConnection *connect, int nPacketId, char *name /* = nullptr */):CPLCDataPacketParam(connect, nPacketId, name)
{
	m_sPackage->data[0] = nPacketId;
	m_nSendTimes = 0;

	memcpy(m_lastBuff, &m_sPackage, m_nByteSize);
}

CPLCWriteDataPacket::~CPLCWriteDataPacket(void)
{
}

bool CPLCWriteDataPacket::updatePacket()
{
	bool isSuccess = false;

	if (m_connect)
	{
		m_sPackage->data[0] = m_nPacketID;
		memcpy(m_buff, &m_sPackage->data, m_nByteSize);

		// ����һ�ε�buff�Աȣ���Ϣ�����仯ʱ�������½������ݸ��Ǿ�����
		bool isSame = (memcmp(m_lastBuff, m_buff, m_nByteSize) == 0);
		if (!isSame)
		{
			m_nSendTimes = 0;
			memcpy(m_lastBuff, &m_buff, m_nByteSize);
		}
		
		// ����UDP�������ظ�����10��
		if (m_nSendTimes < 10)
		{
			if (m_connect->sendMessage(m_buff, m_nByteSize))
			{
				isSuccess = true;
				m_nSendTimes ++;
			}
			else
			{
				cout << "\n" << "WriteDataPacket update Error:" << m_connect->plcError() << "\n";
			}
		}
	}

	return isSuccess;
}