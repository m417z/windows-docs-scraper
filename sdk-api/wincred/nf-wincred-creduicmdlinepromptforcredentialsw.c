CREDUIAPI DWORD CredUICmdLinePromptForCredentialsW(
  [in]           PCWSTR      pszTargetName,
  [in]           PCtxtHandle pContext,
  [in, optional] DWORD       dwAuthError,
  [in, out]      PWSTR       UserName,
  [in]           ULONG       ulUserBufferSize,
  [in, out]      PWSTR       pszPassword,
  [in]           ULONG       ulPasswordBufferSize,
  [in, out]      PBOOL       pfSave,
  [in]           DWORD       dwFlags
);