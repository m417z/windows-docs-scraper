LSA_AUDIT_LOGON LsaAuditLogon;

VOID LsaAuditLogon(
  [in]           NTSTATUS Status,
  [in]           NTSTATUS SubStatus,
  [in]           PUNICODE_STRING AccountName,
  [in]           PUNICODE_STRING AuthenticatingAuthority,
  [in]           PUNICODE_STRING WorkstationName,
  [in, optional] PSID UserSid,
  [in]           SECURITY_LOGON_TYPE LogonType,
  [in]           PTOKEN_SOURCE TokenSource,
  [in]           PLUID LogonId
)
{...}