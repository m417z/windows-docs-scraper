NTSTATUS FsRtlOplockFsctrlEx(
  [in] POPLOCK Oplock,
  [in] PIRP    Irp,
  [in] ULONG   OpenCount,
  [in] ULONG   Flags
);