HRESULT MsiGetFileSignatureInformationW(
  [in]      LPCWSTR        szSignedObjectPath,
  [in]      DWORD          dwFlags,
  [out]     PCCERT_CONTEXT *ppcCertContext,
  [out]     LPBYTE         pbHashData,
  [in, out] LPDWORD        pcbHashData
);