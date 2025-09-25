NTSTATUS BCryptEnumContextFunctionProviders(
  [in]      ULONG                             dwTable,
  [in]      LPCWSTR                           pszContext,
  [in]      ULONG                             dwInterface,
  [in]      LPCWSTR                           pszFunction,
  [in, out] ULONG                             *pcbBuffer,
  [in, out] PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer
);