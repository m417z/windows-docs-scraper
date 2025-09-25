LSA_ADD_CREDENTIAL LsaAddCredential;

NTSTATUS LsaAddCredential(
  [in] PLUID LogonId,
  [in] ULONG AuthenticationPackage,
  [in] PLSA_STRING PrimaryKeyValue,
  [in] PLSA_STRING Credentials
)
{...}