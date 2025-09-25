NTSTATUS UnregisterPhysicalConnectionFromExternal(
  [in] PDEVICE_OBJECT  DeviceObject,
  [in] PUNICODE_STRING FromString,
  [in] ULONG           FromPin,
  [in] PUNKNOWN        ToUnknown,
  [in] ULONG           ToPin
);