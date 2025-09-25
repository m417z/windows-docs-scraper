typedef struct RILMESSAGE {
  DWORD          cbSize;
  DWORD          dwParams;
  RILADDRESS     raSvcCtrAddress;
  RILMESSAGETYPE dwType;
  DWORD          dwFlags;
  union {
    RILMSGINDELIVER     unMsgInDeliver;
    RILMSGINSTATUS      unMsgInStatus;
    RILMSGOUTSUBMIT     unMsgOutSubmit;
    RILMSGBCGENERAL     unMsgBcGeneral;
    RILMSGIS637INSTATUS unMsgIS637InStatus;
    RILMSGCDMAINDELIVER unMsgCDMAInDeliver;
    RILMSGCDMAOUTSUBMIT unMsgCDMAOutSubmit;
  } RILMSGUNION;
  RILMSGUNION    msgUnion;
} RILMESSAGE, *LPRILMESSAGE;