CREDUIAPI DWORD CredUICmdLinePromptForCredentialsA(
  [in]           PCSTR       pszTargetName,
  [in]           PCtxtHandle pContext,
  [in, optional] DWORD       dwAuthError,
  [in, out]      PSTR        UserName,
  [in]           ULONG       ulUserBufferSize,
  [in, out]      PSTR        pszPassword,
  [in]           ULONG       ulPasswordBufferSize,
  [in, out]      PBOOL       pfSave,
  [in]           DWORD       dwFlags
);