BOOL CertGetIntendedKeyUsage(
  [in]  DWORD      dwCertEncodingType,
  [in]  PCERT_INFO pCertInfo,
  [out] BYTE       *pbKeyUsage,
  [in]  DWORD      cbKeyUsage
);