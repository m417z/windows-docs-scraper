typedef struct _PROTOCOL_INFOA {
  DWORD dwServiceFlags;
  INT   iAddressFamily;
  INT   iMaxSockAddr;
  INT   iMinSockAddr;
  INT   iSocketType;
  INT   iProtocol;
  DWORD dwMessageSize;
  LPSTR lpProtocol;
} PROTOCOL_INFOA, *PPROTOCOL_INFOA, *LPPROTOCOL_INFOA;