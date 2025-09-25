typedef struct {
  DWORD       cbStruct;
  HWND        hwndOwner;
  LPCSTR      pszCaption;
  LPCSTR      pszTitle;
  LPCWSTR     pszRoot;
  LPWSTR      pszPath;
  ULONG       cchPath;
  DWORD       dwFlags;
  BFFCALLBACK pfnCallback;
  LPARAM      lParam;
  DWORD       dwReturnFormat;
  LPCWSTR     pUserName;
  LPCWSTR     pPassword;
  LPWSTR      pszObjectClass;
  ULONG       cchObjectClass;
} DSBROWSEINFOA, *PDSBROWSEINFOA;