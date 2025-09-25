SpUpdateCredentialsFn Spupdatecredentialsfn;

NTSTATUS Spupdatecredentialsfn(
  [in] LSA_SEC_HANDLE ContextHandle,
  [in] GUID *CredType,
  [in] ULONG FlatCredUIContextLength,
       PUCHAR FlatCredUIContext
)
{...}