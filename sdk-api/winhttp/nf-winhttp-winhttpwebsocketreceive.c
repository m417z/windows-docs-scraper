WINHTTPAPI DWORD WinHttpWebSocketReceive(
  [in]  HINTERNET                      hWebSocket,
  [out] PVOID                          pvBuffer,
  [in]  DWORD                          dwBufferLength,
  [out] DWORD                          *pdwBytesRead,
  [out] WINHTTP_WEB_SOCKET_BUFFER_TYPE *peBufferType
);