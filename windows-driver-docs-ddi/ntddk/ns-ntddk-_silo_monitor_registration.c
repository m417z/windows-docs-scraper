typedef struct _SILO_MONITOR_REGISTRATION {
  UCHAR                           Version;
  BOOLEAN                         MonitorHost;
  BOOLEAN                         MonitorExistingSilos;
  UCHAR                           Reserved[5];
  union {
    PUNICODE_STRING DriverObjectName;
    PUNICODE_STRING ComponentName;
  };
  SILO_MONITOR_CREATE_CALLBACK    CreateCallback;
  SILO_MONITOR_TERMINATE_CALLBACK TerminateCallback;
} SILO_MONITOR_REGISTRATION, *PSILO_MONITOR_REGISTRATION;