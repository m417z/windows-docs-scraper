PORTCLASSAPI NTSTATUS PcRegisterPhysicalConnection(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PUNKNOWN       FromUnknown,
  [in] ULONG          FromPin,
  [in] PUNKNOWN       ToUnknown,
  [in] ULONG          ToPin
);