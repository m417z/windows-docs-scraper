NTSTATUS FsRtlProcessFileLock(
  [in]           PFILE_LOCK FileLock,
  [in]           PIRP       Irp,
  [in, optional] PVOID      Context
);