typedef struct _MIB_TCP6ROW_OWNER_MODULE {
  UCHAR         ucLocalAddr[16];
  DWORD         dwLocalScopeId;
  DWORD         dwLocalPort;
  UCHAR         ucRemoteAddr[16];
  DWORD         dwRemoteScopeId;
  DWORD         dwRemotePort;
  DWORD         dwState;
  DWORD         dwOwningPid;
  LARGE_INTEGER liCreateTimestamp;
  ULONGLONG     OwningModuleInfo[TCPIP_OWNING_MODULE_SIZE];
} MIB_TCP6ROW_OWNER_MODULE, *PMIB_TCP6ROW_OWNER_MODULE;