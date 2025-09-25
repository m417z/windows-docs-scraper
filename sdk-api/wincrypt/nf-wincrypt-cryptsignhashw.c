BOOL CryptSignHashW(
  [in]      HCRYPTHASH hHash,
  [in]      DWORD      dwKeySpec,
  [in]      LPCWSTR    szDescription,
  [in]      DWORD      dwFlags,
  [out]     BYTE       *pbSignature,
  [in, out] DWORD      *pdwSigLen
);