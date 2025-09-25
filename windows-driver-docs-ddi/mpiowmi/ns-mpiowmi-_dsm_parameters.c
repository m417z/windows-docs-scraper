typedef struct _DSM_PARAMETERS {
  WCHAR        DsmName[63 + 1];
  ULONGLONG    DsmContext;
  DSM_VERSION  DsmVersion;
  DSM_COUNTERS DsmCounters;
} DSM_PARAMETERS, *PDSM_PARAMETERS;