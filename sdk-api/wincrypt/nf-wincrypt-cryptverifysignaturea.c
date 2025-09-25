BOOL CryptVerifySignatureA(
  [in] HCRYPTHASH hHash,
  [in] const BYTE *pbSignature,
  [in] DWORD      dwSigLen,
  [in] HCRYPTKEY  hPubKey,
  [in] LPCSTR     szDescription,
  [in] DWORD      dwFlags
);