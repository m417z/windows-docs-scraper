typedef struct _VDS_PARTITION_INFO_MBR {
  BYTE    partitionType;
  BOOLEAN bootIndicator;
  BOOLEAN recognizedPartition;
  DWORD   hiddenSectors;
} VDS_PARTITION_INFO_MBR;