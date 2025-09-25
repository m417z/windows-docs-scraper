BOOL CertAddEncodedCertificateToSystemStoreW(
  [in] LPCWSTR    szCertStoreName,
  [in] const BYTE *pbCertEncoded,
  [in] DWORD      cbCertEncoded
);