#ifndef COMMONDATA_H
#define COMMONDATA_H

namespace common {
//--------------------定义包结构-------------------
#define PACKET_HEAD_LEN sizeof(short) * 2
#define DATA_MAX_LEN 255

enum packetType{
    cmd,
    keyHook
};

#pragma pack(push, 2)
struct UPacket{
    unsigned short type;
    unsigned short length;
    char data[DATA_MAX_LEN];
};
#pragma pack(pop)
//-----------------------------------------------
const char HOOKDLLPATH[] = "E:\\project\\programming\\C++\\QT\\MyRemoteControl\\bin\\MyKeyHook.dll";

}

#endif // COMMONDATA_H
