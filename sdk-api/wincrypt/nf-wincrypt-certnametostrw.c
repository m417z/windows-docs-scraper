DWORD CertNameToStrW(
  [in]  DWORD           dwCertEncodingType,
  [in]  PCERT_NAME_BLOB pName,
  [in]  DWORD           dwStrType,
  [out] LPWSTR          psz,
  [in]  DWORD           csz
);