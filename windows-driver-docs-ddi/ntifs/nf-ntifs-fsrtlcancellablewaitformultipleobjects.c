NTSTATUS FsRtlCancellableWaitForMultipleObjects(
  [in]           ULONG          Count,
  [in]           PVOID []       ObjectArray,
  [in]           WAIT_TYPE      WaitType,
  [in, optional] PLARGE_INTEGER Timeout,
  [in, optional] PKWAIT_BLOCK   WaitBlockArray,
  [in, optional] PIRP           Irp
);