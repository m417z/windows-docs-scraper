NTSTATUS SeQueryInformationToken(
  [in]  PACCESS_TOKEN           Token,
  [in]  TOKEN_INFORMATION_CLASS TokenInformationClass,
  [out] PVOID                   *TokenInformation
);