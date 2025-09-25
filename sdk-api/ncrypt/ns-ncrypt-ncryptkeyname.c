typedef struct NCryptKeyName {
  LPWSTR pszName;
  LPWSTR pszAlgid;
  DWORD  dwLegacyKeySpec;
  DWORD  dwFlags;
} NCryptKeyName;