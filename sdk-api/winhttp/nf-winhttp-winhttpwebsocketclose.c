WINHTTPAPI DWORD WinHttpWebSocketClose(
  [in]           HINTERNET hWebSocket,
  [in]           USHORT    usStatus,
  [in, optional] PVOID     pvReason,
  [in]           DWORD     dwReasonLength
);