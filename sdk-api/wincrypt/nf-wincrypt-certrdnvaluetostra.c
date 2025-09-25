DWORD CertRDNValueToStrA(
  [in]  DWORD                dwValueType,
  [in]  PCERT_RDN_VALUE_BLOB pValue,
  [out] LPSTR                psz,
  [in]  DWORD                csz
);