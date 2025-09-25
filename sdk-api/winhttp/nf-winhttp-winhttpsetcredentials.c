WINHTTPAPI BOOL WinHttpSetCredentials(
  [in] HINTERNET hRequest,
  [in] DWORD     AuthTargets,
  [in] DWORD     AuthScheme,
  [in] LPCWSTR   pwszUserName,
  [in] LPCWSTR   pwszPassword,
  [in] LPVOID    pAuthParams
);