BOOL CryptVerifySignatureW(
  [in] HCRYPTHASH hHash,
  [in] const BYTE *pbSignature,
  [in] DWORD      dwSigLen,
  [in] HCRYPTKEY  hPubKey,
  [in] LPCWSTR    szDescription,
  [in] DWORD      dwFlags
);