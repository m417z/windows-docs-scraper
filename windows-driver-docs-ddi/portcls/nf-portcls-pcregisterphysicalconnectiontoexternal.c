PORTCLASSAPI NTSTATUS PcRegisterPhysicalConnectionToExternal(
  [in] PDEVICE_OBJECT  DeviceObject,
  [in] PUNKNOWN        FromUnknown,
  [in] ULONG           FromPin,
  [in] PUNICODE_STRING ToString,
  [in] ULONG           ToPin
);