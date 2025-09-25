typedef struct {
  DWORD   cbStruct;
  LPCWSTR pszADsPath;
  LPCWSTR pszClass;
  DWORD   dwMask;
  DWORD   dwState;
  DWORD   dwStateMask;
  WCHAR   szDisplayName[DSB_MAX_DISPLAYNAME_CHARS];
  WCHAR   szIconLocation[MAX_PATH];
  INT     iIconResID;
} DSBITEMW, *PDSBITEMW;