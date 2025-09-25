WINHTTPAPI BOOL WinHttpSendRequest(
  [in]           HINTERNET hRequest,
  [in, optional] LPCWSTR   lpszHeaders,
  [in]           DWORD     dwHeadersLength,
  [in, optional] LPVOID    lpOptional,
  [in]           DWORD     dwOptionalLength,
  [in]           DWORD     dwTotalLength,
  [in]           DWORD_PTR dwContext
);