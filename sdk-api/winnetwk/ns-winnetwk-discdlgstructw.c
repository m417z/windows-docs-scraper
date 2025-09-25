typedef struct _DISCDLGSTRUCTW {
  DWORD  cbStructure;
  HWND   hwndOwner;
  LPWSTR lpLocalName;
  LPWSTR lpRemoteName;
  DWORD  dwFlags;
} DISCDLGSTRUCTW, *LPDISCDLGSTRUCTW;