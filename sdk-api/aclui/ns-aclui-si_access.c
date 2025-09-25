typedef struct _SI_ACCESS {
  const GUID  *pguid;
  ACCESS_MASK mask;
  LPCWSTR     pszName;
  DWORD       dwFlags;
} SI_ACCESS, *PSI_ACCESS;