typedef struct {
  DWORD cbSize;
  DWORD dwSignature;
  CHAR  szTarget[MAX_PATH];
  WCHAR swzTarget[MAX_PATH];
} EXP_SZ_LINK, *LPEXP_SZ_LINK;