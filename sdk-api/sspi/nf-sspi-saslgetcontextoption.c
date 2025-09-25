SECURITY_STATUS SEC_ENTRY SaslGetContextOption(
  [in]            PCtxtHandle ContextHandle,
  [in]            ULONG       Option,
  [out]           PVOID       Value,
  [out]           ULONG       Size,
  [out, optional] PULONG      Needed
);