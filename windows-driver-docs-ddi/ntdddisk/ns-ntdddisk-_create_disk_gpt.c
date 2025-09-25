typedef struct _CREATE_DISK_GPT {
  GUID  DiskId;
  ULONG MaxPartitionCount;
} CREATE_DISK_GPT, *PCREATE_DISK_GPT;