NTSYSAPI NTSTATUS ZwTerminateProcess(
  [in, optional] HANDLE   ProcessHandle,
  [in]           NTSTATUS ExitStatus
);