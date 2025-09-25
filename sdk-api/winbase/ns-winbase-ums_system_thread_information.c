typedef struct _UMS_SYSTEM_THREAD_INFORMATION {
  ULONG UmsVersion;
  union {
    struct {
      ULONG IsUmsSchedulerThread : 1;
      ULONG IsUmsWorkerThread : 1;
    } DUMMYSTRUCTNAME;
    ULONG ThreadUmsFlags;
  } DUMMYUNIONNAME;
} UMS_SYSTEM_THREAD_INFORMATION, *PUMS_SYSTEM_THREAD_INFORMATION;