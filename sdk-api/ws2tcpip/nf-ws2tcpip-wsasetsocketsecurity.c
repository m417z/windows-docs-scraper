INT WSAAPI WSASetSocketSecurity(
  [in]           SOCKET                             Socket,
  [in, optional] const SOCKET_SECURITY_SETTINGS     *SecuritySettings,
  [in]           ULONG                              SecuritySettingsLen,
  [in, optional] LPWSAOVERLAPPED                    Overlapped,
  [in, optional] LPWSAOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine
);