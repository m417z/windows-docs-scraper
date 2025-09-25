int SHFormatDateTimeA(
  [in]                const FILETIME *pft,
  [in, out, optional] DWORD          *pdwFlags,
  [out]               LPSTR          pszBuf,
                      UINT           cchBuf
);