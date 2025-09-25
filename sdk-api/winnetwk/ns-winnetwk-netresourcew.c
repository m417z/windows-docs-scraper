typedef struct _NETRESOURCEW {
  DWORD  dwScope;
  DWORD  dwType;
  DWORD  dwDisplayType;
  DWORD  dwUsage;
  LPWSTR lpLocalName;
  LPWSTR lpRemoteName;
  LPWSTR lpComment;
  LPWSTR lpProvider;
} NETRESOURCEW, *LPNETRESOURCEW;