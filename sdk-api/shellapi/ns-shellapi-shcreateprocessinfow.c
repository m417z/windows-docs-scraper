typedef struct _SHCREATEPROCESSINFOW {
  DWORD                 cbSize;
  ULONG                 fMask;
  HWND                  hwnd;
  LPCWSTR               pszFile;
  LPCWSTR               pszParameters;
  LPCWSTR               pszCurrentDirectory;
  HANDLE                hUserToken;
  LPSECURITY_ATTRIBUTES lpProcessAttributes;
  LPSECURITY_ATTRIBUTES lpThreadAttributes;
  BOOL                  bInheritHandles;
  DWORD                 dwCreationFlags;
  LPSTARTUPINFOW        lpStartupInfo;
  LPPROCESS_INFORMATION lpProcessInformation;
} SHCREATEPROCESSINFOW, *PSHCREATEPROCESSINFOW;