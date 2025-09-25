BOOL CryptBinaryToStringW(
  [in]            const BYTE *pbBinary,
  [in]            DWORD      cbBinary,
  [in]            DWORD      dwFlags,
  [out, optional] LPWSTR     pszString,
  [in, out]       DWORD      *pcchString
);