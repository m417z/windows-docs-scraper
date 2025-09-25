typedef struct _DXGKARG_SETCONTEXTSCHEDULINGPROPERTIES {
  HANDLE                        hContext;
  DXGK_SCHEDULING_PRIORITY_BAND priorityBand;
  INT                           realtimeBandPriorityLevel;
  INT                           inProcessPriority;
  UINT64                        quantum;
  UINT64                        gracePeriodSamePriority;
  UINT64                        gracePeriodLowerPriority;
} DXGKARG_SETCONTEXTSCHEDULINGPROPERTIES;