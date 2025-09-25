BOOL CertAddEncodedCertificateToSystemStoreA(
  [in] LPCSTR     szCertStoreName,
  [in] const BYTE *pbCertEncoded,
  [in] DWORD      cbCertEncoded
);