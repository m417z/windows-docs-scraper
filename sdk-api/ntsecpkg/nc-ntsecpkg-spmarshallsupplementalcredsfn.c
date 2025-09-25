SpMarshallSupplementalCredsFn Spmarshallsupplementalcredsfn;

NTSTATUS Spmarshallsupplementalcredsfn(
  [in]  ULONG CredentialSize,
  [in]  PUCHAR Credentials,
  [out] PULONG MarshalledCredSize,
  [out] PVOID *MarshalledCreds
)
{...}