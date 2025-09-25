typedef struct _PARTITION_INFORMATION_MBR {
  BYTE    PartitionType;
  BOOLEAN BootIndicator;
  BOOLEAN RecognizedPartition;
  DWORD   HiddenSectors;
  GUID    PartitionId;
} PARTITION_INFORMATION_MBR, *PPARTITION_INFORMATION_MBR;