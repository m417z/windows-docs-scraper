typedef struct _CONNECTDLGSTRUCTW {
  DWORD          cbStructure;
  HWND           hwndOwner;
  LPNETRESOURCEW lpConnRes;
  DWORD          dwFlags;
  DWORD          dwDevNum;
} CONNECTDLGSTRUCTW, *LPCONNECTDLGSTRUCTW;