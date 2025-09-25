typedef struct RILMSGINSTATUS {
  DWORD                      dwMsgID;
  RILADDRESS                 raTgtRecipAddress;
  RILSYSTEMTIME              stTgtSCReceiveTime;
  RILSYSTEMTIME              stTgtDischargeTime;
  DWORD                      dwReserved;
  RILMSGINSTATUSTGTDLVSTATUS dwTgtDlvStatus;
  RILMSGPROTOCOLID           dwProtocolID;
  RILMSGDCS                  rmdDataCoding;
  DWORD                      cbHdrLength;
  DWORD                      cchMsgLength;
  BYTE                       rgbHdr[256];
  BYTE                       rgbMsg[512];
} RILMSGINSTATUS, *LPRILMSGINSTATUS;