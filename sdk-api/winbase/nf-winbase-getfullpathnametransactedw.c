DWORD GetFullPathNameTransactedW(
  [in]  LPCWSTR lpFileName,
  [in]  DWORD   nBufferLength,
  [out] LPWSTR  lpBuffer,
  [out] LPWSTR  *lpFilePart,
  [in]  HANDLE  hTransaction
);