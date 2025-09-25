typedef struct _CLUS_CHKDSK_INFO {
  DWORD     PartitionNumber;
  DWORD     ChkdskState;
  DWORD     FileIdCount;
  ULONGLONG FileIdList[1];
} CLUS_CHKDSK_INFO, *PCLUS_CHKDSK_INFO;