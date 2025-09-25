CREDUIAPI DWORD CredUIPromptForWindowsCredentialsW(
  [in, optional]      PCREDUI_INFOW pUiInfo,
  [in]                DWORD         dwAuthError,
  [in, out]           ULONG         *pulAuthPackage,
  [in, optional]      LPCVOID       pvInAuthBuffer,
  [in]                ULONG         ulInAuthBufferSize,
  [out]               LPVOID        *ppvOutAuthBuffer,
  [out]               ULONG         *pulOutAuthBufferSize,
  [in, out, optional] BOOL          *pfSave,
  [in]                DWORD         dwFlags
);