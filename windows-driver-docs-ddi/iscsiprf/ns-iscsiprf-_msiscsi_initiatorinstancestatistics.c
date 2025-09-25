typedef struct _MSiSCSI_InitiatorInstanceStatistics {
  ULONGLONG UniqueAdapterId;
  ULONG     SessionDigestErrorCount;
  ULONG     SessionConnectionTimeoutErrorCount;
  ULONG     SessionFormatErrorCount;
  ULONG     SessionFailureCount;
} MSiSCSI_InitiatorInstanceStatistics, *PMSiSCSI_InitiatorInstanceStatistics;