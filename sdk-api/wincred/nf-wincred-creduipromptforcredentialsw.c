CREDUIAPI DWORD CredUIPromptForCredentialsW(
  [in, optional] PCREDUI_INFOW pUiInfo,
  [in]           PCWSTR        pszTargetName,
  [in]           PCtxtHandle   pContext,
  [in, optional] DWORD         dwAuthError,
  [in, out]      PWSTR         pszUserName,
  [in]           ULONG         ulUserNameBufferSize,
  [in, out]      PWSTR         pszPassword,
  [in]           ULONG         ulPasswordBufferSize,
  [in, out]      BOOL          *save,
  [in]           DWORD         dwFlags
);