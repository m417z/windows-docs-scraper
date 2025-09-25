unsigned long SEC_ENTRY SspiPromptForCredentialsA(
  [in]                PCSTR                           pszTargetName,
  [in]                PCREDUI_INFOA                   pUiInfo,
  [in]                unsigned long                   dwAuthError,
  [in]                PCSTR                           pszPackage,
  [in]                PSEC_WINNT_AUTH_IDENTITY_OPAQUE pInputAuthIdentity,
  [out]               PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity,
  [in, out, optional] int                             *pfSave,
  [in]                unsigned long                   dwFlags
);