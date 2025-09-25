typedef struct _ComponentSummary {
  GUID   ApplicationInstanceId;
  GUID   PartitionId;
  GUID   ApplicationId;
  CLSID  Clsid;
  LPWSTR ClassName;
  LPWSTR ApplicationName;
} ComponentSummary;