LSA_AP_LOGON_USER LsaApLogonUser;

NTSTATUS LsaApLogonUser(
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
  [out] PLSA_UNICODE_STRING *AccountName,
  [out] PLSA_UNICODE_STRING *AuthenticatingAuthority
)
{...}