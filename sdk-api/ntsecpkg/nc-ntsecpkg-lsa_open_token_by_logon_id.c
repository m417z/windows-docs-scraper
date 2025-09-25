LSA_OPEN_TOKEN_BY_LOGON_ID LsaOpenTokenByLogonId;

NTSTATUS LsaOpenTokenByLogonId(
  [in]  PLUID LogonId,
  [out] HANDLE *RetTokenHandle
)
{...}