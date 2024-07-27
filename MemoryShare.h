/**
�����ڴ��������࣬������ɾ��������ӳ��
ע�⣺
	1.�رչ����������رյ�ǰӳ�䣬ʵ�ʹ��������ɴ���
	2.ͨ��openShare()��ȡ��ָ����󣬲���delete
	3.����ʱҪ�Ƚ���ȡָ�������Ϊnullptr,ͨ��closeShare()�ر�ӳ��
*/
#pragma once

#include <map>
using namespace std;

class CMemoryShare
{
public:
	CMemoryShare(void);
	~CMemoryShare(void);

	/*
	���ܣ��򿪹�����
	���룺
		param1(char *):����������
		param2(int):��������С
	�����
		(LPVOID):������������ָ��
	*/
	static LPVOID openShare(const char *name, int nSize);
	static void closeShare(const char *name);

private:
	static void closeAllShare();
	
	// ����������
	static map<CString, HANDLE> m_shareHMap;
	static map<CString, LPVOID> m_shareMap;
};

