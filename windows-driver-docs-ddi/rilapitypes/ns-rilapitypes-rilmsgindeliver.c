typedef struct RILMSGINDELIVER {
  RILADDRESS       raOrigAddress;
  RILMSGPROTOCOLID dwProtocolID;
  RILMSGDCS        rmdDataCoding;
  RILSYSTEMTIME    stSCReceiveTime;
  DWORD            dwMsgID;
  DWORD            cbHdrLength;
  DWORD            cchMsgLength;
  BYTE             rgbHdr[256];
  BYTE             rgbMsg[512];
} RILMSGINDELIVER, *LPRILMSGINDELIVER;