LSA_AUDIT_ACCOUNT_LOGON LsaAuditAccountLogon;

NTSTATUS LsaAuditAccountLogon(
  [in] ULONG AuditId,
  [in] BOOLEAN Success,
  [in] PUNICODE_STRING Source,
  [in] PUNICODE_STRING ClientName,
  [in] PUNICODE_STRING MappedName,
  [in] NTSTATUS Status
)
{...}