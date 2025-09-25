BOOL GetQueuedCompletionStatusEx(
  [in]  HANDLE             CompletionPort,
  [out] LPOVERLAPPED_ENTRY lpCompletionPortEntries,
  [in]  ULONG              ulCount,
  [out] PULONG             ulNumEntriesRemoved,
  [in]  DWORD              dwMilliseconds,
  [in]  BOOL               fAlertable
);