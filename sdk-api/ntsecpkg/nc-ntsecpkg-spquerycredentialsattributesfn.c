SpQueryCredentialsAttributesFn Spquerycredentialsattributesfn;

NTSTATUS Spquerycredentialsattributesfn(
  [in]  LSA_SEC_HANDLE CredentialHandle,
  [in]  ULONG CredentialAttribute,
  [out] PVOID Buffer
)
{...}