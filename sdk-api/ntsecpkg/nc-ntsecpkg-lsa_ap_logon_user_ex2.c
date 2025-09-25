LSA_AP_LOGON_USER_EX2 LsaApLogonUserEx2;

NTSTATUS LsaApLogonUserEx2(
  [in]  PLSA_CLIENT_REQUEST ClientRequest,
  [in]  SECURITY_LOGON_TYPE LogonType,
  [in]  PVOID ProtocolSubmitBuffer,
  [in]  PVOID ClientBufferBase,
  [in]  ULONG SubmitBufferSize,
  [out] PVOID *ProfileBuffer,
  [out] PULONG ProfileBufferSize,
  [out] PLUID LogonId,
  [out] PNTSTATUS SubStatus,
  [out] PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
  [out] PVOID *TokenInformation,
  [out] PUNICODE_STRING *AccountName,
  [out] PUNICODE_STRING *AuthenticatingAuthority,
  [out] PUNICODE_STRING *MachineName,
  [out] PSECPKG_PRIMARY_CRED PrimaryCredentials,
  [out] PSECPKG_SUPPLEMENTAL_CRED_ARRAY *SupplementalCredentials
)
{...}