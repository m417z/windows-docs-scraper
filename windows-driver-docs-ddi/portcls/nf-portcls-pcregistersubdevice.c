PORTCLASSAPI NTSTATUS PcRegisterSubdevice(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PWSTR          Name,
  [in] PUNKNOWN       Unknown
);