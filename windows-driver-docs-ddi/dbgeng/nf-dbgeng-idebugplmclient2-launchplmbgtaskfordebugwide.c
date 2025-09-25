HRESULT LaunchPlmBgTaskForDebugWide(
  [in]  ULONG64 Server,
  [in]  ULONG   Timeout,
  [in]  PCWSTR  PackageFullName,
  [in]  PCWSTR  BackgroundTaskId,
  [out] PULONG  ProcessId,
  [out] PULONG  ThreadId
);