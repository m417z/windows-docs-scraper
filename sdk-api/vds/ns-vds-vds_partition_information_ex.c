typedef struct _VDS_PARTITION_INFORMATION_EX {
  __VDS_PARTITION_STYLE dwPartitionStyle;
  ULONGLONG             ullStartingOffset;
  ULONGLONG             ullPartitionLength;
  DWORD                 dwPartitionNumber;
  BOOLEAN               bRewritePartition;
  union {
    VDS_PARTITION_INFO_MBR Mbr;
    VDS_PARTITION_INFO_GPT Gpt;
  };
} VDS_PARTITION_INFORMATION_EX;