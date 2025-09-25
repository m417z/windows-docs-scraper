typedef struct _PARTITION_INFORMATION_EX {
  PARTITION_STYLE PartitionStyle;
  LARGE_INTEGER   StartingOffset;
  LARGE_INTEGER   PartitionLength;
  ULONG           PartitionNumber;
  BOOLEAN         RewritePartition;
  BOOLEAN         IsServicePartition;
  union {
    PARTITION_INFORMATION_MBR Mbr;
    PARTITION_INFORMATION_GPT Gpt;
  } DUMMYUNIONNAME;
} PARTITION_INFORMATION_EX, *PPARTITION_INFORMATION_EX;