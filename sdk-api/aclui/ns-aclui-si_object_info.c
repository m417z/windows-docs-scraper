typedef struct _SI_OBJECT_INFO {
  DWORD     dwFlags;
  HINSTANCE hInstance;
  LPWSTR    pszServerName;
  LPWSTR    pszObjectName;
  LPWSTR    pszPageTitle;
  GUID      guidObjectType;
} SI_OBJECT_INFO, *PSI_OBJECT_INFO;