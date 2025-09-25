typedef struct _ADSPROPERROR {
  HWND    hwndPage;
  PWSTR   pszPageTitle;
  PWSTR   pszObjPath;
  PWSTR   pszObjClass;
  HRESULT hr;
  PWSTR   pszError;
} ADSPROPERROR, *PADSPROPERROR;