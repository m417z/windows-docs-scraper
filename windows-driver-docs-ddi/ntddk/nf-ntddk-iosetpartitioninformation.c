NTSTATUS IoSetPartitionInformation(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] ULONG          SectorSize,
  [in] ULONG          PartitionNumber,
  [in] ULONG          PartitionType
);