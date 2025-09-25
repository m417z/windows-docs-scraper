DWORD WSAAPI ProcessSocketNotifications(
  HANDLE                   completionPort,
  UINT32                   registrationCount,
  SOCK_NOTIFY_REGISTRATION *registrationInfos,
  UINT32                   timeoutMs,
  ULONG                    completionCount,
  OVERLAPPED_ENTRY         *completionPortEntries,
  UINT32                   *receivedEntryCount
);