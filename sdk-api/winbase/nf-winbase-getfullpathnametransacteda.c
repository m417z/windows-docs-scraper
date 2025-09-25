DWORD GetFullPathNameTransactedA(
  [in]  LPCSTR lpFileName,
  [in]  DWORD  nBufferLength,
  [out] LPSTR  lpBuffer,
  [out] LPSTR  *lpFilePart,
  [in]  HANDLE hTransaction
);