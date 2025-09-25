NTSTATUS BCryptEnumContexts(
  [in]      ULONG           dwTable,
  [in, out] ULONG           *pcbBuffer,
  [in, out] PCRYPT_CONTEXTS *ppBuffer
);