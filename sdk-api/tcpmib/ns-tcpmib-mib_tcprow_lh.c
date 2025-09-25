typedef struct _MIB_TCPROW_LH {
  union {
    DWORD         dwState;
    MIB_TCP_STATE State;
  };
  DWORD dwLocalAddr;
  DWORD dwLocalPort;
  DWORD dwRemoteAddr;
  DWORD dwRemotePort;
} MIB_TCPROW_LH, *PMIB_TCPROW_LH;