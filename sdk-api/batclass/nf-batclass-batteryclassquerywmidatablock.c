NTSTATUS BATTERYCLASSAPI BatteryClassQueryWmiDataBlock(
  [in]            PVOID          ClassData,
  [in, out]       PDEVICE_OBJECT DeviceObject,
  [in, out]       PIRP           Irp,
  [in]            ULONG          GuidIndex,
  [out]           PULONG         InstanceLengthArray,
  [in]            ULONG          OutBufferSize,
  [out, optional] PUCHAR         Buffer
);