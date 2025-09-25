typedef struct _ApplicationProcessRecycleInfo {
  BOOL     IsRecyclable;
  BOOL     IsRecycled;
  FILETIME TimeRecycled;
  FILETIME TimeToTerminate;
  long     RecycleReasonCode;
  BOOL     IsPendingRecycle;
  BOOL     HasAutomaticLifetimeRecycling;
  FILETIME TimeForAutomaticRecycling;
  ULONG    MemoryLimitInKB;
  ULONG    MemoryUsageInKBLastCheck;
  ULONG    ActivationLimit;
  ULONG    NumActivationsLastReported;
  ULONG    CallLimit;
  ULONG    NumCallsLastReported;
} ApplicationProcessRecycleInfo;