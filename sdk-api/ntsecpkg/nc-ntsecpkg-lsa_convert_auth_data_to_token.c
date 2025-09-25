LSA_CONVERT_AUTH_DATA_TO_TOKEN LsaConvertAuthDataToToken;

NTSTATUS LsaConvertAuthDataToToken(
  [in]  PVOID UserAuthData,
  [in]  ULONG UserAuthDataSize,
  [in]  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
  [in]  PTOKEN_SOURCE TokenSource,
  [in]  SECURITY_LOGON_TYPE LogonType,
  [in]  PUNICODE_STRING AuthorityName,
  [out] PHANDLE Token,
  [out] PLUID LogonId,
  [out] PUNICODE_STRING AccountName,
  [out] PNTSTATUS SubStatus
)
{...}