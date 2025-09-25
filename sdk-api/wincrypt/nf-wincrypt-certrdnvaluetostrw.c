DWORD CertRDNValueToStrW(
  [in]  DWORD                dwValueType,
  [in]  PCERT_RDN_VALUE_BLOB pValue,
  [out] LPWSTR               psz,
  [in]  DWORD                csz
);