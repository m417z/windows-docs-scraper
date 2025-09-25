BOOL CryptStringToBinaryW(
  [in]      LPCWSTR pszString,
  [in]      DWORD   cchString,
  [in]      DWORD   dwFlags,
  [in]      BYTE    *pbBinary,
  [in, out] DWORD   *pcbBinary,
  [out]     DWORD   *pdwSkip,
  [out]     DWORD   *pdwFlags
);