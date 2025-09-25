typedef struct {
  DWORD   cbStruct;
  LPCWSTR pszADsPath;
  LPCWSTR pszClass;
  DWORD   dwMask;
  DWORD   dwState;
  DWORD   dwStateMask;
  CHAR    szDisplayName[DSB_MAX_DISPLAYNAME_CHARS];
  CHAR    szIconLocation[MAX_PATH];
  INT     iIconResID;
} DSBITEMA, *PDSBITEMA;