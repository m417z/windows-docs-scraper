DWORD CertNameToStrA(
  [in]  DWORD           dwCertEncodingType,
  [in]  PCERT_NAME_BLOB pName,
  [in]  DWORD           dwStrType,
  [out] LPSTR           psz,
  [in]  DWORD           csz
);