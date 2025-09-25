NTSTATUS BCryptDeriveKey(
  [in]            BCRYPT_SECRET_HANDLE hSharedSecret,
  [in]            LPCWSTR              pwszKDF,
  [in, optional]  BCryptBufferDesc     *pParameterList,
  [out, optional] PUCHAR               pbDerivedKey,
  [in]            ULONG                cbDerivedKey,
  [out]           ULONG                *pcbResult,
  [in]            ULONG                dwFlags
);