typedef struct _MIB_UDP6ROW_OWNER_MODULE {
  UCHAR         ucLocalAddr[16];
  DWORD         dwLocalScopeId;
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
} MIB_UDP6ROW_OWNER_MODULE, *PMIB_UDP6ROW_OWNER_MODULE;