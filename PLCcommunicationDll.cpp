// PLCcommunicationDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "PLCcommunicationDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CPLCcommunicationDllApp

BEGIN_MESSAGE_MAP(CPLCcommunicationDllApp, CWinApp)
END_MESSAGE_MAP()


// CPLCcommunicationDllApp ����

CPLCcommunicationDllApp::CPLCcommunicationDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CPLCcommunicationDllApp ����

CPLCcommunicationDllApp theApp;


// CPLCcommunicationDllApp ��ʼ��

BOOL CPLCcommunicationDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
