typedef struct _DRIVE_LAYOUT_INFORMATION {
  ULONG                 PartitionCount;
  ULONG                 Signature;
  PARTITION_INFORMATION PartitionEntry[1];
} DRIVE_LAYOUT_INFORMATION, *PDRIVE_LAYOUT_INFORMATION;