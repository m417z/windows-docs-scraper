BOOL SslCrackCertificate(
  [in]  PUCHAR           pbCertificate,
  [in]  DWORD            cbCertificate,
  [in]  DWORD            dwFlags,
  [out] PX509Certificate *ppCertificate
);