typedef struct _MIB_TCP6ROW_OWNER_PID {
  UCHAR ucLocalAddr[16];
  DWORD dwLocalScopeId;
  DWORD dwLocalPort;
  UCHAR ucRemoteAddr[16];
  DWORD dwRemoteScopeId;
  DWORD dwRemotePort;
  DWORD dwState;
  DWORD dwOwningPid;
} MIB_TCP6ROW_OWNER_PID, *PMIB_TCP6ROW_OWNER_PID;