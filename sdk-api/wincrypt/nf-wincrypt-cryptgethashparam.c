BOOL CryptGetHashParam(
  [in]      HCRYPTHASH hHash,
  [in]      DWORD      dwParam,
  [out]     BYTE       *pbData,
  [in, out] DWORD      *pdwDataLen,
  [in]      DWORD      dwFlags
);