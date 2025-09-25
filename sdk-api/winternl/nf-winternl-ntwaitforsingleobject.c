NTSTATUS NtWaitForSingleObject(
  [in] HANDLE         Handle,
  [in] BOOLEAN        Alertable,
  [in] PLARGE_INTEGER Timeout
);