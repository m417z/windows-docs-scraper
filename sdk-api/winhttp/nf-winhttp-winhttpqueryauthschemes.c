WINHTTPAPI BOOL WinHttpQueryAuthSchemes(
  [in]  HINTERNET hRequest,
  [out] LPDWORD   lpdwSupportedSchemes,
  [out] LPDWORD   lpdwFirstScheme,
  [out] LPDWORD   pdwAuthTarget
);