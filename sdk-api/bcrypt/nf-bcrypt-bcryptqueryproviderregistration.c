NTSTATUS BCryptQueryProviderRegistration(
  [in]      LPCWSTR             pszProvider,
  [in]      ULONG               dwMode,
  [in]      ULONG               dwInterface,
  [in, out] ULONG               *pcbBuffer,
  [in, out] PCRYPT_PROVIDER_REG *ppBuffer
);