typedef struct _DISCDLGSTRUCTA {
  DWORD cbStructure;
  HWND  hwndOwner;
  LPSTR lpLocalName;
  LPSTR lpRemoteName;
  DWORD dwFlags;
} DISCDLGSTRUCTA, *LPDISCDLGSTRUCTA;