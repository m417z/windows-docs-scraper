typedef struct MONITOR_STATE {
  LARGE_INTEGER          LastUpdate;
  RESOURCE_MONITOR_STATE State;
  HANDLE                 ActiveResource;
  BOOL                   ResmonStop;
} MONITOR_STATE, *PMONITOR_STATE;