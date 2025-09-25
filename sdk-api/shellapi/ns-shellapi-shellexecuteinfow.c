typedef struct _SHELLEXECUTEINFOW {
  DWORD     cbSize;
  ULONG     fMask;
  HWND      hwnd;
  LPCWSTR   lpVerb;
  LPCWSTR   lpFile;
  LPCWSTR   lpParameters;
  LPCWSTR   lpDirectory;
  int       nShow;
  HINSTANCE hInstApp;
  void      *lpIDList;
  LPCWSTR   lpClass;
  HKEY      hkeyClass;
  DWORD     dwHotKey;
  union {
    HANDLE hIcon;
    HANDLE hMonitor;
  } DUMMYUNIONNAME;
  HANDLE    hProcess;
} SHELLEXECUTEINFOW, *LPSHELLEXECUTEINFOW;