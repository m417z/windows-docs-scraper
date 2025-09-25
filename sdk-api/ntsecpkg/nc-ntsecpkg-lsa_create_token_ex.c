LSA_CREATE_TOKEN_EX LsaCreateTokenEx;

NTSTATUS LsaCreateTokenEx(
  [in]  PLUID LogonId,
  [in]  PTOKEN_SOURCE TokenSource,
  [in]  SECURITY_LOGON_TYPE LogonType,
  [in]  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
  [in]  LSA_TOKEN_INFORMATION_TYPE TokenInformationType,
  [in]  PVOID TokenInformation,
  [in]  PTOKEN_GROUPS TokenGroups,
  [in]  PUNICODE_STRING Workstation,
  [in]  PUNICODE_STRING ProfilePath,
  [in]  PVOID SessionInformation,
  [in]  SECPKG_SESSIONINFO_TYPE SessionInformationType,
  [out] PHANDLE Token,
  [out] PNTSTATUS SubStatus
)
{...}