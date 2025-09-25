NTSYSAPI NTSTATUS ZwWaitForSingleObject(
  [in]           HANDLE         Handle,
  [in]           BOOLEAN        Alertable,
  [in, optional] PLARGE_INTEGER Timeout
);