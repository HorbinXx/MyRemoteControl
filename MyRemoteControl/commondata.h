#ifndef COMMONDATA_H
#define COMMONDATA_H

namespace common {
//--------------------定义包结构-------------------
#define PACKET_HEAD_LEN (sizeof(short) * 2 + sizeof(int) * 2)
#define DATA_MAX_LEN 255

enum packetType{
    cmd,
    keyHook,
    capture,
    other
};

#pragma pack(push, 2)
struct UPacket{
    unsigned short type;
    unsigned short length;
    unsigned int tNum;
    unsigned int nNum;
    char data[DATA_MAX_LEN];
};
#pragma pack(pop)
//-----------------------------------------------
const char HOOKDLLPATH[] = "..\\MyRemoteControl\\bin\\MyKeyHook.dll";

}

#endif // COMMONDATA_H
