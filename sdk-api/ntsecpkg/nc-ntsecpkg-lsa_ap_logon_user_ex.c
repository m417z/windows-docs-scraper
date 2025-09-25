LSA_AP_LOGON_USER_EX LsaApLogonUserEx;

NTSTATUS LsaApLogonUserEx(
  [in]  PLSA_CLIENT_REQUEST ClientRequest,
  [in]  SECURITY_LOGON_TYPE LogonType,
  [in]  PVOID AuthenticationInformation,
  [in]  PVOID ClientAuthenticationBase,
  [in]  ULONG AuthenticationInformationLength,
  [out] PVOID *ProfileBuffer,
  [out] PULONG ProfileBufferLength,
  [out] PLUID LogonId,
  [out] PNTSTATUS SubStatus,
  [out] PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
  [out] PVOID *TokenInformation,
  [out] PUNICODE_STRING *AccountName,
  [out] PUNICODE_STRING *AuthenticatingAuthority,
  [out] PUNICODE_STRING *MachineName
)
{...}