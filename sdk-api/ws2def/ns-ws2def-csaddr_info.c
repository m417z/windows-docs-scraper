typedef struct _CSADDR_INFO {
  SOCKET_ADDRESS LocalAddr;
  SOCKET_ADDRESS RemoteAddr;
  INT            iSocketType;
  INT            iProtocol;
} CSADDR_INFO, *PCSADDR_INFO, *LPCSADDR_INFO;