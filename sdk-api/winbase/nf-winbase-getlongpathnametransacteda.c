DWORD GetLongPathNameTransactedA(
  [in]  LPCSTR lpszShortPath,
  [out] LPSTR  lpszLongPath,
  [in]  DWORD  cchBuffer,
  [in]  HANDLE hTransaction
);