typedef struct tagKSCAMERA_EXTENDEDPROP_VIDEOPROCSETTING {
  ULONG                       Mode;
  LONG                        Min;
  LONG                        Max;
  LONG                        Step;
  KSCAMERA_EXTENDEDPROP_VALUE VideoProc;
  ULONGLONG                   Reserved;
} KSCAMERA_EXTENDEDPROP_VIDEOPROCSETTING, *PKSCAMERA_EXTENDEDPROP_VIDEOPROCSETTING;