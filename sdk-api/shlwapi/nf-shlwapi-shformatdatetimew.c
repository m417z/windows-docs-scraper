int SHFormatDateTimeW(
  [in]                const FILETIME *pft,
  [in, out, optional] DWORD          *pdwFlags,
  [out]               LPWSTR         pszBuf,
                      UINT           cchBuf
);