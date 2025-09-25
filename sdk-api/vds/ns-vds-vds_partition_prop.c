typedef struct _VDS_PARTITION_PROP {
  VDS_PARTITION_STYLE PartitionStyle;
  ULONG               ulFlags;
  ULONG               ulPartitionNumber;
  ULONGLONG           ullOffset;
  ULONGLONG           ullSize;
  union {
    VDS_PARTITION_INFO_MBR Mbr;
    VDS_PARTITION_INFO_GPT Gpt;
  };
} VDS_PARTITION_PROP;