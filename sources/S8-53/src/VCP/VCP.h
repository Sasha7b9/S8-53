#pragma once


class VCP
{
public:
    static void Init();
    static void SendDataSynch(const uint8 *data, int size);
    static void SendStringSynch(char *data);                   ///< ��������� ������ ��� ������������ ����.
    static void SendFormatStringAsynch(char *format, ...);     ///< ��� ������ ��������� � ������������ ��������� \r\n.
    static void SendFormatStringSynch(char *format, ...);      ///< ��� ������ ��������� � ������������ ��������� \r\n.
    static void SendByte(uint8 data);
    static void Flush();
};
