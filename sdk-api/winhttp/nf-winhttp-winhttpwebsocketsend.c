WINHTTPAPI DWORD WinHttpWebSocketSend(
  [in] HINTERNET                      hWebSocket,
  [in] WINHTTP_WEB_SOCKET_BUFFER_TYPE eBufferType,
  [in] PVOID                          pvBuffer,
  [in] DWORD                          dwBufferLength
);