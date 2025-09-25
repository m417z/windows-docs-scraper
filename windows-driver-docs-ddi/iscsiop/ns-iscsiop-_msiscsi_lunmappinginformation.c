typedef struct _MSiSCSI_LUNMappingInformation {
  ULONGLONG UniqueAdapterId;
  ULONGLONG UniqueSessionId;
  ULONG     OSBus;
  ULONG     OSTarget;
  ULONG     OSLUN;
} MSiSCSI_LUNMappingInformation, *PMSiSCSI_LUNMappingInformation;