typedef struct _NCryptAlgorithmName {
  LPWSTR pszName;
  DWORD  dwClass;
  DWORD  dwAlgOperations;
  DWORD  dwFlags;
} NCryptAlgorithmName;