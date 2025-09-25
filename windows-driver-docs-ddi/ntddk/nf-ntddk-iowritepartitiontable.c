NTSTATUS IoWritePartitionTable(
  [in] PDEVICE_OBJECT            DeviceObject,
  [in] ULONG                     SectorSize,
  [in] ULONG                     SectorsPerTrack,
  [in] ULONG                     NumberOfHeads,
  [in] _DRIVE_LAYOUT_INFORMATION *PartitionBuffer
);