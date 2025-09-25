SpGetCredentialsFn Spgetcredentialsfn;

NTSTATUS Spgetcredentialsfn(
  [in]  LSA_SEC_HANDLE CredentialHandle,
  [out] PSecBuffer Credentials
)
{...}