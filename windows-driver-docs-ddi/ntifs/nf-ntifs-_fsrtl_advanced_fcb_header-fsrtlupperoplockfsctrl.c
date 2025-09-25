NTSTATUS FsRtlUpperOplockFsctrl(
  [in] POPLOCK Oplock,
  [in] PIRP    Irp,
  [in] ULONG   OpenCount,
  [in] ULONG   LowerOplockState,
  [in] ULONG   Flags
);