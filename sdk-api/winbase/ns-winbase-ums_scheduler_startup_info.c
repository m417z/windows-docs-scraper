typedef struct _UMS_SCHEDULER_STARTUP_INFO {
  ULONG                      UmsVersion;
  PUMS_COMPLETION_LIST       CompletionList;
  PUMS_SCHEDULER_ENTRY_POINT SchedulerProc;
  PVOID                      SchedulerParam;
} UMS_SCHEDULER_STARTUP_INFO, *PUMS_SCHEDULER_STARTUP_INFO;