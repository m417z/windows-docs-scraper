unsigned long SEC_ENTRY SspiPromptForCredentialsW(
  [in]                PCWSTR                          pszTargetName,
  [in]                PCREDUI_INFOW                   pUiInfo,
  [in]                unsigned long                   dwAuthError,
  [in]                PCWSTR                          pszPackage,
  [in]                PSEC_WINNT_AUTH_IDENTITY_OPAQUE pInputAuthIdentity,
  [out]               PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity,
  [in, out, optional] int                             *pfSave,
  [in]                unsigned long                   dwFlags
);