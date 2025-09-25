NTSTATUS WmiFireEvent(
  [in]           PDEVICE_OBJECT DeviceObject,
  [in]           LPCGUID        Guid,
  [in]           ULONG          InstanceIndex,
  [in]           ULONG          EventDataSize,
  [in, optional] PVOID          EventData
);