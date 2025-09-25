NTSTATUS FsRtlCancellableWaitForSingleObject(
  [in]           PVOID          Object,
  [in, optional] PLARGE_INTEGER Timeout,
  [in, optional] PIRP           Irp
);