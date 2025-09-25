NTSTATUS BCryptQueryContextConfiguration(
  [in]      ULONG                 dwTable,
  [in]      LPCWSTR               pszContext,
  [in, out] ULONG                 *pcbBuffer,
  [in, out] PCRYPT_CONTEXT_CONFIG *ppBuffer
);