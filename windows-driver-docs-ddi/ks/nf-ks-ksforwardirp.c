KSDDKAPI NTSTATUS KsForwardIrp(
  [in] PIRP         Irp,
  [in] PFILE_OBJECT FileObject,
  [in] BOOLEAN      ReuseStackLocation
);