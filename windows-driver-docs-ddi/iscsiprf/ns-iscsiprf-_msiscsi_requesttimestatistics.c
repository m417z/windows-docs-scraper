typedef struct _MSiSCSI_RequestTimeStatistics {
  WCHAR     iSCSIName[223 + 1];
  USHORT    CID;
  ULONGLONG USID;
  ULONGLONG UniqueAdapterId;
  ULONG     MaximumProcessingTime;
  ULONG     AverageProcessingTime;
} MSiSCSI_RequestTimeStatistics, *PMSiSCSI_RequestTimeStatistics;