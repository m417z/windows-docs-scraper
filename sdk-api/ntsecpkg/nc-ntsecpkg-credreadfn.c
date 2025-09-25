CredReadFn Credreadfn;

NTSTATUS Credreadfn(
  [in]  PLUID LogonId,
  [in]  ULONG CredFlags,
  [in]  LPWSTR TargetName,
  [in]  ULONG Type,
  [in]  ULONG Flags,
  [out] PENCRYPTED_CREDENTIALW *Credential
)
{...}