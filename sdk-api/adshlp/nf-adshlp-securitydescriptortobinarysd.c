HRESULT SecurityDescriptorToBinarySD(
  [in]  VARIANT              vVarSecDes,
  [out] PSECURITY_DESCRIPTOR *ppSecurityDescriptor,
  [out] PDWORD               pdwSDLength,
  [in]  LPCWSTR              pszServerName,
  [in]  LPCWSTR              userName,
  [in]  LPCWSTR              passWord,
  [in]  DWORD                dwFlags
);