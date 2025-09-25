SECURITY_STATUS SEC_ENTRY SspiUpdateCredentials(
  [in] HANDLE ContextHandle,
  [in] GUID   *CredType,
  [in] ULONG  FlatCredUIContextLength,
  [in] PUCHAR FlatCredUIContext
);