DWORD GetLongPathNameTransactedW(
  [in]  LPCWSTR lpszShortPath,
  [out] LPWSTR  lpszLongPath,
  [in]  DWORD   cchBuffer,
  [in]  HANDLE  hTransaction
);