NTSTATUS IoAttachDeviceToDeviceStackSafe(
  [in]  PDEVICE_OBJECT SourceDevice,
  [in]  PDEVICE_OBJECT TargetDevice,
  [out] PDEVICE_OBJECT *AttachedToDeviceObject
);