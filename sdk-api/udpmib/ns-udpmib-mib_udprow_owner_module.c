typedef struct _MIB_UDPROW_OWNER_MODULE {
  DWORD         dwLocalAddr;
  DWORD         dwLocalPort;
  DWORD         dwOwningPid;
  LARGE_INTEGER liCreateTimestamp;
  union {
    struct {
      int SpecificPortBind : 1;
    };
    int dwFlags;
  };
  ULONGLONG     OwningModuleInfo[TCPIP_OWNING_MODULE_SIZE];
} MIB_UDPROW_OWNER_MODULE, *PMIB_UDPROW_OWNER_MODULE;