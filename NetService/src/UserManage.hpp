#pragma once

#include "UserInfo.hpp"
#include "UserStorage.h"

#include <string>
#define NULLPOINT			-1
#define LOGIN_OK			1
#define TEST_FALSE			2

using namespace std;

class CUserManage
{
private:
	UserStorage *m_us;
public:
	CUserManage(UserStorage* _UserStorage)
	{
		m_us = _UserStorage;
	}
	//返回值： LOGIN_OK 登陆成功 TEST_FALSE 验证失败 NULLPOINT 指针无效
	//如果登陆成功则获得用户信息
	int Authenticate(char* szUser, char* pPassword, userinfo* pUserInfo, int nPassLen = 40)
{
	

	if ( !m_us->IfUserExist(szUser) )//账号是否存在 查数据库
	{
		return TEST_FALSE;
	}
	char strPass[40] = {0};	
	m_us->GetPassword(szUser, strPass, 40);

	int i = 0; //密码验证
	do
	{
		if (strPass[i] != pPassword[i])
		{
			return TEST_FALSE;
		}
		++i;
	} while (i < nPassLen);

	if ((int)pUserInfo == 0)
	{
		return NULLPOINT;
	}

	//获得用户信息
	m_us->GetUserInfo(szUser, pUserInfo);

	return LOGIN_OK;
}

};

