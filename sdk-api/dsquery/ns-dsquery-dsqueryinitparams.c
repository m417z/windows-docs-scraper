typedef struct {
  DWORD  cbStruct;
  DWORD  dwFlags;
  LPWSTR pDefaultScope;
  LPWSTR pDefaultSaveLocation;
  LPWSTR pUserName;
  LPWSTR pPassword;
  LPWSTR pServer;
} DSQUERYINITPARAMS, *LPDSQUERYINITPARAMS;