typedef struct _MIB_TCPROW_W2K {
  DWORD dwState;
  DWORD dwLocalAddr;
  DWORD dwLocalPort;
  DWORD dwRemoteAddr;
  DWORD dwRemotePort;
} MIB_TCPROW_W2K, *PMIB_TCPROW_W2K;