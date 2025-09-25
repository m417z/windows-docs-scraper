SpGetUserInfoFn Spgetuserinfofn;

NTSTATUS Spgetuserinfofn(
  [in]  PLUID LogonId,
  [in]  ULONG Flags,
  [out] PSecurityUserData *UserData
)
{...}