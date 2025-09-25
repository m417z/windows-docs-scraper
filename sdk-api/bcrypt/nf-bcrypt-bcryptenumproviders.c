NTSTATUS BCryptEnumProviders(
  [in]  LPCWSTR              pszAlgId,
  [out] ULONG                *pImplCount,
  [out] BCRYPT_PROVIDER_NAME **ppImplList,
  [in]  ULONG                dwFlags
);