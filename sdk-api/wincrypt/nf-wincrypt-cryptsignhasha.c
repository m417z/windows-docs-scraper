BOOL CryptSignHashA(
  [in]      HCRYPTHASH hHash,
  [in]      DWORD      dwKeySpec,
  [in]      LPCSTR     szDescription,
  [in]      DWORD      dwFlags,
  [out]     BYTE       *pbSignature,
  [in, out] DWORD      *pdwSigLen
);