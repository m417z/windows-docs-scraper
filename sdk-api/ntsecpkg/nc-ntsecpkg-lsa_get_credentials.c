LSA_GET_CREDENTIALS LsaGetCredentials;

NTSTATUS LsaGetCredentials(
  [in]      PLUID LogonId,
  [in]      ULONG AuthenticationPackage,
  [in, out] PULONG QueryContext,
  [in]      BOOLEAN RetrieveAllCredentials,
  [in, out] PLSA_STRING PrimaryKeyValue,
  [out]     PULONG PrimaryKeyLength,
  [out]     PLSA_STRING Credentials
)
{...}