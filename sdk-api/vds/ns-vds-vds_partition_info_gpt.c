typedef struct _VDS_PARTITION_INFO_GPT {
  GUID      partitionType;
  GUID      partitionId;
  ULONGLONG attributes;
  WCHAR     name[36];
} VDS_PARTITION_INFO_GPT;