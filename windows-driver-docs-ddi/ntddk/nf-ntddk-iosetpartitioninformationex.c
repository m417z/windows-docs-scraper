NTSTATUS IoSetPartitionInformationEx(
  [in] PDEVICE_OBJECT                DeviceObject,
  [in] ULONG                         PartitionNumber,
  [in] _SET_PARTITION_INFORMATION_EX *PartitionInfo
);