WINHTTPAPI DWORD WinHttpWebSocketQueryCloseStatus(
  [in]  HINTERNET hWebSocket,
  [out] USHORT    *pusStatus,
  [out] PVOID     pvReason,
  [in]  DWORD     dwReasonLength,
  [out] DWORD     *pdwReasonLengthConsumed
);