typedef struct _ISCSI_LUNList {
  ULONGLONG TargetLUN;
  ULONG     OSLUN;
  ULONG     Reserved;
} ISCSI_LUNList, *PISCSI_LUNList;