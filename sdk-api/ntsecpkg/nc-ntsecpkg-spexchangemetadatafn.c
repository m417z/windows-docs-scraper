SpExchangeMetaDataFn Spexchangemetadatafn;

NTSTATUS Spexchangemetadatafn(
  [in]           LSA_SEC_HANDLE CredentialHandle,
  [in, optional] PUNICODE_STRING TargetName,
  [in]           ULONG ContextRequirements,
  [in]           ULONG MetaDataLength,
  [in]           PUCHAR MetaData,
  [in, out]      PLSA_SEC_HANDLE ContextHandle
)
{...}