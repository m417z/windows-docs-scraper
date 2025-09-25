typedef struct _CREATE_DISK_GPT {
  GUID  DiskId;
  DWORD MaxPartitionCount;
} CREATE_DISK_GPT, *PCREATE_DISK_GPT;