SpSaveCredentialsFn Spsavecredentialsfn;

NTSTATUS Spsavecredentialsfn(
  [in] LSA_SEC_HANDLE CredentialHandle,
  [in] PSecBuffer Credentials
)
{...}