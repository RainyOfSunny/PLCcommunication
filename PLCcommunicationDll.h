// PLCcommunicationDll.h : PLCcommunicationDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPLCcommunicationDllApp
// �йش���ʵ�ֵ���Ϣ������� PLCcommunicationDll.cpp
//

class CPLCcommunicationDllApp : public CWinApp
{
public:
	CPLCcommunicationDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
