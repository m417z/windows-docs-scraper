NTSTATUS RxRegisterMinirdr(
  [out]     OUT PRDBSS_DEVICE_OBJECT *DeviceObject,
  [in, out] IN OUT PDRIVER_OBJECT    DriverObject,
  [in]      IN PMINIRDR_DISPATCH     MrdrDispatch,
  [in]      IN ULONG                 Controls,
  [in]      IN PUNICODE_STRING       DeviceName,
  [in]      IN ULONG                 DeviceExtensionSize,
  [in]      IN DEVICE_TYPE           DeviceType,
  [in]      IN ULONG                 DeviceCharacteristics
);