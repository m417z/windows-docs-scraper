typedef struct _CMINVOKECOMMANDINFO {
  DWORD  cbSize;
  DWORD  fMask;
  HWND   hwnd;
  LPCSTR lpVerb;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  int    nShow;
  DWORD  dwHotKey;
  HANDLE hIcon;
} CMINVOKECOMMANDINFO;