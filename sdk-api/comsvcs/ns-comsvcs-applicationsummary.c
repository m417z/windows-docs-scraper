typedef struct _ApplicationSummary {
  GUID            ApplicationInstanceId;
  GUID            PartitionId;
  GUID            ApplicationId;
  COMPLUS_APPTYPE Type;
  LPWSTR          ApplicationName;
  ULONG           NumTrackedComponents;
  ULONG           NumComponentInstances;
} ApplicationSummary;