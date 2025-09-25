NTSTATUS IoAttachDevice(
  [in]  PDEVICE_OBJECT  SourceDevice,
  [in]  PUNICODE_STRING TargetDevice,
  [out] PDEVICE_OBJECT  *AttachedDevice
);