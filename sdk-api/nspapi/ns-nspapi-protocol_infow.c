typedef struct _PROTOCOL_INFOW {
  DWORD  dwServiceFlags;
  INT    iAddressFamily;
  INT    iMaxSockAddr;
  INT    iMinSockAddr;
  INT    iSocketType;
  INT    iProtocol;
  DWORD  dwMessageSize;
  LPWSTR lpProtocol;
} PROTOCOL_INFOW, *PPROTOCOL_INFOW, *LPPROTOCOL_INFOW;