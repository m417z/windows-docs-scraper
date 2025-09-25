typedef struct _CONNECTDLGSTRUCTA {
  DWORD          cbStructure;
  HWND           hwndOwner;
  LPNETRESOURCEA lpConnRes;
  DWORD          dwFlags;
  DWORD          dwDevNum;
} CONNECTDLGSTRUCTA, *LPCONNECTDLGSTRUCTA;