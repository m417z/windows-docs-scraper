LSA_DELETE_CREDENTIAL LsaDeleteCredential;

NTSTATUS LsaDeleteCredential(
  [in] PLUID LogonId,
  [in] ULONG AuthenticationPackage,
  [in] PLSA_STRING PrimaryKeyValue
)
{...}