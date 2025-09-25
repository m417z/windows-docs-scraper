typedef struct _PARTITION_INFORMATION_MBR {
  UCHAR   PartitionType;
  BOOLEAN BootIndicator;
  BOOLEAN RecognizedPartition;
  ULONG   HiddenSectors;
  GUID    PartitionId;
} PARTITION_INFORMATION_MBR, *PPARTITION_INFORMATION_MBR;