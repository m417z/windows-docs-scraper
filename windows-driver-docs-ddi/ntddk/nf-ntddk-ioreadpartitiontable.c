NTSTATUS IoReadPartitionTable(
  [in]  PDEVICE_OBJECT            DeviceObject,
  [in]  ULONG                     SectorSize,
  [in]  BOOLEAN                   ReturnRecognizedPartitions,
  [out] _DRIVE_LAYOUT_INFORMATION **PartitionBuffer
);