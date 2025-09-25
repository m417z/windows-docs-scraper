typedef struct _JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION {
  DWORD64                                   IoReadBytesLimit;
  DWORD64                                   IoWriteBytesLimit;
  LARGE_INTEGER                             PerJobUserTimeLimit;
  DWORD64                                   JobMemoryLimit;
  JOBOBJECT_RATE_CONTROL_TOLERANCE          RateControlTolerance;
  JOBOBJECT_RATE_CONTROL_TOLERANCE_INTERVAL RateControlToleranceInterval;
  DWORD                                     LimitFlags;
} JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION, *PJOBOBJECT_NOTIFICATION_LIMIT_INFORMATION;