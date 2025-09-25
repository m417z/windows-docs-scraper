KSDDKAPI NTSTATUS KsForwardAndCatchIrp(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PIRP           Irp,
  [in] PFILE_OBJECT   FileObject,
  [in] KSSTACK_USE    StackUse
);