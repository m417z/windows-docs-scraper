NTSTATUS UnregisterPhysicalConnectionToExternal(
  [in] PDEVICE_OBJECT  DeviceObject,
  [in] PUNKNOWN        FromUnknown,
  [in] ULONG           FromPin,
  [in] PUNICODE_STRING ToString,
  [in] ULONG           ToPin
);