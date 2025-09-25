CREDUIAPI DWORD CredUIPromptForCredentialsA(
  [in, optional] PCREDUI_INFOA pUiInfo,
  [in]           PCSTR         pszTargetName,
  [in]           PCtxtHandle   pContext,
  [in, optional] DWORD         dwAuthError,
  [in, out]      PSTR          pszUserName,
  [in]           ULONG         ulUserNameBufferSize,
  [in, out]      PSTR          pszPassword,
  [in]           ULONG         ulPasswordBufferSize,
  [in, out]      BOOL          *save,
  [in]           DWORD         dwFlags
);