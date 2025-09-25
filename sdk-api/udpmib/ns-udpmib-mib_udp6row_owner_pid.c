typedef struct _MIB_UDP6ROW_OWNER_PID {
  UCHAR ucLocalAddr[16];
  DWORD dwLocalScopeId;
  DWORD dwLocalPort;
  DWORD dwOwningPid;
} MIB_UDP6ROW_OWNER_PID, *PMIB_UDP6ROW_OWNER_PID;