typedef struct _CMINVOKECOMMANDINFOEX {
  DWORD   cbSize;
  DWORD   fMask;
  HWND    hwnd;
  LPCSTR  lpVerb;
  LPCSTR  lpParameters;
  LPCSTR  lpDirectory;
  int     nShow;
  DWORD   dwHotKey;
  HANDLE  hIcon;
  LPCSTR  lpTitle;
  LPCWSTR lpVerbW;
  LPCWSTR lpParametersW;
  LPCWSTR lpDirectoryW;
  LPCWSTR lpTitleW;
  POINT   ptInvoke;
} CMINVOKECOMMANDINFOEX;