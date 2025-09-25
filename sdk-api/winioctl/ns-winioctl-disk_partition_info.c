typedef struct _DISK_PARTITION_INFO {
  DWORD           SizeOfPartitionInfo;
  PARTITION_STYLE PartitionStyle;
  union {
    struct {
      DWORD Signature;
      DWORD CheckSum;
    } Mbr;
    struct {
      GUID DiskId;
    } Gpt;
  } DUMMYUNIONNAME;
} DISK_PARTITION_INFO, *PDISK_PARTITION_INFO;