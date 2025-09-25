typedef struct _PARTITION_INFORMATION {
  LARGE_INTEGER StartingOffset;
  LARGE_INTEGER PartitionLength;
  DWORD         HiddenSectors;
  DWORD         PartitionNumber;
  BYTE          PartitionType;
  BOOLEAN       BootIndicator;
  BOOLEAN       RecognizedPartition;
  BOOLEAN       RewritePartition;
} PARTITION_INFORMATION, *PPARTITION_INFORMATION;