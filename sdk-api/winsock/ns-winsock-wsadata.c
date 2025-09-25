typedef struct WSAData {
  WORD           wVersion;
  WORD           wHighVersion;
#if ...
  unsigned short iMaxSockets;
#if ...
  unsigned short iMaxUdpDg;
#if ...
  char           *lpVendorInfo;
#if ...
  char           szDescription[WSADESCRIPTION_LEN + 1];
#if ...
  char           szSystemStatus[WSASYS_STATUS_LEN + 1];
#else
  char           szDescription[WSADESCRIPTION_LEN + 1];
#endif
#else
  char           szSystemStatus[WSASYS_STATUS_LEN + 1];
#endif
#else
  unsigned short iMaxSockets;
#endif
#else
  unsigned short iMaxUdpDg;
#endif
#else
  char           *lpVendorInfo;
#endif
} WSADATA;