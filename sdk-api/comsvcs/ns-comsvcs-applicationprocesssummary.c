typedef struct _ApplicationProcessSummary {
  GUID            PartitionIdPrimaryApplication;
  GUID            ApplicationIdPrimaryApplication;
  GUID            ApplicationInstanceId;
  DWORD           ProcessId;
  COMPLUS_APPTYPE Type;
  LPWSTR          ProcessExeName;
  BOOL            IsService;
  BOOL            IsPaused;
  BOOL            IsRecycled;
} ApplicationProcessSummary;