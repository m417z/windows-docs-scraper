SpQueryMetaDataFn Spquerymetadatafn;

NTSTATUS Spquerymetadatafn(
  [in]           LSA_SEC_HANDLE CredentialHandle,
  [in, optional] PUNICODE_STRING TargetName,
  [in]           ULONG ContextRequirements,
  [out]          PULONG MetaDataLength,
  [out]          PUCHAR *MetaData,
  [in, out]      PLSA_SEC_HANDLE ContextHandle
)
{...}