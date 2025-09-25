SECURITY_STATUS SEC_ENTRY SspiGetCredUIContext(
  [in]  HANDLE                           ContextHandle,
  [in]  GUID                             *CredType,
  [in]  LUID                             *LogonId,
  [out] PSEC_WINNT_CREDUI_CONTEXT_VECTOR *CredUIContexts,
  [out] HANDLE                           *TokenHandle
);