typedef struct RILMSGIS637INSTATUS {
  RILADDRESS              raOrigAddress;
  RILSUBADDRESS           rsaOrigSubaddr;
  RILSYSTEMTIME           stSCReceiveTime;
  DWORD                   dwCauseCode;
  DWORD                   dwReplySeqNumber;
  DWORD                   dwUserResponseCode;
  RILMSGCDMAMSGSTATUSTYPE dwMsgStatusType;
  DWORD                   dwMsgID;
  RILMSGCDMALANGUAGE      dwMsgLang;
  RILMSGCDMAMSGENCODING   dwMsgEncoding;
  DWORD                   cchMsgLength;
  BYTE                    rgbMsg[512];
} RILMSGIS637INSTATUS, *LPRILMSGIS637INSTATUS;