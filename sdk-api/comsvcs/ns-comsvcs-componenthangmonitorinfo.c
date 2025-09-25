typedef struct _ComponentHangMonitorInfo {
  BOOL  IsMonitored;
  BOOL  TerminateOnHang;
  ULONG AvgCallThresholdInMs;
} ComponentHangMonitorInfo;