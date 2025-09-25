BOOL CryptStringToBinaryA(
  [in]      LPCSTR pszString,
  [in]      DWORD  cchString,
  [in]      DWORD  dwFlags,
  [in]      BYTE   *pbBinary,
  [in, out] DWORD  *pcbBinary,
  [out]     DWORD  *pdwSkip,
  [out]     DWORD  *pdwFlags
);