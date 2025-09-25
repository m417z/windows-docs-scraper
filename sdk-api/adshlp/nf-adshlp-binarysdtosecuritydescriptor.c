HRESULT BinarySDToSecurityDescriptor(
  [in]  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [out] VARIANT              *pVarsec,
  [in]  LPCWSTR              pszServerName,
  [in]  LPCWSTR              userName,
  [in]  LPCWSTR              passWord,
  [in]  DWORD                dwFlags
);