NTSTATUS FLTAPI FltEnumerateInstanceInformationByDeviceObject(
  [in]  PDEVICE_OBJECT             DeviceObject,
  [in]  ULONG                      Index,
  [in]  INSTANCE_INFORMATION_CLASS InformationClass,
  [out] PVOID                      Buffer,
  [in]  ULONG                      BufferSize,
  [out] PULONG                     BytesReturned
);