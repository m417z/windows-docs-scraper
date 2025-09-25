SECURITY_STATUS NCryptDeriveKey(
  [in]            NCRYPT_SECRET_HANDLE hSharedSecret,
  [in]            LPCWSTR              pwszKDF,
  [in, optional]  NCryptBufferDesc     *pParameterList,
  [out, optional] PBYTE                pbDerivedKey,
  [in]            DWORD                cbDerivedKey,
  [out]           DWORD                *pcbResult,
  [in]            ULONG                dwFlags
);