typedef struct _NS_CONTEXT_ATTRIBUTES {
  union {
    struct {
      DWORD dwVersion;
      DWORD dwReserved;
    };
    ULONGLONG _ullAlign;
  };
  LPWSTR                 pwszContext;
  GUID                   guidHelper;
  DWORD                  dwFlags;
  ULONG                  ulPriority;
  ULONG                  ulNumTopCmds;
  _CMD_ENTRY( )            *pTopCmds[];
  struct                 _CMD_ENTRY;
  ULONG                  ulNumGroups;
  _CMD_GROUP_ENTRY( )      *pCmdGroups[];
  struct                 _CMD_GROUP_ENTRY;
  PNS_CONTEXT_COMMIT_FN  pfnCommitFn;
  PNS_CONTEXT_DUMP_FN    pfnDumpFn;
  PNS_CONTEXT_CONNECT_FN pfnConnectFn;
  PVOID                  pReserved;
  PNS_OSVERSIONCHECK     pfnOsVersionCheck;
} NS_CONTEXT_ATTRIBUTES, *PNS_CONTEXT_ATTRIBUTES;