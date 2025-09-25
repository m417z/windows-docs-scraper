typedef struct CLUS_PARTITION_INFO_EX2 {
  GUID  GptPartitionId;
  WCHAR szPartitionName[MAX_PATH];
  DWORD EncryptionFlags;
} CLUS_PARTITION_INFO_EX2, *PCLUS_PARTITION_INFO_EX2;