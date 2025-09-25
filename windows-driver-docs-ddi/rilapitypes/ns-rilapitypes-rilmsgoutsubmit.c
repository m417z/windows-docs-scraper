typedef struct RILMSGOUTSUBMIT {
  RILADDRESS              raDestAddress;
  RILMSGPROTOCOLID        dwProtocolID;
  RILMSGDCS               rmdDataCoding;
  RILMSGOUTSUBMITVPFORMAT dwVPFormat;
  RILSYSTEMTIME           stVP;
  DWORD                   dwMsgID;
  DWORD                   cbHdrLength;
  DWORD                   cchMsgLength;
  BYTE                    rgbHdr[256];
  BYTE                    rgbMsg[512];
} RILMSGOUTSUBMIT, *LPRILMSGOUTSUBMIT;