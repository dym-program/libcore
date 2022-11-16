/*
	auth: ugpu
	date: 11/13/2022
	description: common base socket  . the class not use and only suport addtiopn other fun class . all noblock!
*/
#ifndef CSOCKET_H
#define CSOCKET_H
#include "global.h"

#include "define.h"

class CSocket
{
public:
    CSocket();
	//common base use virtual,  not memery leak. 
	virtual ~CSocket();
	
public:
	//init socker
	//type: SOCK_STREAM&SOCK_DGRAM
	int init(const char* ip, int port, int type = SOCK_STREAM, bool is_reuseaddr = true, bool is_nagale = false);

	int bind();
	int listen(int num = DEFAULT_LISTEN_NUM);
	int connect();
	//no block. epoll et mode only suprt noBlock. default use;
	int setNoBlock();

	int setOpt(int opt_id, int opt_val , int& opt_ret);

	int getFD() const;
	char* getIP();
	int getPort();


private:
	char m_ip[128];
    int  m_port;
	int  m_fd;
	int  m_sType;
};

#endif