NTSTATUS BCryptResolveProviders(
  [in, optional] LPCWSTR              pszContext,
  [in, optional] ULONG                dwInterface,
  [in, optional] LPCWSTR              pszFunction,
  [in, optional] LPCWSTR              pszProvider,
  [in]           ULONG                dwMode,
  [in]           ULONG                dwFlags,
  [in, out]      ULONG                *pcbBuffer,
  [in, out]      PCRYPT_PROVIDER_REFS *ppBuffer
);