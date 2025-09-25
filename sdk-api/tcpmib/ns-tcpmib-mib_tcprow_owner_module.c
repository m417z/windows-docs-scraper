typedef struct _MIB_TCPROW_OWNER_MODULE {
  DWORD         dwState;
  DWORD         dwLocalAddr;
  DWORD         dwLocalPort;
  DWORD         dwRemoteAddr;
  DWORD         dwRemotePort;
  DWORD         dwOwningPid;
  LARGE_INTEGER liCreateTimestamp;
  ULONGLONG     OwningModuleInfo[TCPIP_OWNING_MODULE_SIZE];
} MIB_TCPROW_OWNER_MODULE, *PMIB_TCPROW_OWNER_MODULE;