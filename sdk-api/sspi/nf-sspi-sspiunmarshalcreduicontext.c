SECURITY_STATUS SEC_ENTRY SspiUnmarshalCredUIContext(
  [in]  PUCHAR                    MarshaledCredUIContext,
  [in]  ULONG                     MarshaledCredUIContextLength,
  [out] PSEC_WINNT_CREDUI_CONTEXT *CredUIContext
);