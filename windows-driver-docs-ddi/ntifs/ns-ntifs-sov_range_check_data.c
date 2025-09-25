typedef struct _SOV_RANGE_CHECK_DATA {
  BOOLEAN   RemoveZone;
  ULONGLONG InRange[2];
  GUID      ZidForRemoval;
  ULONGLONG Reserved1;
  ULONGLONG Reserved2;
} SOV_RANGE_CHECK_DATA, *PSOV_RANGE_CHECK_DATA;