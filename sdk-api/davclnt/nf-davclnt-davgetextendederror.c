DWORD DavGetExtendedError(
  [in]      HANDLE hFile,
  [out]     DWORD  *ExtError,
  [out]     LPWSTR ExtErrorString,
  [in, out] DWORD  *cChSize
);