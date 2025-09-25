CredWriteFn Credwritefn;

NTSTATUS Credwritefn(
  [in] PLUID LogonId,
  [in] ULONG CredFlags,
  [in] PENCRYPTED_CREDENTIALW Credential,
  [in] ULONG Flags
)
{...}