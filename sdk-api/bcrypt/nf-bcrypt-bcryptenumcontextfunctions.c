NTSTATUS BCryptEnumContextFunctions(
  [in]      ULONG                    dwTable,
  [in]      LPCWSTR                  pszContext,
  [in]      ULONG                    dwInterface,
  [in, out] ULONG                    *pcbBuffer,
  [in, out] PCRYPT_CONTEXT_FUNCTIONS *ppBuffer
);