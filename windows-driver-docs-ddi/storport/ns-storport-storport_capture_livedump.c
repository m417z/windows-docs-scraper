typedef struct _STORPORT_CAPTURE_LIVEDUMP {
  ULONG                          Version;
  ULONG                          Size;
  STORPORT_CAPTURE_LIVEDUMP_TYPE LiveDumpType;
  STORPORT_LIVEDUMP_ISSUE_TYPE   IssueType;
  PWSTR                          ComponentName;
  STORPORT_LIVEDUMP_DATA_TYPE    DataType;
  PVOID                          Data;
} STORPORT_CAPTURE_LIVEDUMP, *PSTORPORT_CAPTURE_LIVEDUMP;