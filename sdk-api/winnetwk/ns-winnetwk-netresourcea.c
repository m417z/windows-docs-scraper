typedef struct _NETRESOURCEA {
  DWORD dwScope;
  DWORD dwType;
  DWORD dwDisplayType;
  DWORD dwUsage;
  LPSTR lpLocalName;
  LPSTR lpRemoteName;
  LPSTR lpComment;
  LPSTR lpProvider;
} NETRESOURCEA, *LPNETRESOURCEA;