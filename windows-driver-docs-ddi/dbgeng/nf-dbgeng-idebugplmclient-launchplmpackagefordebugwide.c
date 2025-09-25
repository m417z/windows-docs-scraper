HRESULT LaunchPlmPackageForDebugWide(
  [in]           ULONG64 Server,
  [in]           ULONG   Timeout,
  [in]           PCWSTR  PackageFullName,
  [in]           PCWSTR  AppName,
  [in, optional] PCWSTR  Arguments,
  [out]          PULONG  ProcessId,
  [out]          PULONG  ThreadId
);